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
    void pre(TreeNode* root, vector<int>&ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        pre(root->left,ans);
        pre(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        pre(root,ans);
        int s=0;
        int size=ans.size();
        int e=size-1;
        int sum=0;
        sort(ans.begin(), ans.end());
        while(e>s){
            sum=ans[s]+ans[e];
            if(sum==k) return true;
            if(sum>k) e--;
            if(sum<k) s++;
        }
        return false;
    }
};