class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> columns[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];

                if (val == '.') {
                    continue;
                }

                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].contains(val) || columns[c].contains(val) || boxes[boxIndex].contains(val)) {
                    return false;
                } else {
                    rows[r].insert(val);
                    columns[c].insert(val);
                    boxes[boxIndex].insert(val);
                }
            }
        }

        return true;
    }
};

/*
runtime
    time: 1ms
    beats: 60.29%
memory
    amt: 25.66MB
    beats: 17.71%
*/
