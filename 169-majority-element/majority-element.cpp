class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;

        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
            }
            if(element==nums[i]){
                count++;
            }
            else{
                count--;
            }
        }

        int maxCount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==element){
                maxCount++;
            }
        }

        int ans;

        if(maxCount>=nums.size()/2){
            ans = element;
        }

        return ans;
    }
};