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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //your code goes here
        unordered_map<int,int> inMap;

        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }

        return buildTreeHelper(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size() - 1 , inMap);
    }

    TreeNode* buildTreeHelper(vector<int> &inorder , int inStart , int inEnd , vector<int> &postorder , int postStart , int postEnd , unordered_map<int,int> &inMap){

        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }

        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndexInorder = inMap[rootValue];
        int leftTree = rootIndexInorder - inStart;

        root->left = buildTreeHelper(inorder , inStart , rootIndexInorder - 1 , postorder , postStart , postStart + leftTree-1 , inMap);

        root->right = buildTreeHelper(inorder , rootIndexInorder+1 , inEnd , postorder , postStart + leftTree , postEnd - 1 ,inMap);

        return root;


    }
};