// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         vector<int>gcdpairs;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 gcdpairs.push_back(gcd(nums[i],nums[j]));
//             }
//         }
//         sort(gcdpairs.begin(),gcdpairs.end());
//         vector<int>ans;
//         for(int i=0;i<queries.size();i++){
//             ans.push_back(gcdpairs[queries[i]]);
//         }
//         return ans;  
//     }
// };

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        // store frequency of each value
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exactPairs[g] = number of pairs with gcd exactly g
        vector<long long> exactPairs(mx + 1, 0);

        // Count pairs for each gcd
        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;
            // Count numbers divisible by g
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];
            // Total pairs divisible by g
            exactPairs[g] = cnt * (cnt - 1) / 2;
            // Remove pairs already counted for larger gcds
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                exactPairs[g] -= exactPairs[multiple];
        }

        // Prefix sums of pair counts
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exactPairs[g];
        // Answer queries
        vector<int> ans;
        for (long long q : queries) {
            // q is 0-indexed, convert to 1-indexed rank
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }
        return ans;
    }
};