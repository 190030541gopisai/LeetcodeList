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
    bool isLeaf(TreeNode* root){
        return (root && root->left == nullptr && root->right == nullptr);
    }
    vector<int> getLeafs(TreeNode *root){
        vector<int> leafs;
        stack<TreeNode*> stk;
        
        while(root || !stk.empty()){
            if(root){
                if(isLeaf(root)){
                    leafs.push_back(root->val);
                }
                stk.push(root);
                root = root->left;
            }else{
                if(stk.empty()){
                    break;
                }
                root = stk.top() -> right;
                stk.pop();
            }
        }
    
        return leafs;
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1 = getLeafs(root1);
        vector<int> leafs2 = getLeafs(root2);
       
        return (leafs1 == leafs2);
    }
};