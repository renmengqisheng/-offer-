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
    /********************************
    *思路一
    char* Serialize(TreeNode *root) {
        if(!root) return NULL;
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            if(q.front())
            {
                str += to_string(t->val)+'!';
                q.push(t->left);
                q.push(t->right);
            }
            else str += "#!";
            q.pop();
        }
        char* res = strdup(str.c_str());
        return res;
    }
    TreeNode* Deserialize(char *str) {
        if(!str) return NULL;
        int len = strlen(str);
        vector<string> v;
        string t;
        for(int i = 0; i < len; i++)
        {
            if(str[i] != '!')
                t += str[i];
            else
            {
                v.push_back(t);
                t = "";
            }
        }
        int index = 0;
        queue<TreeNode*> q;
        TreeNode* head = new TreeNode(atoi(v[index++].c_str()));
        q.push(head);
        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            if(v[index] != "#")
                t->left = new TreeNode(atoi(v[index].c_str()));
            index++;
            if(v[index] != "#")
                t->right = new TreeNode(atoi(v[index].c_str()));
            index++;
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return head;
    }
    ************************************/
    /***********************************
    *思路二
    ***********************************/
    char* Serialize(TreeNode *root) {
        if(!root) return NULL;
        return strdup(DFS(root).c_str());
    }
    string DFS(TreeNode* p)
    {
        if(!p) return "#!";
        string str = to_string(p->val)+"!";
        str += DFS(p->left);
        str += DFS(p->right);
        return str;
    }
    TreeNode* Deserialize(char *&str) {
        if(!str) return NULL;
        if(*str == '#')
        {
            ++str;
            return NULL;
        }
        int num = 0;
        while(*str != '!')
        {
            num *= 10;
            num += *str - '0';
            ++str;
        }
        TreeNode* p = new TreeNode(num);
        p->left = Deserialize(++str);
        p->right = Deserialize(++str);
        return p;
    }
};
