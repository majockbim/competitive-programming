/* INITIAL APPROACH O(nlogn) time because std::sort
 * Problem description requires O(n) time

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        if (nums.size() == 1) {
            return 1;
        }

        sort(nums.begin(), nums.end());

        auto last = unique(nums.begin(), nums.end());
        nums.erase(last, nums.end());

        int count = 1;
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if ((nums[i + 1] - nums[i]) == 1) {
                count++;
            } else {
                count = 1;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};


runtime
    time: 18ms
    beats: 86.32%
memory
    amt: 60.23MB
    beats: 85.87%
*/

// Optimized approach O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (!numSet.contains(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.contains(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

/*
runtime
    time: 85ms
    beats: 40.28%
memory
    amt: 88.86MB
    beats: 68.26%
*/
