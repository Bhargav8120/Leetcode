class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int l=0;
        int r=k-1;

        int sum=0;

        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        double average=(double)sum/k;

        double newAverage;

        while(r<nums.size()-1){
            sum=sum-nums[l];
            l++;
            r++;
            sum=sum+nums[r];

            newAverage=(double)sum/k;

            if(newAverage>average){
                average=newAverage;
            }

        }

        return (double)average;
    }
};