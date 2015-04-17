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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool flag = false;
        if((p==NULL && q!=NULL)||(q==NULL && p!=NULL))
        {
            return false;
        }
        
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p->val == q->val)
        {
            if(isSameTree(p->left, q->left))
            {
                if(isSameTree(p->right, q->right))
                {
                    flag = true;
                }
                
            }
        }
        
        return flag;
    }
};