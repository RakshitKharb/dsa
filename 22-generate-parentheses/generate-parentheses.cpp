class Solution {
public:
    void f(vector<string> &ans,int ob,int cb,int n,string s){
        if(ob==n && cb==n){
            ans.push_back(s);
            return;
        }
        if(ob<n){
        f(ans,ob+1,cb,n,s+"(");
    }
    if(cb<ob){
        f(ans,ob,cb+1,n,s+")");
    }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int ob=0;
        int cb=0;
        string s ="";
        f(ans,ob,cb,n,s);
        return ans;

    }
};