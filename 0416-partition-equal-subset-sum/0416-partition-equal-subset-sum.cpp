class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (sum(nums) % 2 != 0){
            return false;
        }

        int target = sum(nums)/2;
        vector<int> dp (target + 1, false);
        vector<int> nextDP (target + 1, false);
        dp[0]= true;

        for(int i = 0; i < nums.size(); i++){
            for(int j = 1 ; j <= target; j++){
                if(j >= nums[i]){
                    nextDP[j] = dp[j] || dp[j - nums[i]];
                }else{
                    nextDP[j] = dp[j];
                }
            }
            swap(dp, nextDP);
        }
        return dp[target];
        
    }
private:
    int sum(vector<int>& nums){
        int total = 0;
        for(int num : nums) {
            total += num;
        }
        return total;
    }
};