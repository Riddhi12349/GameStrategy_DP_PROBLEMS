class Solution {
public:

   int dp[502][502];

    int find(vector<int>& piles ,int i , int j){
       
        if(i >j){
             return 0;
         }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int a1 = piles[i] + min(find(piles , i+2 , j),
        find(piles , i+1 , j-1));

        int a2 = piles[j] + min(find(piles, i+1 , j-1)  , 
        find(piles , i, j-2));

        return dp[i][j] =  max(a1 , a2);
    }
    bool stoneGame(vector<int>& piles) {
        
        memset(dp , -1 , sizeof(dp));

        int alice_score  = find(piles , 0 , piles.size()-1);
        int tot_score = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            tot_score += piles[i];
        }
        int bob_score = tot_score - alice_score;
        return alice_score >= bob_score;
    }
};
