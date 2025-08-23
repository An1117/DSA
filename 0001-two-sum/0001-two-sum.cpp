class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> list;

        for(int i = 0 ; i < n; i++){
            int diff = target - nums[i];
            if(list.find(diff) != list.end()){
                return {list[diff], i};
            }
            list.insert({nums[i], i});
        }
    return {};
    }
};