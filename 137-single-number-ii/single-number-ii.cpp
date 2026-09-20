class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        //your code goes here
        int one = 0, two =0;

        for(int i=0;i<nums.size();i++){
            one = (one ^ nums[i]) & ~two;
            two = (two ^ nums[i]) & ~one;
        }

        return one;
    }
};