class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> quad;
        kSum(nums, target, 0, 4, quad, res);
        return res;
    }

private:
    void kSum(vector<int> nums, long long target, int start, int k, vector<int> quad, vector<vector<int>>& res){

        int n = nums.size();

        //Early Termination
        //edge cases where, the first element is too big, or the last element is too small to even reach the target, then we will avoid that recursion step all toegther and save redundant processing.


        if(start == n) return; //only has one element
        long long avg = target / k;
        if(nums[start] > avg || nums[n - 1] < avg){
            return;
        }


        // Base Case: 2Sum
        if(k == 2){
            int l = start, r = n-1;
            while(l < r){
                long long sum = nums[l] + nums[r];
                if(sum < target) l++;
                else if(sum > target) r--;
                else {
                    res.push_back(quad);
                    res.back().push_back(nums[l]);
                    res.back().push_back(nums[r]);
                    l++;
                    while(l < r && nums[l] == nums[l - 1]) l++; //skip duplicate.
                }
            }
            return;
        }

    //Recursive case: reduce ksum to (k - 1)sum
    for(int i = start; i < n - k + 1; ++i){
        if(i > start && nums[i] == nums[i - 1]) continue;
        quad.push_back(nums[i]);
        kSum(nums, target - nums[i], i + 1, k - 1, quad, res);
        quad.pop_back();//Backtrack
    }
    }
};