class Solution {
public:
    int candy(vector<int>& ratings) {
        //your code goes here
        int n=ratings.size();

        if(n==0) return 0;

        vector<int> left(n,1);

        // vector<int> right(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
        }

        int curr=1;
        int right=1;

        int sum=max(1,left[n-1]);

        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr=right+1;
            }
            else{
                curr=1;
            }

            right=curr;

            sum+=max(left[i],curr);
        }

        return sum;

    }
};