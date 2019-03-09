/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    /*****************************************
    *思路一
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL || pHead->next->next == NULL)
            return NULL;
        
        ListNode* fast = pHead->next->next;
        ListNode* slow = pHead->next;
        bool first = true;
        while(fast->next && fast->next->next)
        {
            if(first)
            {
                if(fast == slow)
                {
                    fast = pHead;
                    first = false;
                    continue;
                }
                fast = fast->next->next;
            }
            else
            {
                if(fast == slow) return fast;
                fast = fast->next;
            }
            slow = slow->next;
        }
        return NULL;
    }
    ***************************************/
    /*****************************************
    *思路二
    *****************************************/
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead || !pHead->next || !pHead->next->next) return nullptr;
        
        ListNode* fast = pHead->next->next;
        ListNode* slow = pHead->next;
        while(fast != slow)
        {
            if(fast->next && fast->next->next)
                fast = fast->next->next;
            else return nullptr;
            slow = slow->next;
        }
        fast = pHead;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
