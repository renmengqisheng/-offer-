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
    /********************************************
    *思路一
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vv;
        if(!pRoot) return vv;
        queue<TreeNode*> q;
        q.push(pRoot);
        bool first = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> v;
            stack<int> s;
            for(int i = 0; i < size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                if(first) v.push_back(t->val);
                else s.push(t->val);
            }
            while(!s.empty())
            {
                v.push_back(s.top());
                s.pop();
            }
            vv.push_back(v);
            first = !first;
        }
        return vv;
    }
    ***************************************/
    /***************************************
    *思路二
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vv;
        if(!pRoot) return vv;
        
        deque<TreeNode*> dq;
        dq.push_back(pRoot);
        bool derect = true;
        while(!dq.empty())
        {
            int size = dq.size();
            vector<int> v;
            for(int i = 0; i < size; i++)
            {
                if(derect)
                {
                    TreeNode* t = dq.front();
                    dq.pop_front();
                    if(t->left) dq.push_back(t->left);
                    if(t->right) dq.push_back(t->right);
                    v.push_back(t->val);
                }
                else
                {
                    TreeNode* t = dq.back();
                    dq.pop_back();
                    if(t->right) dq.push_front(t->right);
                    if(t->left) dq.push_front(t->left);
                    v.push_back(t->val);
                }
            }
            derect = !derect;
            vv.push_back(v);
        }
        return vv;
    }
    ***************************************/
    /***************************************
    *思路三
    ***************************************/
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vv;
        if(!pRoot) return vv;
        
        stack<TreeNode*> s1, s2;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty())
        {
            vector<int> v;
            if(!s1.empty())
            {
                int size = s1.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* t = s1.top();
                    s1.pop();
                    if(t->left) s2.push(t->left);
                    if(t->right) s2.push(t->right);
                    v.push_back(t->val);
                }
            }
            else
            {
                int size = s2.size();
                for(int i = 0; i < size; i++)
                {
                    TreeNode* t = s2.top();
                    s2.pop();
                    if(t->right) s1.push(t->right);
                    if(t->left) s1.push(t->left);
                    v.push_back(t->val);
                }
            }
            vv.push_back(v);
        }
        return vv;
    }
};
