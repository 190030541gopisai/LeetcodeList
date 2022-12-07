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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return 0;
        }
        int rootVal = root->val;
        if(rootVal < low && rootVal < high){
            return rangeSumBST(root->right, low, high);
        }
        else if(rootVal > low && rootVal > high){
            return rangeSumBST(root->left, low, high);
        }
        else{
            return rootVal + rangeSumBST(root->left, low, rootVal) +
                    rangeSumBST(root->right, rootVal, high);
        }
    }
};