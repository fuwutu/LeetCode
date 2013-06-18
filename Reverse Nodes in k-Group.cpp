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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode help(0);
        help.next = head;
        if (k >= 2)
        {
            ListNode* left = &help;
            ListNode* cur = head;
            while (cur != NULL && cur->next != NULL)
            {
                ListNode* rbegin = cur;
                ListNode* rend = cur;
                cur = cur->next;
                rend->next = NULL;
                int count = 2;
                while (count < k && cur->next != NULL)
                {
                    ListNode* temp = cur->next;
                    cur->next = rbegin;
                    rbegin = cur;
                    cur = temp;
                    ++count;
                }
                    
                if (count == k)
                {
                    rend->next = cur->next;
                    cur->next = rbegin;
                    left->next = cur;
                    left = rend;
                    cur = rend->next;
                }
                else
                {
                    while (rbegin != NULL)
                    {
                        ListNode* temp = rbegin;
                        rbegin = rbegin->next;
                        temp->next = cur;
                        cur = temp;
                    }
                    left->next = rend;
                    cur = NULL;
                }
            }
        }
        return help.next;
    }
};
