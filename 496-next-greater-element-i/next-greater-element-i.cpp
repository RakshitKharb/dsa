class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            int temp=-1;
            bool flag=false;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    flag=true;
                }
                if(flag==true && nums2[j]>nums1[i]){
                    temp=nums2[j];
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};