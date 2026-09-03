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
		vector<int> preorderTraversal(TreeNode* root){
	       //your code goes here
           stack<TreeNode*> st;

           vector<int> result;

           TreeNode* Node=root;

           while(true){
            if(Node!=NULL){
                st.push(Node);

                result.push_back(Node->val);

                Node=Node->left;
            }
            else{
                if(st.empty()){
                    break;
                }
                Node=st.top();

                st.pop();

                Node=Node->right;
            }
           }
           return result;
		}
};