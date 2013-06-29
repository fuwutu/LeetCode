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
    ListNode* rotateRight(ListNode* head, int k)
    {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* cur = head;
        int count = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            count += 1;
        }
        
        if (count != 0)
        {
            int r = k % count;
            if (r != 0)
            {
                r = count - r;
                cur = head;
                for (int i = 1; i < r; ++i)
                {
                    cur = cur->next;
                }
                ListNode* first = cur->next;
                cur->next = nullptr;
            
                cur = first;
                for (int i = r + 1; i < count; ++i)
                {
                    cur = cur->next;
                }
                
                cur->next = head;
                dummy.next = first;
            }
        }
        
        return dummy.next;
    }
};
