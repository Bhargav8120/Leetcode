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

        TreeNode* findTarget(TreeNode* root,int target){
            if(root == NULL)
                return NULL;

            if(root->val == target)
                return root;

            TreeNode* left = findTarget(root->left, target);

            if(left != NULL)
                return left;

            return findTarget(root->right, target);
        }
        
		int amountOfTime(TreeNode* root, int start){
            //your code goes here
            queue<TreeNode*> q;

            int dist=0;

            if(root==NULL){
                return 0;
            }

            map<TreeNode*,TreeNode*> parentNode;

            q.push(root);

            parentNode[root]=NULL;

            while(!q.empty()){
                TreeNode* node=q.front();
                q.pop();

                if(node->left){
                    parentNode[node->left]=node;
                    q.push(node->left);
                }

                if(node->right){
                    parentNode[node->right]=node;
                    q.push(node->right);
                }
            }

            queue<TreeNode*> q1;

            set<TreeNode*> visited;

            TreeNode* givenTarget = findTarget(root,start);

            q1.push(givenTarget);

            visited.insert(givenTarget);

            while(!q1.empty()){
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

            return dist-1;
		}	
};