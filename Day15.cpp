//longest subarray with maximum bitwise AND
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0;
        int ans=0;
        int maxBitwise=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxBitwise){
                count++;
                ans=max(ans,count);
            }
            else{
                count=0;
            }
        }
        return  ans;
    }
};