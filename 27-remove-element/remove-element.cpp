class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=0;

        int n=nums.size();

       while(right<n){
        if(nums[right]==val){
            right++;
        }
        else{
            swap(nums[left],nums[right]);
            left++;
            right++;
        }
       }
        int k=0;
       for(int i=0;i<n;i++){
        if(nums[i]!=val){
            k++;
        }
    }

    return k;
    }

   

    
};