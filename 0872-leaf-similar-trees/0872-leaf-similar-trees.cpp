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
//     TC = O(N + N)
//     SC = O(H) + O(H)
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stk1, stk2;
        
        stk1.push(root1);
        stk2.push(root2);
        
        while(!stk1.empty() && !stk2.empty()){
            if(dfs(stk1) != dfs(stk2)){
                return false;
            }
        }
        return (stk1.empty() && stk2.empty());
    }
    int dfs(stack<TreeNode*> &stk){
        while(!stk.empty()){
            TreeNode* node = stk.top(); 
            stk.pop();
            if(node->right){
                stk.push(node->right);
            }
            if(node->left){
                stk.push(node->left);
            }
            if(isLeaf(node)){
                return node->val;
            }
        }
        return -1;
    }
    bool isLeaf(TreeNode* root){
        return (root && !root->left && !root->right);
    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     bool isLeaf(TreeNode* root){
//         return (root && root->left == nullptr && root->right == nullptr);
//     }
//     vector<int> getLeafs(TreeNode *root){
//         vector<int> leafs;
//         stack<TreeNode*> stk;
        
//         while(root || !stk.empty()){
//             if(root){
//                 if(isLeaf(root)){
//                     leafs.push_back(root->val);
//                 }
//                 stk.push(root);
//                 root = root->left;
//             }else{
//                 if(stk.empty()){
//                     break;
//                 }
//                 root = stk.top() -> right;
//                 stk.pop();
//             }
//         }
    
//         return leafs;
//     }
// public:
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         vector<int> leafs1 = getLeafs(root1);
//         vector<int> leafs2 = getLeafs(root2);
       
//         return (leafs1 == leafs2);
//     }
// };