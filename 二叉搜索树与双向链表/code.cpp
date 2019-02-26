/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return NULL;
        
        if(!pRootOfTree->left && !pRootOfTree->right)
            return pRootOfTree;
        
        TreeNode* newHead = pRootOfTree;
        while(newHead != NULL && newHead->left != NULL)
            newHead = newHead->left;
        
        modify(pRootOfTree);
        
        return newHead;
    }
    
    void modify(TreeNode*& pRootOfTree)
    {
        if(!pRootOfTree || (!pRootOfTree->left && !pRootOfTree->right))
            return;
        
        modify(pRootOfTree->left);
        modify(pRootOfTree->right);
        
        TreeNode* cur = pRootOfTree->left;
        while(cur != NULL && cur->right != NULL)
            cur = cur->right;
        if(cur)
        {
            cur->right = pRootOfTree;
            pRootOfTree->left = cur;
        }
        cur = pRootOfTree->right;
        while(cur != NULL && cur->left != NULL)
            cur = cur->left;
        if(cur)
        {
            cur->left = pRootOfTree;
            pRootOfTree->right = cur;
        }
    }
};
