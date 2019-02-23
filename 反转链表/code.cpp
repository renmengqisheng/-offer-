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
    ListNode* ReverseList(ListNode* pHead) {
        //if(pHead == NULL)
        //    return NULL;
        //if(pHead->next == NULL)
        //    return pHead;
        /**********************
        *思路一
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
        ***********************/
        /*********************
        *思路二
        **********************/
        if(pHead == NULL || pHead->next == NULL)
            return pHead;
        
        ListNode* repHead = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = NULL;
        return repHead;
    }
};
