class Solution {  
public:
    bool checkValidString(string s) {
        //your code goes 
        int minCount=0;
        int maxCount=0;

        for(char c : s){
            if(c=='('){
                minCount++;
                maxCount++;
            }
            else if(c==')'){
                minCount--;
                maxCount--;
            }
            else if(c=='*'){
                minCount--;
                maxCount++;
            }

            if(maxCount<0) return false;
 
            if(minCount<0) minCount=0;

        }
        return minCount==0;
        
    }
};