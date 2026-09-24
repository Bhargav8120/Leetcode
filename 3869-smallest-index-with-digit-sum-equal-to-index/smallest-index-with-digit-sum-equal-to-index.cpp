class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int number=nums[i];
            int sum=sumOfNumbers(nums[i]);

            if(sum==i){
                return i;
            }
        }

        return -1;
    }

    int sumOfNumbers(int x){
        int sum=0;

        while(x>0){
            sum+=x%10;
            x=x/10;
        }

        return sum;
    }
};