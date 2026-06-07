class Solution {
public:
    int maxArea(vector<int>& height) {
        // $A = L \cdot W$
        // $\hookrightarrow = (right - left) \cdot min(height[right], height[left])$

        int A = 0, left = 0;
        int right = height.size() - 1;
            
        while (left < right) {
            int curr_A = (right - left) * min(height[right], height[left]);
            if (A < curr_A) A = curr_A;

            if (height[right] < height[left]) {
                right--;
            } else {
                left++;
            }
        }

        return A;
    }
};

/*
runtime
    time: 0ms
    beats: 100.00%
memory
    amt: 62.89MB
    beats: 77.80%
*/
