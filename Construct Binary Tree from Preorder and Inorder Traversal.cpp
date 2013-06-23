/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* buildTree(vector<int>::iterator prebegin, vector<int>::iterator preend, vector<int>::iterator inbegin, vector<int>::iterator inend)
    {
        TreeNode* root = nullptr;
        if (prebegin != preend)
        {
            root = new TreeNode(*prebegin);
            auto it = find(inbegin, inend, *prebegin);
            root->left = buildTree(prebegin + 1, prebegin + 1 + (it - inbegin), inbegin, it);
            root->right = buildTree(prebegin + 1 + (it - inbegin), preend, it + 1, inend);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
