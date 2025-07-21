class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1, currMax = 1;

        for (int n : nums ){
            int temp = currMax * n;
            currMax = max(max(currMax * n, currMin * n), n);
            currMin = min(min(temp, currMin * n), n);
            res = max(res, currMax);
        }
        return res;
        
    }
};