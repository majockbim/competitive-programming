class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // determine sorted half
            if (nums[left] <= nums[mid]) {
                // left half sorted
                if (nums[left] <= target && target < nums[mid]) {
                    mid--;
                    right = mid;
                } else { 
                    mid++;
                    left = mid;
                }
            } else { // right half sorted
                if (nums[mid] <= target && target <= nums[right]) {
                    mid ++;
                    left = mid;
                } else {
                    mid --;
                    right = mid;
                }
            }
        }
        
        return -1;
    }
};


