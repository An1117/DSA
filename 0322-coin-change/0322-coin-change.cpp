class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin) { // ensures that the current coin can be used to make up amount i.
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                    //1 + dp[i - coin]:
                    // 1 represents using this coin.
                    // dp[i - coin] represents the minimum number of coins needed to make (i - coin) amount.
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];//If dp[amount] is unchanged, return -1 (not possible).
    }
};