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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2) return NULL;
        ListNode* p1 = hasLoop(pHead1);
        ListNode* p2 = hasLoop(pHead2);
        if(!p1 && p2 || p1 && !p2) return NULL;
        if(!p1 && !p2) return first(pHead1, pHead2, NULL);
        if(p1 == p2) return first(pHead1, pHead2, p1);
        ListNode* cur = p1->next;
        while(cur != p2)
        {
            if(cur == p1) return NULL;
            cur = cur->next;
        }
        return cur;
    }
    ListNode* first(ListNode* p1, ListNode* p2, ListNode* end)
    {
        int num1 = 0;
        ListNode* cur = p1;
        while(cur != end) ++num1, cur = cur->next;
        int num2 = 0;
        cur = p2;
        while(cur != end) ++num2, cur = cur->next;
        for(int i = 0; i < abs(num1-num2); i++)
        {
            if(num1 > num2) p1 = p1->next;
            else p2 = p2->next;
        }
        while(p1 != p2) p1 = p1->next, p2 = p2->next;
        return p1;
    }
    ListNode* hasLoop(ListNode* p)
    {
        if(!p || !p->next || !p->next->next) return NULL;
        ListNode* fast = p->next->next;
        ListNode* slow = p->next;
        while(fast != slow)
        {
            if(!fast->next || !fast->next->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = p;
        while(fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};
