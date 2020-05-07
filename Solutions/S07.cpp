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

int level(TreeNode* root, int x, int lev) {
    if(root == NULL) return 0;
    else if(root -> val == x) return lev;
    else {
        int le = level(root->left, x, lev + 1);
        if(le != 0) return le;
        else return level(root->right, x, lev + 1);
    }
}

bool sibling(TreeNode* root, int x, int y) {
    if(root == NULL) return false;
    else return (root->left && root->left->val == x && root->right && root->right->val == y) ||
                (root->right && root->right->val == x && root->left && root->left->val == y) ||
                sibling(root->left, x, y) || sibling(root->right, x, y);
}

bool isCousins(TreeNode* root, int x, int y) {
    if(level(root, x, 1) == level(root, y, 1) && !sibling(root, x, y)) return true;
    return false;
}