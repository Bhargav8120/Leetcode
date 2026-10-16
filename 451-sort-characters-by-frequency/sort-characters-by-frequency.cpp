class Solution {
public:
    static bool comp(pair<char,int> &a , pair<char,int> &b){
        if(a.second == b.second){
            return a.first<b.first;
        }

        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char,int> mpp;

        for(char c : s){
            mpp[c]++;
        }

        vector<pair<char,int>> v(mpp.begin(),mpp.end());

        sort(v.begin(),v.end(),comp);

        string ans;

        for(auto it : v){
            for(int i=0;i<it.second;i++){
                ans+=it.first;
            }
        }

        return ans;
    }
};