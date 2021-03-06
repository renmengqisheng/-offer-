/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(!pNode) return NULL;
        
        if(pNode->right)
        {
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        TreeLinkNode* p = pNode->next;
        while(p)
        {
            if(p->left == pNode) return p;
            pNode = p;
            p = p->next;
        }
        return NULL;
    }
};
