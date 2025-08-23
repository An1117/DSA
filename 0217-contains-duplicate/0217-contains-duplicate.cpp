class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> freqcheck;

        for(int i = 0; i < n; i++){
            if(freqcheck.find(nums[i]) != freqcheck.end()){
                return true;
            }
            freqcheck.insert(nums[i]);
        }
        return false;
    }
};