class Solution {
public:
    int reverse(int x) {

        long long n=x;

        long long reverseNumber=0;

        if(x<0){
            n= 1LL * (-1) * x;
        }

        while(n>0){
            reverseNumber= 1LL * reverseNumber*10 + 1LL * n%10;
            n= 1ll* n/10;
            
        }

        if(x<0){
            if(reverseNumber>INT_MAX){
                return 0;
            }
            else
            return -1 * reverseNumber;
        }

        if(reverseNumber>INT_MAX){
            return 0;
        }
        else return reverseNumber;
    }
};