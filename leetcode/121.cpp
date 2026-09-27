class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int profit = 0;

        for (size_t right{}; right < prices.size(); right++) {
            if (prices[right] > prices[left]) {
                profit = max(profit, prices[right] - prices[left]);
            } else if (prices[right] < prices[left]) {
                left = right;
            }

        }

        return profit;
    }
};

/*
runtime
    time: 4ms
    beats: 17.87%
memory
    amt: 97.41MB
    beats: 26.33%
*/
