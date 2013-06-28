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
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> trees;
        generateTrees(1, n + 1, trees);
        return trees;
    }
    
    void generateTrees(int begin, int end, vector<TreeNode*>& trees)
    {
        if (begin != end)
        {
            for (int n = begin; n < end; ++n)
            {
                vector<TreeNode*> left_trees;
                vector<TreeNode*> right_trees;
                generateTrees(begin, n, left_trees);
                generateTrees(n + 1, end, right_trees);
                for (auto left_root : left_trees)
                {
                    for (auto right_root : right_trees)
                    {
                        TreeNode* root = new TreeNode(n);
                        root->left = left_root;
                        root->right = right_root;
                        trees.push_back(root);
                    }
                }
            }
        }
        else
        {
            trees.push_back(nullptr);
        }
    }
};
