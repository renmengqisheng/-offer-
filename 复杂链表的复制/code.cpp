/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        
        /****************************************
        *思路一
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode* cur = pHead;
        while(cur)
        {
            RandomListNode* newNode = new RandomListNode(cur->label);
            m[cur] = newNode;
            cur = cur->next;
        }
        cur = pHead;
        RandomListNode* newHead = m[pHead];
        pHead = newHead;
        while(cur)
        {
            if(m.count(cur->next))
                pHead->next = m[cur->next];
            if(m.count(cur->random))
                pHead->random = m[cur->random];
            cur = cur->next;
            pHead = pHead->next;
        }
        return newHead;
        ************************************/
        /***********************************
        *思路二
        ***********************************/
        RandomListNode* cur = pHead;
        while(cur)
        {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = pHead;
        while(cur)
        {
            RandomListNode* node = cur->next;
            if(cur->random)
                node->random = cur->random->next;
            cur = node->next;
        }
        cur = pHead;
        pHead = cur->next;
        while(cur)
        {
            RandomListNode* node = cur->next;
            cur->next = node->next;
            if(cur->next)
                node->next = cur->next->next;
            cur = cur->next;
        }
        
        return pHead;
    }
};
