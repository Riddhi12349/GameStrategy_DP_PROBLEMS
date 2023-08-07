class Solution {
public:
    
    int dp[50002][2];

    int find(vector<int>& stoneValue , int i , int person){
        
        int n = stoneValue.size();
        if(i >= n){
            return 0;
        }
        
        if(dp[i][person] != -1){
            return dp[i][person];
        }
        int result =  (person == 1) ? INT_MIN : INT_MAX  ; 
        int stones = 0;

        for(int j = i ; j <= min(i+2 , n-1) ; j++){
         
            if(person == 1){
            stones += stoneValue[j];
            result = max(result , stones + find(stoneValue , j+1 ,0));
            }
            else if(person == 0){
             result = min(result , find(stoneValue , j+1 , 1));
            }
        }

        return dp[i][person] = result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp , -1, sizeof(dp));

        int alice_score = find(stoneValue , 0 , 1);
        int tot_score = 0;
        for(int i = 0 ; i < stoneValue.size() ; i++){
            tot_score += stoneValue[i];
        }
        int bob_score = tot_score-alice_score;
        string ans= "";
        ans = (alice_score > bob_score)?"Alice":"Bob";
        if(alice_score == bob_score){ ans ="Tie";}
        return ans;
    }

};
