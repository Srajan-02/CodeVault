/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>>res;
//     void solve(TreeNode *root, int sum, vector<int>temp, int &targetSum){
//         if(!root){
//             return;
//         }
//         sum+=root->val;
//         temp.push_back(root->val);
//         //check for leaf node
//         if(root->left==NULL && root->right==NULL){
//             if(sum==targetSum){
//                 res.push_back(temp);
//             }
//             return;
//         }
//         solve(root->left,sum,temp,targetSum);
//         solve(root->right,sum,temp,targetSum);

//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         int sum = 0;
//         vector<int>temp;
//         solve(root,sum,temp,targetSum);
//         return res;
        
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* a, vector<vector<int>> &v,int t,vector<int> &ans,int &temp)
    {
        if(!a) 
        {
            return;
        }

        ans.push_back(a->val);
        temp+=a->val;
        
        if(!a->left && !a->right)
        {
            if(temp==t) v.push_back(ans);
        }
        else
        {
            dfs(a->left,v,t,ans,temp);
            dfs(a->right,v,t,ans,temp);
        }

        ans.pop_back();
        temp-=a->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>> v; 
       if(!root) return v;
        
        vector<int> ans;
        int temp=0;
        dfs(root,v,targetSum,ans,temp);
        
        return v;
    }
};