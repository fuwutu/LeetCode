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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (true)
        {
            if (NULL != cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else if (!s.empty())
            {
                result.push_back(s.top()->val);
                cur = s.top()->right;
                s.pop();
            }
            else
            {
                break;
            }
        }
        return result;
    }
};
