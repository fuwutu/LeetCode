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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode help(0);
        ListNode* cur = &help;
        
        lists.erase(remove(lists.begin(), lists.end(), nullptr), lists.end());
        
        while (!lists.empty())
        {
            size_t m = 0;
            for (size_t i = 1; i < lists.size(); ++i)
            {
                if (lists[i]->val < lists[m]->val)
                {
                    m = i;
                }
            }
            cur->next = lists[m];
            cur = cur->next;
            lists[m] = lists[m]->next;
            if (lists[m] == NULL)
            {
                lists.erase(lists.begin() + m);
            }
        }
        
        cur->next = NULL;
        
        return help.next;
    }
};
