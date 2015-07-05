/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        res.push_back(root->val);
        vector<int> left = rightSideView(root->left);
        vector<int> right = rightSideView(root->right);
        int index = 0;
        for(; index < right.size(); index ++){
            res.push_back(right[index]);
        }
        for(; index < left.size(); index++){
            res.push_back(left[index]);
        }
        return res;
    }
};
