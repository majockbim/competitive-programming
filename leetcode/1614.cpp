class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int close = 0;
        int ans = 0;

        for (size_t i{}; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                open--;
            }

            ans = max(ans, open);
        }

        return ans;
    }
};

/*
runtime
    time: 0ms
    beats: 100.00%
memory
    amt: 8.44MB
    beats: 24.11%
*/
