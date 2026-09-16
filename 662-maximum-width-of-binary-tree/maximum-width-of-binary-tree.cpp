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
    long long int widthOfBinaryTree(TreeNode* root) {
        //your code goes here

        if(root==NULL){
            return 0;
        }

        long long ans=0;

        queue<pair<TreeNode*,unsigned int>> q;

        q.push({root,0});

        while(!q.empty()){

            int size=q.size();

            int nmin=q.front().second;

            long long first=0 , last=0;

            for(int i=0;i<size;i++){
                int curr_id=q.front().second-nmin;

                TreeNode* node=q.front().first;

                q.pop();

                if(i==0){
                    first=curr_id;
                }

                if(i==size-1){
                    last=curr_id;
                }

                if(node->left){
                    q.push({node->left,(long long)curr_id*2+1});
                }

                if(node->right){
                    q.push({node->right,(long long)curr_id*2+2});
                }
            }

            ans=max(ans,(long long)last-first+1);
        }
        return ans;
    }
};