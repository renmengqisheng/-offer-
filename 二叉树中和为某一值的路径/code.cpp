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
    vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
        vector<vector<int> > res;
        vector<int> v;
        
        if(root != NULL)
        {
            DFS(root, expectNumber, v, res);
            sort(res.begin(), res.end(), [](vector<int> a, vector<int> b){return a.size() > b.size();});
        }
        return res;
    }
    
    void DFS(TreeNode* root, int e, vector<int> v, vector<vector<int> >& res)
    {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        e -= root->val;
        if(e == 0 && root->left == NULL && root->right == NULL)
        {
            res.push_back(v);
            v.pop_back();
            return;
        }
        
        DFS(root->left, e, v, res);
        DFS(root->right, e, v, res);
        
        //v.pop_back();  //以引用形式传递v时要加上这句
    }
};
