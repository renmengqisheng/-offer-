class Solution {
public:
    /*******************************************
    *思路一
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        
        return abs(depth(pRoot->left)-depth(pRoot->right)) < 2 &&
            IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    
    int depth(TreeNode* p)
    {
        if(!p) return 0;
        
        return max(depth(p->left),depth(p->right))+1;
    }
    *******************************************/
    /******************************************
    *思路二
    ******************************************/
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return depth(pRoot) != -1;
    }
    
    int depth(TreeNode* pRoot) {
        if(!pRoot) return 0;
        
        int left = depth(pRoot->left);
        if(left == -1) return -1;
        int right = depth(pRoot->right);
        if(right == -1) return -1;
        return abs(left-right) > 1? -1: max(left,right)+1;
    }
};
