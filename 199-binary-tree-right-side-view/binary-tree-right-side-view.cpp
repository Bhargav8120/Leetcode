/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:

    void preOrder(TreeNode* root,int depth,vector<int> &level){
        if(root==NULL){
            return;
        }

        if(depth==level.size()){
            level.push_back(root->val);
        }

        preOrder(root->right,depth+1,level);

        preOrder(root->left,depth+1,level);
        
    }

    vector<int> rightSideView(TreeNode* root) {
        //your code goes here
        vector<int> level;

        preOrder(root,0,level);

        return level;
    }
};