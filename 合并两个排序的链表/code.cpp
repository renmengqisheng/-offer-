/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        /********************
        *思路一
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        ListNode* head = NULL;
        ListNode* p = head;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            if(pHead1->val <= pHead2->val)
            {
                if(head == NULL)
                    head = p = pHead1;
                else
                {
                    p->next = pHead1;
                    p = p->next;
                }
                pHead1 = pHead1->next;
            }
            else
            {
                if(head == NULL)
                    head = p = pHead2;
                else
                {
                    p->next = pHead2;
                    p = p->next;
                }
                pHead2 = pHead2->next;
            }
        }
        if(pHead1 != NULL)
            p->next = pHead1;
        else
            p->next = pHead2;
        
        return head;
        ****************************/
        /*****************************
        *思路二
        *****************************/
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        if(pHead1->val <= pHead2->val)
        {
            pHead1->next = Merge(pHead1->next, pHead2);
            return pHead1;
        }
        else
        {
            pHead2->next = Merge(pHead1, pHead2->next);
            return pHead2;
        }
    }
};
