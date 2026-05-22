#include <cstring>

class Solution {
public:

    string encode(vector<string>& strs) {
        // "contains any .. 256 ASCII characters" -> use non-ASCII "¡"
        // ¡ is 2 bytes
        // emojis are 4 bytes
        // ascii are 1 byte
        string encoded = "";

        // separate strings by non-ASCII character
        for (int i = 0; i < strs.size(); ++i) {
            encoded += strs[i] + "¡";
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        string curr = "";
        for (int i = 0; i < s.length(); ++i) {
            if (strncmp(&s[i], "¡", 2) == 0) {
                decoded.push_back(curr);
                curr = "";
                ++i; // skip 2nd byte of ¡
                continue;
            }
            curr += s[i];
        }

        return decoded;
    }
};

/*
runtime
    time: 6ms
    beats: 96.81%
memory
    amt: 108.4MB
    beats: 99.60%
*/
