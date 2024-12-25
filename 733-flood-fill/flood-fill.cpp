class Solution {
public:
    void dfs(int row,int col, vector<vector<int>>& image,vector<vector<int>>&ans,int color,int m, int n,int startingclr){
        ans[row][col]=color;
        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r= row+ nrow[i];
            int c= col+ ncol[i];
            if(r>=0 && c>=0 && r<m && c<n && ans[r][c]!=color && image[r][c]==startingclr && ans[r][c]!=color){
                dfs(r,c,image,ans,color,m,n,startingclr);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int m=image.size();
        int n=image[0].size();
        
        int startingclr=ans[sr][sc];
        dfs(sr,sc,image,ans,color,m,n,startingclr);
        return ans;
    }
};