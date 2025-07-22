//1695->maximum Erasure value
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0;
        unordered_map<int,pair<int,int>>mp;
        int sum=0;
    
        int left=0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) == mp.end() || mp[nums[i]].first==0){
                mp[nums[i]].first++;
                mp[nums[i]].second=i;
                sum+=nums[i];
            }
            else{
                //int value=mp[nums[i]].first;
                int index=mp[nums[i]].second;
                /*for(int j=index;j<=i;j++){
                    minus+=nums[j];
                    
                }*/
                while(left<=index){
                    sum-=nums[left];
                    mp[nums[left]].first--;
                    left++;
                }

                mp[nums[i]].first++;
                mp[nums[i]].second=i;
                sum+=nums[i];

            }
            ans=max(ans,sum);
        }
        return ans;
        
    }
};