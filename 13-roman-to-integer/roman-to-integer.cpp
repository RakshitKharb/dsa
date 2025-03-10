class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        unordered_map<char,int> mpp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<s.length();i++){
            if(mpp[s[i]]<mpp[s[i+1]]){
                result-=mpp[s[i]];
            }
            else{
                result+=mpp[s[i]];
            }
        }
        return result;
    }
};