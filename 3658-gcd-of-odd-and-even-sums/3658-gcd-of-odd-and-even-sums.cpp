class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = 0;
        int evensum = 0;
        // Sum of first n odd numbers
        for (int i = 1; i <= n; i++) {
            oddsum += 2 * i - 1;
        }
        // Sum of first n even numbers
        for (int i = 1; i <= n; i++) {
            evensum += 2 * i;
        }
        return gcd(oddsum, evensum);
    }
};