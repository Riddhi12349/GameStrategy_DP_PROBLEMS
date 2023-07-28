class Solution {
public:
/*
  player1                  Player2              Player1
  (i,j) ----------i------->(i+1 , j)---(i+1)--->(i+2 , j)
      |                             |----j---->(i+1 ,j-1)  
      |                 
      |-----------j------->(i , j-1)-----i---->(i+1 ,j-1)
                                    |----(j-1)->(i, j-2)
    */
    int f(vector<int>& a , int i , int j){
      
      if(i > j ){
        return 0;
      }
      if(i == j){
        return a[i];
      }
      int a1 = a[i] + min(f(a,i+2,j) , f(a,i+1,j-1));
      int a2 = a[j] + min(f(a,i+1,j-1) , f(a,i,j-2));

      return max(a1 , a2);
    }

    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        int s1 = f(nums , 0 , n-1);
  
        int s = 0;
        for(int i = 0 ; i < n ; i++){
          s += nums[i];
        }
       int s2 = s-s1;

        if(s1 >= s2) return true;
        return false;
    }
};
