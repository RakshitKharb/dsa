class Solution {
public:
    string reverseWords(string s) {
        vector<string> mpp;
        string temp="";

        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                if(!temp.empty())
                mpp.push_back(temp);
                temp="";
            }
            else{
                temp=temp+ s[i];
            }
        }
        if(temp!=""){
            mpp.push_back(temp);
        }
        string ans="";
        for(int i=mpp.size()-1;i>=0;i--){
            if(i==0){
                ans=ans+ mpp[i] ;
            }
            else{
                ans=ans+mpp[i]+ " ";
            }
        }
        return ans;
    }
};