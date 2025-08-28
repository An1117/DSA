class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            if((i > 0) && (nums[i] == nums[i - 1])){
                continue;
            }

            int l = i + 1;
            int r  = n - 1;
            
            while(l < r){
                int total = nums[i] + nums[l] + nums[r];
                if(total > 0){
                    r--;
                }else if(total < 0){
                    l++;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;

                    while(nums[l] == nums[l - 1] && l < r){
                        l++;
                    }
                }
            }
        }
        return res;

    }
};