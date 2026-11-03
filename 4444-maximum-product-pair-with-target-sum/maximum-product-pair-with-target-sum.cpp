class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {

        vector<pair<int,int>> arr;

        for(int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        long long maxProduct = LLONG_MIN;

        vector<int> ans = {-1, -1};

        while(left < right) {

            long long sum = 1LL * arr[left].first + arr[right].first;

            if(sum == target) {

                // arr[right].first > arr[left].first
                if(arr[right].first > arr[left].first) {

                    long long product =
                        1LL * arr[left].first * arr[right].first;

                    if(product > maxProduct) {
                        maxProduct = product;

                        // Larger value's index first
                        ans = {arr[right].second, arr[left].second};
                    }
                }

                left++;
                right--;
            }

            else if(sum < target) {
                left++;
            }

            else {
                right--;
            }
        }

        return ans;
    }
};