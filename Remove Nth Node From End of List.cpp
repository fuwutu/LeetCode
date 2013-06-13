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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* node = head;
        int count = 1;
        while (node->next != NULL)
        {
            node = node->next;
            ++count;
        }
         
        if (count == n)
        {
            return head->next;
        }
         
        node = head;
        for (int i = 0; i < count - n - 1; ++i)
        {
            node = node->next;
        }
        node->next = node->next->next;
        return head;
    }
};
