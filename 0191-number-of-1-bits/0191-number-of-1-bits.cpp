class Solution {
public:
    int hammingWeight(int n) {
        int res = 0;

        while(n != 0){
            //modulo 2 , O(32);
            res += n % 2;
            n = n >> 1;
        }
        return res;
    }
};