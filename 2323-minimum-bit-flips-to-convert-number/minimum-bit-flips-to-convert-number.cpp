class Solution{   
public:    
    int minBitFlips(int start, int goal) { 
        //Your code goes here
        long long ans = start ^ goal;

        long long count=0;

        while(ans>0){
            count+=(ans & 1);
            ans>>=1;
        }

        return count;
    }
};