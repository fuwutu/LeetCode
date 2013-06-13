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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode* result = new ListNode(0);
        ListNode* l3 = result;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
            l3 = l3->next;
        }
         
        while (l1 != NULL)
        {
            int sum = l1->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l3 = l3->next;
        }
         
        while (l2 != NULL)
        {
            int sum = l2->val + carry;
            l3->next = new ListNode(sum % 10);
            carry = sum / 10;
            l2 = l2->next;
            l3 = l3->next;
        }
         
        while (carry != 0)
        {
            l3->next = new ListNode(carry % 10);
            carry /= 10;
            l3 = l3->next;
        }
         
        l3 = result;
        result = l3->next;
        delete l3;
         
        return result;
    }
};
