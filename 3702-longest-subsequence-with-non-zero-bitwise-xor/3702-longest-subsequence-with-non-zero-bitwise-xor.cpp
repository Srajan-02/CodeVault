class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int resultXor = 0;
        bool allZero = true;
        for (int &x : nums) {
            resultXor ^= x;
            if (x != 0) {
                // We found at least one non-zero element.
                allZero = false;
            }
        }
        if (allZero) {
            // We can't take any subsequence with non-zero XOR.
            return 0;
        }
        return (resultXor == 0) ? n - 1 : n;
    }
};