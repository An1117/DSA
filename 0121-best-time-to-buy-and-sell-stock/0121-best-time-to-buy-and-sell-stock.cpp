class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 0; //l = buy, r = sell : therefore r > l
        int maxP = 0;

        while(r < n){
            if(prices[l] < prices[r]){
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            }else{
                l = r;
            }
            r += 1;
        }
        return maxP;
    }
};