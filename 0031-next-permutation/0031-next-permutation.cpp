class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        // approach-01
        // next_permutation(nums.begin(), nums.end());
        // for (int it : nums) {
        //     cout << it << " ";
        // }
        //approach-02
        int index = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i; //store the break point from where we can start making the next permutation
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        else{
            // find the least element from the right side of the breakpoint to replace the left side inorder to get next permutation
            for(int i=nums.size()-1;i>index;i--){
                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            }
            // now add the remaining values as they are already in a order
            reverse(nums.begin()+index+1,nums.end());
        }
        return;
    }
};