class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp((n + 1), false);
        dp[n] = true;

        for(int i = n; i > -1; i-- ){
            for(const auto& w: wordDict){
                if((i + w.size()) <= n && s.substr(i, w.size()) == w){
                    dp[i] = dp [ i + w.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};