class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //sorting algo: tc = O(n(logn))

        // sort(nums.begin(), nums.end());
        // int n = nums.size();

        // for(int i = 1; i <  n ; i+=2/*bcs only two duplicstes for a number*/) {
        //     if(nums[i] != nums[i - 1]){
        //         return nums[i - 1];
        //     }
            
        // }
        // return nums[n-1]; //if no unique number found in the loop

        //bit manipulation
        int result = 0;
        for(int num : nums) {
            result ^= num;
        }
        return result;
    }
};