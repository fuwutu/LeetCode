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
    bool hasPathSum(TreeNode *root, int sum)
    {
        return (NULL != root)
            && ((NULL != root->left && hasPathSum(root->left, sum - root->val))
            || (NULL != root->right && hasPathSum(root->right, sum - root->val))
            || (NULL == root->left && NULL == root->right && sum == root->val));
    }
};
