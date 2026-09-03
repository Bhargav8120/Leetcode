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
		vector<int> inorderTraversal(TreeNode* root){
	        //your code goes here
            stack<TreeNode*> st;

            TreeNode* Node=root;

            vector<int> result;

            while(true){
                if(Node!=NULL){
                    st.push(Node);
                    Node=Node->left;
                }
                else{
                    if(st.empty()){
                        break;
                    }

                    Node=st.top();

                    st.pop();

                    result.push_back(Node->val);

                    Node=Node->right;
                    
                }
            }

            return result;
		}
};