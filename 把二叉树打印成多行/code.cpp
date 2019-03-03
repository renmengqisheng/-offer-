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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vv;
            if(!pRoot) return vv;
            
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                vector<int> v;
                int size = q.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* t = q.front();
                    q.pop();
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                    v.push_back(t->val);
                }
                vv.push_back(v);
            }
            return vv;
        }
        **********************************/
        /*********************************
        *思路二
        *********************************/
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > vv;
            if(!pRoot) return vv;
            add(pRoot, 1, vv);
            return vv;
        }
    
        void add(TreeNode* p, int d, vector<vector<int>> &vv)
        {
            if(!p) return;
            if(d > vv.size()) vv.push_back(vector<int>());
            vv[d-1].push_back(p->val);
            add(p->left, d+1, vv);
            add(p->right, d+1, vv);
        }
};
