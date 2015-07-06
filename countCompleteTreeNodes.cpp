/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    void num(TreeNode * root, int & res){
        if(root == NULL) return;
        res +=1;
        if(root->left != NULL){
            num(root->left, res);
        }
        if(root->right != NULL){
            num(root->right, res);
        }
    }
    int countNodes(TreeNode* root) {
        int res = 0;
        num(root, res);
        return res;
    }
};

