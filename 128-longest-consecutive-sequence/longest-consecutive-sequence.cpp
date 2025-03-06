class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        unordered_set<int> set(nums.begin(),nums.end());
        int longests=0;
        
        for(int num: set){
            if(set.find(num-1)==set.end()){
                int currentnum=num;
                int currents=1;
            
            while(set.find(currentnum+1)!=set.end()){
                currents++;
                currentnum++;
            }
            longests=max(longests,currents);
        }
        }
        return longests;
    }
};