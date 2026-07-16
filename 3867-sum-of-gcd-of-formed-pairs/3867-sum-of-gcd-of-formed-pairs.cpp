class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixGcd;
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int left = 0;
        int right = prefixGcd.size()-1;
        long long sum=0;
        while (left < right) {
            sum += gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};