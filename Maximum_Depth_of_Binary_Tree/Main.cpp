/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findMax(int a, int b)
{
    if(a<b)
    {
        a = b;
    }
    return a;
}


class Solution {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            depth = findMax(maxDepth(root->left),maxDepth(root->right))+1;
        }
        
        return depth;
    }
};
