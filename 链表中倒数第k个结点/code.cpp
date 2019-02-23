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
            if(fast != NULL && fast->next != NULL)
                fast = fast->next;
            else if(k != 0)
                return NULL;
        }
        while(fast != NULL && fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
