#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    /**
     * Identifies the shortest subarray that needs sorting to make the whole array sorted.
     * Uses a two-pointer approach within a single loop for O(n) time and O(1) space.
     */
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // start: Leftmost index that is out of place
        // end: Rightmost index that is out of place
        int start = -1; 
        int end = -2; // Initialized so if sorted, length (end-start+1) = 0
        
        int currentMax = INT_MIN;
        int currentMin = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            // --- FORWARD PASS (Finding the End) ---
            currentMax = max(currentMax, nums[i]);
            if (nums[i] < currentMax) {
                end = i; // Last 'dip' found moving forward
            }
            
            // --- BACKWARD PASS (Finding the Start) ---
            int j = n - 1 - i; // Index moving from right to left
            currentMin = min(currentMin, nums[j]);
            if (nums[j] > currentMin) {
                start = j; // Last 'peak' found moving backward (Leftmost violation)
            }
        }
        
        // If the array is already sorted, start will stay -1 and end -2.
        // Result: -2 - (-1) + 1 = 0.
        int result = end - start + 1;
        return (result < 0) ? 0 : result;
    }
};

int main() {
    Solution solver;
    
    // Test Case: [2, 6, 4, 8, 10, 9, 15]
    vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    int length = solver.findUnsortedSubarray(nums);
    
    cout << "Shortest Unsorted Subarray Length: " << length << endl;
    
    return 0;
}