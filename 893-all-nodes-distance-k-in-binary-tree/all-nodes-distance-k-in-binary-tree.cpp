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
	vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
		//your code goes here

        queue<TreeNode*> q;

        map<TreeNode*,TreeNode*> parentNode;

        parentNode[root]=NULL;

        vector<int> result;

        if(root==NULL){
            return result;
        }

        q.push(root);

        int dist=0;

        while(!q.empty()){

            TreeNode* node=q.front();
            q.pop();

            if(node->left!=NULL){
                parentNode[node->left]=node;
                q.push(node->left);
            }

            if(node->right!=NULL){
                parentNode[node->right]=node;
                q.push(node->right);
            }
        }

        set<TreeNode*> visited;

        queue<TreeNode*> q1;

        q1.push(target);
        
        visited.insert(target);

        while(dist!=k){

            int size=q1.size();

            for(int i=0;i<size;i++){

                TreeNode* node = q1.front();
                q1.pop();

                if(node->left && visited.find(node->left)==visited.end()){
                    q1.push(node->left);
                    visited.insert(node->left);
                }

                if(node->right && visited.find(node->right)==visited.end()){
                    q1.push(node->right);
                    visited.insert(node->right);
                }

                if(parentNode[node] && visited.find(parentNode[node])==visited.end()){
                    q1.push(parentNode[node]);
                    visited.insert(parentNode[node]);
                }

            }
            dist++;
        }

        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();

            result.push_back(node->val);
        }

        return result;

    }
};