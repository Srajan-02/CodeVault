class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {0};
        int windowCount[51] = {0};
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Add element to window
            freq[nums[right]]++;
            // If window becomes bigger than k
            if (right - left + 1 > k) {
                freq[nums[left]]--;
                left++;
            }
            // Window has exactly k elements
            if (right - left + 1 == k) {
                // Count each distinct element in this window once
                for (int x = 0; x <= 50; x++) {
                    if (freq[x] > 0) {
                        windowCount[x]++;
                    }
                }
            }
        }
        int ans = -1;
        // Find largest element appearing in exactly one window
        for (int x = 0; x <= 50; x++) {
            if (windowCount[x] == 1) {
                ans = x;
            }
        }
        return ans;
    }
};