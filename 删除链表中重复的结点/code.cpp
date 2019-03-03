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
    /*******************************************
    *思路一
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next) return pHead;
        
        if(pHead->val == pHead->next->val)
        {
            ListNode* cur = pHead->next;
            while(cur && pHead->val == cur->val)
                cur = cur->next;
            return deleteDuplication(cur);
        }
        else
            pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
    ********************************************/
    /*******************************************
    *思路二
    *******************************************/
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead || !pHead->next) return pHead;
        ListNode* head = new ListNode(-1);
        head->next = pHead;
        ListNode* pre = head;
        while(pHead)
        {
            if(pHead->next && pHead->val == pHead->next->val)
            {
                pHead = pHead->next;
                while(pHead->next && pHead->val == pHead->next->val)
                {
                    pHead = pHead->next;
                }
                pre->next = pHead->next;
                pHead = pHead->next;
            }
            else
            {
                pre = pHead;
                pHead = pHead->next;
            }
            
        }
        return head->next;
    }
};
