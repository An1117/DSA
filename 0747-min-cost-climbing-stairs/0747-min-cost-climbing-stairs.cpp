class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
//         //bottom up approach:
//         int n = cost.size();
//         vector<int> dp(n + 1);
// //dp[0] and dp[1] default to 0 (since you can start at 0 or 1 without paying).

//         for (i = 2; i <= n; i++ ) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[n];
//         //example:
//         // dp[0] = 0
//         // dp[1] = 0

//         // dp[2] = min(dp[1] + cost[1], dp[0] + cost[0])
//         // → dp[2] = min(0 + 15, 0 + 10) = 10

//This version modifies the cost array directly to avoid using extra space for a separate dp array.
            for (int i = cost.size() - 3; i >= 0; i--){
                cost[i] += min(cost[i + 1], cost[i + 2]);
            }
            return min(cost[0], cost[1]);

            // example:
            // Start from index = 0 or 1, want to reach index 3 (top).
            // Let’s modify the array from back:
            // At i = 0:
            // cost[0] += min(cost[1], cost[2])
            // cost[0] = 10 + min(15, 20) = 10 + 15 = 25
            // At this point, cost = {25, 15, 20}
            // Now return min(cost[0], cost[1]) = min(25, 15) = 15
            // → Start at index 1, pay 15, go directly to top (step 3)
    }
};
