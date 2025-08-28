class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //making 2d dp with infinity vals.
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));

        //this is the helper escape hatch: (base case)
        dp[m-1][n] = 0;
        //after this, the new structure of the dp is as follows:
        // [∞, ∞, ∞, ∞]
        // [∞, ∞, ∞, ∞]
        // [∞, ∞, ∞, 0]
        // [∞, ∞, ∞, ∞]

        for(int i = m -1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};