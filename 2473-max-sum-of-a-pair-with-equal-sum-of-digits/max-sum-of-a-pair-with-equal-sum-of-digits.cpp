class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int arr[84]={0};
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int temp=nums[i];
            while(temp!=0){
                sum+=temp%10;
                temp/=10;
            }
            if(arr[sum]!=0) ans=max(ans,nums[i]+arr[sum]);
            arr[sum]= max(arr[sum],nums[i]);
        }
        return ans;
    }
};