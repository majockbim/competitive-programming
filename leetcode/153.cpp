class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                mid++;
                left = mid;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};

/*
runtime
    time: 0ms
    beats: 100.00%
memory
    amt: 14.04MB
    beats: 79.63%
*/
