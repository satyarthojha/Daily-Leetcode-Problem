//maximum fruits harverted after at most k steps
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        vector<int>position(n);
        vector<int>prefixSum(n);
        int totalFruits=0;
        int maxFruits=0;
        
        for(int i=0;i<fruits.size();i++){
            position[i]=fruits[i][0];
            prefixSum[i]=(i==0?0:prefixSum[i-1])+fruits[i][1];
        }
        for(int d=0;d<=k/2;d++){
            int remain=k-2*d;
            int i=startPos-d;
            int j=startPos+remain;
            //apply binary search for i and j and use prefix sum to call all fruits between i and j index
            //and find max value
            //apply same thing for right to left
            int left=lower_bound(position.begin(),position.end(),i)-position.begin();
            int right=upper_bound(position.begin(),position.end(),j)-position.begin()-1;
            if(left<=right){
                totalFruits=prefixSum[right]-(left>0?prefixSum[left-1]:0);
                maxFruits=max(maxFruits,totalFruits);
            }
           
           
            //right to left
            remain=k-2*d;
            i=startPos-remain;
            j=startPos+d;

            left=lower_bound(position.begin(),position.end(),i)-position.begin();
            right=upper_bound(position.begin(),position.end(),j)-position.begin()-1;
            if(left<=right){
                totalFruits=prefixSum[right]-(left>0?prefixSum[left-1]:0);
                maxFruits=max(maxFruits,totalFruits);
            }
           
           



        }
        return maxFruits;
       

       
           
        
        
    }
};