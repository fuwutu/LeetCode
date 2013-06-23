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
    TreeNode* buildTree(vector<int>::iterator inbegin, vector<int>::iterator inend, vector<int>::iterator postbegin, vector<int>::iterator postend)
    {
        TreeNode* root = nullptr;
        if (postbegin != postend)
        {
            root = new TreeNode(*(postend - 1));
            auto it = find(inbegin, inend, *(postend - 1));
            root->left = buildTree(inbegin, it, postbegin, postbegin + (it - inbegin));
            root->right = buildTree(it + 1, inend, postbegin + (it - inbegin), postend - 1);
        }
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};
