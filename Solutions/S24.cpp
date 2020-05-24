class Solution {
public:
    int preidx;
    unordered_map<int, int> m;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int st, int en) {
        if(st > en) return NULL;
        int val = preorder[preidx++];
        TreeNode* node = new TreeNode(val);
        int pos = m[val];
        node->left = buildTree(preorder, inorder, st, pos - 1);
        node->right = buildTree(preorder, inorder, pos + 1, en);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        preidx = 0;
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        m.clear();
        //Store positions of values as they appear in the inorder traversal using a hashmap
        for(int i = 0; i < preorder.size(); i++) m[inorder[i]] = i;
        return buildTree(preorder, inorder, 0, n - 1);
    }
};