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
    TreeNode* sortedArrayToBST(const vector<int>& num, size_t begin, size_t end)
    {
        if (begin == end)
        {
            return nullptr;
        }
        
        size_t middle = (begin + end) / 2;
        TreeNode* root = new TreeNode(num[middle]);
        root->left = sortedArrayToBST(num, begin, middle);
        root->right = sortedArrayToBST(num, middle + 1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& num)
    {
        return sortedArrayToBST(num, 0, num.size());
    }
};
