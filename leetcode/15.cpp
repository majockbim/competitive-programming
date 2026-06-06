class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // a + b + c = 0, a != b, a != c, b != c
        // $\hookrightarrow$ b + c = -a $\leftarrow$ like Two Sum
        vector<vector<int>> res = {};
        sort(nums.begin(), nums.end());

        int target{};
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            target = -nums[i];

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                if (nums[left] + nums[right] < target) {
                    left++;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    res.push_back({nums[i], nums[left], nums[right]});

                    right--;
                    int temp_left = left;
                    while (left < right) {
                        if (nums[temp_left] == nums[left]) {
                            left++;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};

/*
runtime
    time: 50ms
    beats: 47.19%
memory
    amt: 29.08MB
    beats: 72.10%
*/
