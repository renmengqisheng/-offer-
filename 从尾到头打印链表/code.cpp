/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        /*****************
        *解法一
        *****************/
        while(head != NULL)
        {
            v.insert(v.begin(), head->val);
            head = head->next;
        }
        
        /**
        *解法二
        if(head != NULL)
        {
            stack<int> s;
            ListNode* p = head;
            while(p != NULL)
            {
                s.push(p->val);
                p = p->next;
            }

            while(!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
        }
        **/
        return v;
    }
};
