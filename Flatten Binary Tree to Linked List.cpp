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
    void flatten(TreeNode *root)
    {
        TreeNode* cur = root;
        while (NULL != cur)
        {
            if (NULL != cur->left)
            {
                TreeNode* end = cur->left;
                while (true)
                {
                    if (NULL != end->right)
                    {
                        end = end->right;
                    }
                    else if (NULL != end->left)
                    {
                        end = end->left;
                    }
                    else
                    {
                        break;
                    }
                }
                end->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            
            cur = cur->right;
        }
    }
};
