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
    vector<vector<int> > levelOrder(TreeNode* root) {
        //your code goes here

        vector<vector<int>> ans;

        queue<TreeNode*> q;

        q.push(root);

        if(root==NULL){
            return ans;
        }

        while(!q.empty()){

            int size=q.size();

            vector<int> level;

            for(int i=0;i<size;i++){
                TreeNode* Node=q.front();

                q.pop();

                level.push_back(Node->val);

                if(Node->left!=NULL) q.push(Node->left);

                if(Node->right!=NULL) q.push(Node->right);
            }

            ans.push_back(level);

        }

        return ans;

    }
};