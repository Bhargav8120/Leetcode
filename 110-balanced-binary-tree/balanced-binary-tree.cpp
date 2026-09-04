/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : val(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:

    int height(TreeNode* node){
        if(node==NULL){
            return 0;
        }

        int left=height(node->left);

        int right=height(node->right);

        return 1 + max(left,right);
    }

    bool isBalanced(TreeNode *root){
    	//your code goes here
        if(root==NULL){
            return true;
        }

        int difference=abs(height(root->left) - height(root->right));

        if(difference>1){
            return false;
        }

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        return left && right;
        
    }
};