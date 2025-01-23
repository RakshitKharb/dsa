class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<s.length();j++){
                mpp[s[j]]++;
                int least= INT_MAX;
                int maxi=INT_MIN;
                for(auto it:mpp){
                    least=min(least,it.second);
                    maxi=max(maxi,it.second);
                }
                ans+=maxi-least;
            }
        }
    return ans;
    }
};