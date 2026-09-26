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

    TreeNode* solve(vector<int>& nums, int left, int right) {
        
        // Base case
        if (left > right) {
            return nullptr;
        }

        // Middle element becomes root
        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        // Left half -> left subtree
        root->left = solve(nums, left, mid - 1);

        // Right half -> right subtree
        root->right = solve(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }
};