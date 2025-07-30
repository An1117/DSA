class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int xorr = n;

        // for(int i =0; i < n; i++){
        //     xorr ^= (i ^ nums[i]);
        // }
        // return xorr;

        //MATHS BIT:

        int res = nums.size();

        for(int i = 0; i < n; i++){
            res += i - nums[i];
        }
        return res;
    }
};

