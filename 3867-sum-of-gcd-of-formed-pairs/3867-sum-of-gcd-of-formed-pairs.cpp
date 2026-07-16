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
        vector<long long>ans;
        while(left<right){
            ans.push_back(gcd(prefixGcd[left],prefixGcd[right]));
            left++;
            right--;
        }
        return accumulate(ans.begin(),ans.end(),0LL);
    }
};