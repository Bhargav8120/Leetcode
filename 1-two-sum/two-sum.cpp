class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> result;

        vector<vector<int>> mpp;

        for(int i=0;i<nums.size();i++){
           mpp.push_back({nums[i],i});
        }

        sort(mpp.begin(),mpp.end(),[](const vector<int> &a , const vector<int> &b){return a[0]<b[0];});

        int left=0;

        int right=mpp.size()-1;

        while(left<=right){

            int sum = mpp[left][0] + mpp[right][0];

            if(sum==target){
                result.push_back(mpp[left][1]);
                result.push_back(mpp[right][1]);
                return result;
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        
        return result;
    }
};