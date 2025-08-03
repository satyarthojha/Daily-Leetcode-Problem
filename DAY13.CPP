//COUNT NUMBER OF MAXIMUM BITWISE or SUBSETS
class Solution {
public:
    int maxOr=0;
    int count=0;

    void maxOrSubset(vector<int>nums,int index,int currentOr){
        if(index==nums.size()){
            if(currentOr==maxOr){
                count++;
            }
            return;
        }
        maxOrSubset(nums,index+1,currentOr | nums[index]);

        maxOrSubset(nums,index+1,currentOr);

    }
    int countMaxOrSubsets(vector<int>& nums) {
       
        for(int num : nums){
            maxOr = maxOr | num;
        }

        maxOrSubset(nums,0,0);
        return count;
        
    }
};