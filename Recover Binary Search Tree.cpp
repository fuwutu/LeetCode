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
    void recoverTree(TreeNode *root)
    {
        TreeNode* p = root;
        TreeNode* prev = nullptr;
        TreeNode* cur = nullptr;
        TreeNode* mistake1 = nullptr;
        TreeNode* mistake2 = nullptr;
        while (p != nullptr)
        {
            if (p->left == nullptr)
            {
                prev = cur;
                cur = p;
                if (prev != nullptr && prev->val > cur->val)
                {
                    if (mistake1 == nullptr)
                    {
                        mistake1 = prev;
                    }
                    mistake2 = cur;
                }
                p = p->right;
            }
            else
            {
                TreeNode* temp = p->left;
                while (temp->right != nullptr && temp->right != p)
                {
                    temp = temp->right;
                }
                if (temp->right == nullptr)
                {
                    temp->right = p;
                    p = p->left;
                }
                else
                {
                    prev = cur;
                    cur = p;
                    if (prev != nullptr && prev->val > cur->val)
                    {
                        if (mistake1 == nullptr)
                        {
                            mistake1 = prev;
                        }
                        mistake2 = cur;
                    }
                    temp->right = nullptr;
                    p = p->right;
                }
            }
        }
        
        swap(mistake1->val, mistake2->val);
    }
};
