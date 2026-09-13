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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ans;
        vector<int> level;

        if(root==NULL){
            return ans;
        }

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int size=q.size();

            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                level.push_back(node->val);
                q.pop();

                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }

        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        //your code goes here

        vector<int> result;

        vector<vector<int>> levelTraversal=levelOrder(root);

        for(auto p : levelTraversal){
            result.push_back(p.back());
        }

         return result;
        
    }
};