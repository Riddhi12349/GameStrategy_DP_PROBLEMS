class Solution {
public:
    int dp[502][502];
  // run for case -- [2,1,9 ||,2,|8,3] || = more balanced (diff = 0)
  // (|) - this partition gives more ans
    int find(vector<int>& a , int st , int end){
        
        if(st >= end){
            return 0;
        }

        if(dp[st][end]!= -1){
            return dp[st][end];
        }

        int tot = 0;
        for(int i = st ; i <= end ; i++){
            tot += a[i];
        }
        
        int ans = 0 , left_sum = 0;

        for(int k = st ; k < end ; k++){

             left_sum += a[k];
            int right_sum = tot-left_sum;

        if(left_sum < right_sum){
           ans = max(ans , left_sum + find(a , st , k));
        }
        else if (right_sum < left_sum){
            ans = max(ans , right_sum + find(a , k +1 , end));
        }
        else{
         ans = max(ans , left_sum + max(find(a,st,k) , find(a,k+1,end)));
        }
    }
         return dp[st][end] = ans;
    }
    int stoneGameV(vector<int>& a) {
        
        int n = a.size();
        memset(dp , -1 , sizeof(dp));
      return  find(a , 0 , n-1);
    }
};
