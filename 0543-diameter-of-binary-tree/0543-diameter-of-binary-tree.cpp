/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }

        int currDia=height(root->left)+height(root->right);
        int leftDia=diameterOfBinaryTree(root->left);
        int rightDia=diameterOfBinaryTree(root->right);

        return max({currDia,leftDia,rightDia});
    }
};