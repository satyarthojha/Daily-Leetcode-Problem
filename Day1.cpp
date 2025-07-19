//3202->Find the maximum length of a valid subarray -2
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        /*int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int a=(nums[i]+nums[i+1])%2;
            int count=0;
            for(int j=i;j<nums.size()-1;j++){
                if(a==(nums[j]+nums[j+1])%2){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;*/
      /*  int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[(nums[i]+nums[i+1])%2]++;
        }
        
        
        for(int i=1;i<nums.size()-1;i++){
            if((nums[i-1]+nums[i])%2!=(nums[i+1]+nums[i])%2){
                count++;
                i++;
                 
            }

        }
        int result=max(mp[0]+count,mp[1]+count);
        return result;*/
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                count++;
            }
        }
        int even=count;
        int odd=nums.size()-count;
        int num=0;
        int num2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1 && num%2==0){
                num++;
            }
            if(nums[i]%2==0 && num%2==1){
                num++;
            }


        }
        for(int i=0;i<nums.size();i++){
             if(nums[i]%2==0 && num2%2==0){
                num2++;
            }
            if(nums[i]%2==1 && num2%2==1){
                num2++;
            }
        }
        int ans=max(max(odd,even),max(num,num2));
        return ans;
       
    }
};