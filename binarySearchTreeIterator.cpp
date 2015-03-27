/*
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 * */
/**
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class BSTIterator {
public:
    stack<TreeNode *> trail;
    BSTIterator(TreeNode *root) {
        while(root != NULL){
            trail.push(root);
            root = root->left;
        }
    }

    void pushTrail(TreeNode * root){
        while(root != NULL){
            trail.push(root);
            root = root->left;
        }        
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !trail.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * tmp = trail.top();
        trail.pop();
        if(tmp->right != NULL)
            pushTrail(tmp->right);
        return tmp->val;
    }
};

/**
 *  * Your BSTIterator will be called like this:
 *   * BSTIterator i = BSTIterator(root);
 *    * while (i.hasNext()) cout << i.next();
 *     */
