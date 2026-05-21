class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix
        int left_product = 1;
        for (int i = 0; i < n; ++i) {
            ans[i] = left_product;
            left_product *= nums[i];
        }

        // suffix
        int right_product = 1;
        for (int i = n-1; i >= 0; --i) {
            ans[i] *= right_product;
            right_product *= nums[i];
        }

        return ans;
    }
};

/*
runtime
    time: 21ms
    beats: 5.15%
memory
    amt: 40.04MB
    beats: 95.02%
*/
