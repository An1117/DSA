class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_set<char> charSet;//to chceck for duplicates.
       int l = 0, res = 0;

       for (int r = 0; r<s.size(); r++){
            while (charSet.find(s[r]) != charSet.end()) {//If charSet.find(s[r]) is not equal to charSet.end(), it means that s[r] was found in the set.
                 charSet.erase(s[l]);
                 l++;
            }
            charSet.insert(s[r]);
            res = max (res, r - l + 1);
       }
       return res;
    }
};
