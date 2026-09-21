class Solution {
public:
    bool isValid(string s) {
        // 1. Loop through & add opening to stack
        // 2. If ending, check if in stack
        // 3. If in stack, pop, if not, false

        stack<char> brackets;

        for (size_t i{}; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                brackets.push(s[i]);
            } else {
                if (brackets.empty()) {
                    return false;
                }

                char top = brackets.top();
                if (s[i] == ')' && top == '('||
                    s[i] == '}' && top == '{' ||
                    s[i] == ']' && top == '[') {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }
};

/*
runtime
    time: 3ms
    beats: 9.30%
memory
    amt: 8.87MB
    beats: 66.84%
*/
