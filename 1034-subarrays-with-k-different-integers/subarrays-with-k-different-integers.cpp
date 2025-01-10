class Solution {
public:
    int helper(vector<int>&nums, int k){
        int start=0;
        int n=nums.size();
        int c=0;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;

            while(mpp.size()>k){
                mpp[nums[start]]--;
                if(mpp[nums[start]]==0){
                    mpp.erase(nums[start]);
                }
                start++;
            }
            c=c+(i-start+1);
        }
        return c;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x= helper(nums,k);
        int y=helper(nums,k-1);
        return x-y;
    }
};