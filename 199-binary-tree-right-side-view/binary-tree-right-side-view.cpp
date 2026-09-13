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
    vector<int> rightSideView(TreeNode* root) {
        //your code goes here

        vector<int> ans;

        if(root==NULL){
            return ans;
        }

        queue<pair<TreeNode*,int>> q;

        map<int,TreeNode*> mp;

        q.push({root,0});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node=p.first;
            int x=p.second;

            mp[x]=node;

            if(node->left!=NULL){
                q.push({node->left,x+1});
            }

            if(node->right!=NULL){
                q.push({node->right,x+1});
            }
        }

        for(auto &p : mp){
            ans.push_back(p.second->val);
        }

        return ans;
    }
};