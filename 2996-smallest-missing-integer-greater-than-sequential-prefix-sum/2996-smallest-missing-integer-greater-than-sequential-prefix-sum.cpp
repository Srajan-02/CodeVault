class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        // sum of sequential prefix
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }
        // smallest number >= sum that is not present in nums
        unordered_set<int> st(nums.begin(), nums.end());
        while (st.count(sum)) {
            sum++;
        }
        return sum;
    }
};