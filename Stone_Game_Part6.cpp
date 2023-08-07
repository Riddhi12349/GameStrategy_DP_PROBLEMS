class Solution {
public:

    // We would THINK of the question as GAIN TO US AND LOSS TO OTHER
    // Alice strategy would be to pick the maximum element of BOB..
    // Such that her score and BOB score values sum would be maximum..


    
    int stoneGameVI(vector<int>& a_val, vector<int>& b_val) {

        int n = a_val.size();

        vector<vector<int>> v1(n);
        for(int i = 0 ; i < n ; i++){
            v1[i] = {a_val[i] + b_val[i] , a_val[i] , b_val[i]};
        }
           
        sort(v1.begin() , v1.end() , greater<vector<int>>());

        int a = 0 , b = 0;
        for(int i = 0 ; i < v1.size() ; i++){
            if(i % 2 == 0){
                a += v1[i][1];
            }
            else{
                b += v1[i][2];
            }
        }

        if(a == b){
            return 0;
        }
        else if(a > b){
            return 1;
        }
        else{
            return -1;
        }
    }
};
