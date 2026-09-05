class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();

        int maxi = nums[0];

        vector<int> maxiArray;
        maxiArray.push_back(nums[0]);

        vector<int> miniArray(n);
        miniArray[n-1] = nums[n-1];

        int ans = -1;

        // Prefix maximum
        for(int i = 1; i < n; i++){
            maxi = max(maxi, nums[i]);
            maxiArray.push_back(maxi);
        }

        // Suffix minimum
        for(int i = n-2; i >= 0; i--){
            miniArray[i] = min(miniArray[i+1], nums[i]);
        }

        // Find first stable index
        for(int i = 0; i < n; i++){
            int res = maxiArray[i] - miniArray[i];

            if(res <= k){
                ans = i;
                break;
            }
        }


        return ans;
    }
};