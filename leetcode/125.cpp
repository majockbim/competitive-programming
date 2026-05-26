class Solution {
public:
    bool isPalindrome(string s) {
        s = strip(s);

        int j = s.length() - 1;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != s[j]) {
                return false;
            }

            j--;
        }

        return true;
    }

    string strip(const string& input) {
        string result;

        for (unsigned char c : input) {
            if (std::isalnum(c)) {
            result.push_back(std::tolower(c));
            }
        }

        return result;
    }
};

/*
runtime
    time: 4ms
    beats: 15.05%
memory
    amt: 10.20MB
    beats: 23.47%
*/
