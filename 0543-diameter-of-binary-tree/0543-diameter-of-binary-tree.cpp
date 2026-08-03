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
    pair<int,int> diameter(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {0,0};
        }

        pair<int,int> left=diameter(root->left); //dia,height
        pair<int,int> right=diameter(root->right);

        int currDia=left.second+right.second;

        int finalDia=max({currDia,left.first,right.first});
        int finalH=max(left.second,right.second)+1;


        return make_pair(finalDia,finalH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};