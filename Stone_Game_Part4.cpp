class Solution {
public:
    int dp[100002][2];

    bool find(int n , int person){
      
      if(n == 1){
          return person;
      }
      if(n == 0){
          return !person;
      }
      
      if(dp[n][person] != -1){
          return dp[n][person];
      }

        bool ans1 = 0 , ans2 =  1;
        for(int x = 1 ; x*x <= n ; x++){
           if(person == 1){
            bool p = find(n - x*x , 0);
            ans1 = (ans1|p);
           }
           else{
             bool p = find(n-x*x , 1);
             ans2 = (ans2 & p);
           }
        }
        return dp[n][person] = person == 1 ? ans1 : ans2 ;
    }
    bool winnerSquareGame(int n) {
        
        memset(dp , -1 , sizeof(dp));
        return find(n , 1);
    }
};
