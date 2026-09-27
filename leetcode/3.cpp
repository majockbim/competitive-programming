class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // in this case, our window is a set
        unordered_set<char> window = {};
        size_t left = 0;
        size_t ans = 0;

        for (size_t right{}; right < s.size(); right++) {
            while (window.contains(s[right])) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

/*
runtime
    time: 301ms
    beats: 25.41%
memory
    amt: 81.48MB
    beats: 15.67%
*/
