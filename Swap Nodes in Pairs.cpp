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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            swap(cur->val, cur->next->val);
            cur = cur->next->next;
        }
        return head;
    }
};
