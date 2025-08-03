//smallest subarrays with maximum bitwise OR 

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       /* vector<vector<int>>vec;
        unordered_map<int,vector<int>>mp;
        for(int num:nums){
            vector<int>vec;
            vector<int>ans;
            while(num>0){
                vec.push_back(num%2);
                num=num/2;
            }
            for(int i=0;i<vec.size();i++){
                if(vec[i]==1){
                   mp[i+1]++;
                }
            }
        }
        */
        int n = nums.size();
        vector<int> answer(n);
        unordered_map<int, int> bitCount; 

        int right = n - 1;
        int orValue = 0;

        for (int i = n - 1; i >= 0; --i) {
            orValue |= nums[i];

           
            for (int b = 0; b < 32; ++b) {
                if ((nums[i] >> b) & 1) {
                    bitCount[b] = i;
                }
            }

            int farthest = i;
            for (auto [bit, index] : bitCount) {
                farthest = max(farthest, index);
            }

            answer[i] = farthest - i + 1;
        }

        return answer;
            
    }
};