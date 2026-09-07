class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(auto it : s){
            if(it=='('  || it=='{' || it=='[' ){
                st.push(it);
            }
            else{
                if(st.empty()){
                    return false;
                }

                char top=st.top();
                st.pop();

                if(it==')' && top != '(') return false;
                if(it=='}' && top != '{') return false;
                if(it==']' && top != '[') return false;
            }
        }

        return st.empty();

    }
};