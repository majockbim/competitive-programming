class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double window = 0;
        double ans = numeric_limits<double>::lowest();

        for (size_t right{}; right < nums.size(); right++) {
            int firstCompleteWindow = k - 1;
            window += nums[right];

            if (right >= k) {
                window -= nums[right - k];
            }

            if (right >= firstCompleteWindow) ans = max(ans, window); 

        }

        return ans / k;
    }
};

/*
runtime
    time: 0ms
    beats: 100.00%
memory
    amt: 113.90MB
    beats: 27.09%
*/
