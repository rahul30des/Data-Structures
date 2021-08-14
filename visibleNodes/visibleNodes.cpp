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
    void visibleNodesUtil(TreeNode *root, int &count, int max_value) {
        int current_value = INT_MIN;
        if(root == NULL) {
            return;
        } else {
            current_value = root->val;
        }
        if(current_value >= max_value) {
            ++count;
            max_value = current_value;
        }
        visibleNodesUtil(root->left, count, max_value);
        visibleNodesUtil(root->right, count, max_value);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        visibleNodesUtil(root, count, INT_MIN);
        return count;
    }
};
