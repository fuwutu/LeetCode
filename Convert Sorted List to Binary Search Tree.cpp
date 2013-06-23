/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> num;
        while (head != nullptr)
        {
            num.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(num, 0, num.size());
    }
};
