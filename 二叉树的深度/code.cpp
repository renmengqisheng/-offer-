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
    /*****************************
    *思路一
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == nullptr) return 0;
        
        return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
    }
    *****************************/
    /*****************************
    *思路二
    ****************************/
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot) return 0;
        
        queue<TreeNode*> q;
        q.push(pRoot);
        int level = 0;
        while(!q.empty())
        {
            level++;
            int width = q.size();
            for(int i = 0; i < width; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return level;
    }
};
