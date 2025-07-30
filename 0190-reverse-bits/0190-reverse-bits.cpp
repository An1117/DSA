class Solution {
public:
    int reverseBits(int n) {
        uint32_t res = 0;

        for(int i = 0; i < 32; i++) {
            uint32_t bit = (n >> i) & 1;
            res += (bit << (31 - i));
        }
        return res;
    }
};