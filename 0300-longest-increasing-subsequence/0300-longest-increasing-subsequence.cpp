class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(), 1);

        for(int i = nums.size(); i >= 0; i--){
            for(int j = (i + 1); j < nums.size(); j++){
                if(nums[i] < nums[j]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
        
    }
};