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
    /************************************
    *思路一
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot || !pRoot->left && !pRoot->right) return true;
        string res1, res2;
        pre(pRoot, res1);
        reverse(pRoot);
        pre(pRoot, res2);
        return res1 == res2;
    }
    
    void pre(TreeNode* pRoot, string &str)
    {
        if(!pRoot)
        {
            str += '#';
            return;
        }
        str += to_string(pRoot->val);
        pre(pRoot->left, str);
        pre(pRoot->right, str);
    }
    
    void reverse(TreeNode* pRoot)
    {
        if(!pRoot || !pRoot->left && !pRoot->right) return;
        
        TreeNode* t = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = t;
        reverse(pRoot->left);
        reverse(pRoot->right);
    }
    ****************************************/
    /****************************************
    *思路二
    ****************************************/
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(!pRoot || !pRoot->left && !pRoot->right) return true;
        return compare(pRoot->left, pRoot->right);
    }
    
    bool compare(TreeNode* left, TreeNode* right)
    {
        if(!left) return !right;
        if(!right) return false;
        if(left->val != right->val) return false;
        return compare(left->left, right->right) && 
            compare(left->right, right->left);
    }
};
