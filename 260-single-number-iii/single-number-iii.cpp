class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
			//your code goes here
            vector<int> ans;
        
        /* Map to store the elements 
        and their frequencies */
        unordered_map <int, int> mpp;
        
        // Iterate on the array
        for(int i=0; i < nums.size(); i++) {
            mpp[nums[i]]++; // Update the map
        }
        
        // Iterate on the map
        for(auto it : mpp) {
            // If frequency is 1
            if(it.second == 1) {
                /* Add the element to
                the result array */
                ans.push_back(it.first);
            }
        }   
        
        // Return the result after sorting
        sort(ans.begin(), ans.end());
        return ans;
		}
};