class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // APPROACH-01(BRUTE FORCE) -> TLE

        // unordered_set<int> uniqueOutputs;
        // int n = nums.size();
        // // Iterating through all possible triplet index combinations
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         for (int k = 0; k < n; ++k) {
        //             int xorSum = nums[i] ^ nums[j] ^ nums[k];
        //             uniqueOutputs.insert(xorSum);
        //         }
        //     }
        // }
        // // return the size of set i.e count
        // return uniqueOutputs.size();

        // APPROACH-2(DOING XOR OF 2 ELEMENTS IN N^2 AND THEN THIRD ELEMENT WITH THE pairXOR vector)

        unordered_set<int> pairXor;
        unordered_set<int> ans;
        int n = nums.size();
        // Store all XORs of two elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pairXor.insert(nums[i] ^ nums[j]);
            }
        }
        // XOR each pair result with every element
        for (int x : pairXor) {
            for (int num : nums) {
                ans.insert(x ^ num);
            }
        }
        return ans.size();
    }
};