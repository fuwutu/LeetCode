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
    bool isValidBST(TreeNode *root)
    {
        vector<int> vals;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                vals.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* temp = cur->left;
                while (temp->right != nullptr && temp->right != cur)
                {
                    temp = temp->right;
                }
                if (temp->right == nullptr)
                {
                    temp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    vals.push_back(cur->val);
                    temp->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        
        bool valid = true;
        for (size_t i = 1; i < vals.size(); ++i)
        {
            if (vals[i-1] >= vals[i])
            {
                valid = false;
                break;
            }
        }
        return valid;
    }
};
