class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequencies
        unordered_map<int, int> f;
        for (auto& num : nums) {
            f[num]++;
        }

        // buckets, index is frequency
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto const& [key, value] : f) {
            buckets[value].push_back(key);
        }

        // gather top k items
        vector<int> ans;
        ans.reserve(k);
        for (int i = buckets.size() - 1; i > 0; --i) {
            for (int n : buckets[i]) {
                ans.push_back(n);
                if (ans.size() == k) return ans;
            }
        }

        return {};
    }
};

/*
runtime
    time: 0ms
    beats: 100.00%
memory
    amt: 19.78MB
    beats: 20.62%
*/
