/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //your code goes here
        queue<TreeNode*> q;

        q.push(root);

        TreeNode* node=root;

        int depth=0;

        if(root==NULL){
            return 0;
        }

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                node=q.front();

                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            depth++;
        }

        return depth;
    }
};