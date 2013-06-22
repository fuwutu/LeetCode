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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (m < n)
        {
            ListNode help(0);
            help.next = head;
            
            ListNode* left = &help;
            for (int i = 1; i < m; ++i)
            {
                left = left->next;
            }
            
            ListNode* rend = left->next;
            ListNode* middle = rend;
            ListNode* rbegin = rend->next;
            ListNode* right = rbegin->next;
            for (int i = 1; i < n - m; ++i)
            {
                rbegin->next = middle;
                middle = rbegin;
                rbegin = right;
                right = right->next;
            }
            rbegin->next = middle;
            
            left->next = rbegin;
            rend->next = right;
            
            head = help.next;
        }
        return head;
    }
};
