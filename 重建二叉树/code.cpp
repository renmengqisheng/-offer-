/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() == 0 || vin.size() == 0)
            return NULL;
        
        TreeNode* root = new TreeNode(pre[0]);
        int i = 0;
        for(; i < vin.size(); i++)
        {
            if(vin[i] == pre[0])
                break;
        }
        
        //vector<int> nextPreLeft(pre.begin()+1, pre.begin()+i+1);
        //vector<int> nextVinLeft(vin.begin(), vin.begin()+i);
        //vector<int> nextPreRight(pre.begin()+i+1, pre.end());
        //vector<int> nextVinRight(vin.begin()+i+1, vin.end());
        //root->left = reConstructBinaryTree(nextPreLeft, nextVinLeft);
        //root->right = reConstructBinaryTree(nextPreRight, nextVinRight);
        root->left = reConstructBinaryTree(vector<int>(pre.begin()+1, pre.begin()+i+1), 
                                           vector<int>(vin.begin(), vin.begin()+i));
        root->right = reConstructBinaryTree(vector<int>(pre.begin()+i+1, pre.end()), 
                                           vector<int>(vin.begin()+i+1, vin.end()));
        return root;
    }
};
