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
        int sum = 0;
        stack<TreeNode*>  stk;
        stk.push(root);
        
        while(!stk.empty()){
            TreeNode *node = stk.top();
            stk.pop();
            if(node == nullptr) {
                continue;
            }
            if(node->val < low){
                 stk.push(node->right);   
            }
            else if(node->val > high){
                stk.push(node->left);
            }
            else{
                sum += node->val;
                stk.push(node->left);
                stk.push(node->right);
            }
        }
        
        return sum;
    }
};

/*
// Time: O(n), space: O(h)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == nullptr){
            return 0;
        }
        int rootVal = root->val;
        if(rootVal < low){
            return rangeSumBST(root->right, low, high);
        }
        else if(rootVal > high){
            return rangeSumBST(root->left, low, high);
        }
        return rootVal + rangeSumBST(root->left, low, rootVal) +
                         rangeSumBST(root->right, rootVal, high);
    }
};

*/