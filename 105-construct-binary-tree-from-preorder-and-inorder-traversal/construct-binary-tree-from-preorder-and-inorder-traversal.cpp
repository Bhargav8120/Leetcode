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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //your code goes here

        unordered_map<int,int> inorderMap;

        for(int i=0;i<inorder.size();i++){
            inorderMap[inorder[i]]=i;
        }

        return buildTreeHelper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderMap);

    }

    TreeNode* buildTreeHelper(vector<int> &preorder,int preStart,int preEnd , vector<int> &inorder,int inStart,int inEnd,unordered_map<int,int> &inMap){


        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = inMap[root->val];

        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inEnd,inMap);

        root->right = buildTreeHelper(preorder , preStart + numsLeft + 1 ,preEnd , inorder , inRoot + 1 , inEnd , inMap);

        return root;

    }
};