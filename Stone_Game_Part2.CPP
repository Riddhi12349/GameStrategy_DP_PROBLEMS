class Solution {
public:
    
    int dp[102][102][2];

    int find(vector<int>& piles , int i , int M , int person){
    
    int n = piles.size();
    if(i >= n){
        return 0;
    }
    
    if(dp[i][M][person]!= -1){
        return dp[i][M][person];
    }

   int result =  (person == 1) ? -1 : INT_MAX;
   int stones = 0;

    for(int x = 1 ; x <= min(2*M , n-i) ; x++){
           
    if(person == 1){

    stones += piles[i+x-1];
    result = max(result , stones+find(piles , i+x , max(M,x) , 0));
    }
    
    else if(person == 0){ 
    result = min(result , find(piles , i+x, max(M,x) , 1));
    }

    }
       return dp[i][M][person] = result;
    }

    int stoneGameII(vector<int>& piles) {
      
      memset(dp , -1 , sizeof(dp));

      int alice_score = find(piles , 0 , 1 , 1);
      return alice_score;

    }
};
