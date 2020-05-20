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

//In-Order traversal of a BST gives elements in sorted order
vector<int> inOrder(TreeNode* root, vector<int> &v) {
    if(root) {
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }
    return v;
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> res;
    res = inOrder(root, res);
    return res[k-1];
}