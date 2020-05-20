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

//Pre-Order traversal of a BST gives elements in sorted order
vector<int> preOrder(TreeNode* root, vector<int> &v) {
    if(root) {
        preOrder(root->left, v);
        v.push_back(root->val);
        preOrder(root->right, v);
    }
    return v;
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    res = preOrder(root, res);
    return res[k-1];
}