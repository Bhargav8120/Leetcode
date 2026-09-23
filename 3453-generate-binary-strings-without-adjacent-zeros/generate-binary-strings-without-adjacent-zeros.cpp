class Solution {
public:
    vector<string> validStrings(int n) {
        // Your code goes here
        vector<string> result;

        string str;

        helper(0,n,str,result);

        return result;
    }

    void helper(int ind , int n , string str , vector<string> &result){

        if(ind==n){
            result.push_back(str);
            return;
        }

        if(str.empty() || str.back()!='0'){
            helper(ind+1 , n , str+"0" , result);
        }
        
        helper(ind+1 , n , str+"1" , result);

    }
};
