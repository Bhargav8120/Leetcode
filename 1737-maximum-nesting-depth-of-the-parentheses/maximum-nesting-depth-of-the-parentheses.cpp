class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int maxDepth=0;

        for(auto it : s){
            if(it=='('){
                depth++;
                maxDepth=max(maxDepth,depth);
            }
            else if(it==')'){
                depth--;
            }
        }

        return maxDepth;
    }
};