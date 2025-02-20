class Solution {
public:
    bool f(vector<vector<int>>&dp, vector<int>&nums, int ind,int target){
        if(target==0){
            return true;
        }
        if(ind==0) return (nums[0]==target); 
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(nums[ind]<=target){
            take= f(dp,nums,ind-1,target-nums[ind]);
        }
        bool nottake=f(dp,nums,ind-1,target);
        return dp[ind][target]= take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int target=sum/2;
        if(sum%2) return false;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(dp,nums,n-1,target);
    }
};