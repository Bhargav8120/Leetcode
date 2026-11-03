class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {

        int sumPeak=0;
        int sumValley=0;

        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                sumPeak+=nums[i];
            }

            if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){
                sumValley+=nums[i];
            }

        }

        return sumPeak - sumValley;
        
    }
};