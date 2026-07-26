class Solution {
public:
    long long largestInteger(int n, int s) {
        if (s > 9 * n)
            return -1;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int digit = min(9, s);
            ans = ans * 10 + digit;
            s -= digit;
        }
        return ans;
    }
};