/**
* Definition for binary tree
* struct TreeNode {
* int val;
* TreeNode *left;
* TreeNode *right;
* TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution
{
public:
    bool isSymmetric(TreeNode* a, TreeNode* b)
    {
        if (a != nullptr && b != nullptr)
        {
            return (a->val == b->val)
                && isSymmetric(a->left, b->right)
                && isSymmetric(a->right, b->left);
        }
        
        return (a == nullptr && b == nullptr);
    }
    
    bool isSymmetric(TreeNode* root)
    {
        return (root == nullptr) || isSymmetric(root->left, root->right);
    }
};
