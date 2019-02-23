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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k < 1)
            return NULL;
        
        ListNode* fast = pListHead;
        ListNode* slow = pListHead;
        while(--k > 0)
        {
            if(fast->next != NULL)
                fast = fast->next;
            else
                return NULL;
        }
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
