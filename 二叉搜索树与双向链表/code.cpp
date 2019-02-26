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
    /*****************************************
    *思路一
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree || (!pRootOfTree->left && !pRootOfTree->right))
            return pRootOfTree;
        
        modify(pRootOfTree);
        
        while(pRootOfTree->left != NULL)
            pRootOfTree = pRootOfTree->left;
        
        return pRootOfTree;
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
    **********************************/
    /***************************************
    *思路二
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        
        stack<TreeNode*> s;
        TreeNode* cur = pRootOfTree;
        TreeNode* pre = NULL;
        bool first = true;
        while(cur || !s.empty())
        {
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if(first)
            {
                pRootOfTree = cur;
                pre = cur;
                first = false;
            }
            else
            {
                cur->left = pre;
                if(pre) pre->right = cur;
                pre = cur;
            }
            cur = cur->right;
        }
        return pRootOfTree;
    }
    ***********************************/
    /***********************************
    *思路三
    ***********************************/
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return NULL;
        
        TreeNode* pre = NULL;
        modify(pRootOfTree, pre);
        
        TreeNode* cur = pRootOfTree;
        while(cur->left) cur = cur->left;
        return cur;
    }
    
    void modify(TreeNode* root, TreeNode*& pre)
    {
        if(!root) return;
        
        modify(root->left, pre);
        
        root->left = pre;
        if(pre) pre->right = root;
        pre = root;
        
        modify(root->right, pre);
    }
    
};
