/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (root != nullptr)
        {
            vector<TreeLinkNode*> level({root});
            vector<TreeLinkNode*> level_temp;
            while (!level.empty())
            {
                for (size_t i = 0; i < level.size() - 1; ++i)
                {
                    level[i]->next = level[i+1];
                }
                level.back()->next = nullptr;

                for (auto p : level)
                {
                    if (p->left != nullptr)
                    {
                        level_temp.push_back(p->left);
                    }
                    if (p->right != nullptr)
                    {
                        level_temp.push_back(p->right);
                    }
                }

                level.swap(level_temp);
                level_temp.clear();
            }
        }
    }
};
