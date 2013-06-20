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
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> result;
        if (root != NULL)
        {
            vector<int> path;
            walk(root, sum, path, result);
        }
        return result;
    }
    
    void walk(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& result)
    {
        sum -= root->val;
        path.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == 0)
            {
                result.push_back(path);
            }
        }
        
        if (root->left != NULL)
        {
            walk(root->left, sum, path, result);
        }
        
        if (root->right != NULL)
        {
            walk(root->right, sum, path, result);
        }
        
        path.pop_back();
    }
};
