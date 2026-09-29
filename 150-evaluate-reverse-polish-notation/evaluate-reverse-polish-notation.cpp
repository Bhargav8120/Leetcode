class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int ans;

        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int right=s.top();
                s.pop();
                int left=s.top();
                s.pop();

                char op=tokens[i][0];
                switch(op)
                {
                    case '+':
                    ans=left+right;
                    break;

                     case '-':
                    ans=left-right;
                    break;

                     case '*':
                    ans=left*right;
                    break;

                     case '/':
                    ans=left/right;
                    break;
                }
                s.push(ans);
            }
            else
            {
                int n=stoi(tokens[i]);
                s.push(n);
            }
        }
        return s.top();
    }
};