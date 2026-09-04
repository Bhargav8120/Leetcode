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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //your code goes here
        TreeNode* n1=p;
        TreeNode* n2=q;

        if(n1==NULL && n2==NULL){
            return true;
        }

        if(n1==NULL || n2==NULL){
            return false;
        }

        if(n1->val != n2->val){
            return false;
        }

        return isSameTree(n1->left,n2->left) && isSameTree(n1->right,n2->right);

    }
};