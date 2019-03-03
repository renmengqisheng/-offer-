/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    /***************************************
    *思路一
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot) return NULL;
        int index = 0;
        TreeNode* res = NULL;
        mid(pRoot, k, index, res);
        return res;
    }
    
    void mid(TreeNode* p, int k, int &index, TreeNode* &res)
    {
        if(!p) return;
        mid(p->left, k, index, res);
        if(++index == k) res = p;
        mid(p->right, k, index, res);
    }
    ****************************************/
    /***************************************
    *思路二
    ***************************************/
    int index = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot)
        {
            TreeNode* ret = KthNode(pRoot->left, k); //在左子树中找第k小的结点
            if(ret) return ret; //如果在左子树中，直接返回
            if(++index == k) return pRoot; //如果当前结点是第k小的结点，直接返回
            ret = KthNode(pRoot->right, k); //在右子树中找第k小的结点
            if(ret) return ret; //如果在右子树中，直接返回
        }
        return NULL;
    }
};
