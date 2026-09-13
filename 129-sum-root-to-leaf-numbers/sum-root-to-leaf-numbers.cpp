/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,vector<vector<int>> &allPaths,vector<int> &paths){
        if(root==NULL){
            return;
        }

        paths.push_back(root->val);

        if(root->left==NULL && root->right==NULL){
            allPaths.push_back(paths);
        }
            
        else{

            dfs(root->left,allPaths,paths);

            dfs(root->right,allPaths,paths);
        }

        paths.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root,vector<vector<int>> &allPaths,vector<int> &paths) {
        //your code goes here

        dfs(root,allPaths,paths);

        return allPaths;
    }

    int sumNumbers(TreeNode* root) {
        
        vector<vector<int>> allPaths;

        vector<int> paths;

        allRootToLeaf(root,allPaths,paths);

        int ans=0;

        for(int i = 0; i < allPaths.size(); i++){

            int num = 0;

            for(int j = 0; j < allPaths[i].size(); j++){
                num = num * 10 + allPaths[i][j];
            }

        ans += num;
    }

        return ans;

    }
};