/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 . k . BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
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
    bool findk(TreeNode * root, int & k, int & res){
        if(root->left != NULL){
            if(findk(root->left, k, res)) return true;
        }
        if(k == 1) {
            res = root->val;
            return true;
        }
        k -=1;
        if(root->right != NULL){
            if (findk(root->right, k, res)) return true;
        }
        return false;
    }
    int kthSmallest(TreeNode* root, int k) {
        int res;
        findk(root, k, res);
        return res;
    }
};
