class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp;

        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        // mp["IV"]=4;
        // mp["IX"]=9;
        // mp["XL"]=49;
        // mp["XC"]=90;
        // mp["CD"]=400;
        // mp["CM"]=900;


        int ans=0;

        for(int i=0;i<s.size();){
            
            if(i+1<s.size() && s[i]=='I' && s[i+1]=='V'){
                ans+=4;
                i=i+2;
            }
            else if(i+1<s.size() &&  s[i]=='I' && s[i+1]=='X'){
                ans+=9;
                i=i+2;
            }
            else if( i+1<s.size() && s[i]=='X' && s[i+1]=='L'){
                ans+=40;
                i=i+2;
            }
            else if(i+1<s.size() &&  s[i]=='X' && s[i+1]=='C'){
                ans+=90;
                i=i+2;
            }
            else if(i+1<s.size() && s[i]=='C' && s[i+1]=='D'){
                ans+=400;
                i=i+2;
            }
            else if(i+1<s.size() && s[i]=='C' && s[i+1]=='M'){
                ans+=900;
                i=i+2;
            }
            else{
                ans+=mp[s[i]];
                i++;
            }
            
        }

        return ans;
    }
};