class Solution {
public:
    int f(vector<int>&dp, int ind,vector<int>&nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int select= nums[ind] + f(dp,ind-2,nums);
        int nselect= f(dp,ind-1,nums);
        return dp[ind]=max(select,nselect);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return nums[0];

        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        vector<int> nums1(nums.begin()+1,nums.end());
        vector<int> nums2(nums.begin(),nums.end()-1);

        return max(f(dp1,n-2,nums1) , f(dp2,n-2,nums2));
    }
};