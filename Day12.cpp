//count hills and valley in an array
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        
        int count=0;
        int count1=0;
        int hill=0;
        int valley=0;
        /*for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[0]){
                count++;

            }
        }*/
        /*for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]==nums[nums.size()-1]){
                count1++;
            }
        }*/
        
        for(int i=count+1;i<nums.size()-count1-1;i++){
            if(nums[i-1]==nums[i]) continue;
            int j=i+1;
            while(j<nums.size() && nums[i]==nums[j]){
                j++;
            }
            if(j<nums.size()){
                if(nums[i-1]<nums[i] && nums[i]>nums[j]){
                    hill++;
                }
                if(nums[i-1]>nums[i] && nums[i]<nums[j]){
                    valley++;
                }


            }
            

        }
        return hill+valley;
       
        
    }
};