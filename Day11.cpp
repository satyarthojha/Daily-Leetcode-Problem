//maximum unique subarray sum after deletion
class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum=0;
        int count=0;
        unordered_map<int,int>mp;
        for(int num:nums){
            if(num>0){
                mp[num];
            }
            else{
                count++;
            }
        }
        if(count==nums.size()){
            return *max_element(nums.begin(),nums.end());
        }
        for(auto it :mp){
            sum+=it.first;
        }
        return sum;
        
    }
};