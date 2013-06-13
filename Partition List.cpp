/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> less;
        vector<int> greater;
        ListNode* node = head;
        while (node != NULL)
        {
            if (node->val < x)
            {
                less.push_back(node->val);
            }
            else
            {
                greater.push_back(node->val);
            }
            node = node->next;
        }
        
        node = head;
        for (size_t i = 0; i < less.size(); ++i)
        {
            node->val = less[i];
            node = node->next;
        }
        for (size_t i = 0; i < greater.size(); ++i)
        {
            node->val = greater[i];
            node = node->next;
        }
        
        return head;
    }
};
