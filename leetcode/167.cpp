class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if ((numbers[right] + numbers[left]) < target) {
                left++;
            } else if ((numbers[right] + numbers[left]) > target) {
                right--;
            } else {
                return {left + 1, right + 1};
            }
        }

        return {};
    }

};


/*
runtime
    time: 0ms
    beats: 100%
memory
    amt: 19.58MB
    beats: 33.06%
*/
