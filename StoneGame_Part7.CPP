class Solution {
public:
        // diff in their scores can be written as
       a1 - (b1 - (a2 - b2))

    int dp[1002][1002];

    int find(vector<int>& a , int tot , int i , int j){
        
      if(i >= j){
          return 0;
      }

     if(dp[i][j] != -1)  return dp[i][j];

      // if alice picks ith element
      int s1 = (tot-a[i])-find(a , tot-a[i] , i+1 , j);
      
      // if alice picks jth element
      int s2 = (tot-a[j])-find(a , tot-a[j] , i , j-1);

      return dp[i][j] = max(s1 , s2);
    }
 
    int stoneGameVII(vector<int>& stones) {
        
        int tot = 0;
        for(int i = 0 ; i < stones.size() ; i++)
                tot += stones[i];

        memset(dp , -1 , sizeof(dp));
      return  find(stones , tot , 0 , stones.size()-1);
    
    }
};
