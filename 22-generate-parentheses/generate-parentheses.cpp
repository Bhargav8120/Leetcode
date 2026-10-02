class Solution {
public:

    void helper(int open,int close,int n,string s,vector<string> &ans){
        if(close>open) return;

        if(open>n) return;

        if(open+close==2*n && open==close){
            ans.push_back(s);
            return;
        }

        helper(open+1,close,n,s+'(',ans);

        if(open>close){
            helper(open,close+1,n,s+')',ans);
        }
    }


    vector<string> generateParenthesis(int n) {
        //your code goes here

        vector<string> ans;

        helper(0,0,n,"",ans);

        return ans;
    }
};