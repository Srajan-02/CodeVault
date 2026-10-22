class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                pos = i;
                break;
            }
        }

        int ans = INT_MAX;

        // Case 1: Check normal order
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos + i) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, min(pos, n - pos + 2));
        }

        // Case 2: Check reversed order
        ok = true;
        for (int i = 0; i < n; i++) {
            if (nums[(pos - i + n) % n] != i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int k = (n - 1 - pos + n) % n;
            ans = min(ans, 1 + min(k, n - k));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};