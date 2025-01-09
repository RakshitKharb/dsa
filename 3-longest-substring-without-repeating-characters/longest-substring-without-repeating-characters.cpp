class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start=0;
        int maxi=0;
        unordered_map<char,int> mpp;
        for(int i=0;i<s.length();i++){
            char curr=s[i];
            mpp[curr]++;

            while(mpp[curr]>1){
                mpp[s[start]]--;
                start++;
            }
            maxi=max(maxi,i-start+1);
        }
        return maxi;
    }
};