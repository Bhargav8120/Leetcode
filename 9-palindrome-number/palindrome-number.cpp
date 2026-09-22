class Solution {
public:

    long long reverseHelper(long long x){

        long long reverseNumber = 0;

        while(x>0){
            reverseNumber = reverseNumber * 10 + x%10;
            x=x/10;
        }

        return reverseNumber;
    }
    
    bool isPalindrome(int x) {
        long long reverseNumber = reverseHelper((long long)x);

        if(x==reverseNumber) return true;

        return false;
    }
};