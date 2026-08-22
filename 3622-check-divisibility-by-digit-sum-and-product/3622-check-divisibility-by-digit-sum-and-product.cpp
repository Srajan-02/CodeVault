class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int x = 0;
        int y = 1;
        while (n > 0) {
            int digit = n%10;
            x = x+digit;
            y = y*digit;
            n /= 10;
        }
        return original % (x+y) == 0;
    }
};