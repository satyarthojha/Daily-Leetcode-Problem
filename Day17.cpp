//rearrangeing Fruits
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        //vector<int>basket1elem;
        vector<int>basketelem;
        //vector<int>basket2elem;
        long long ans=0;
        long long minCost=0;
       
        for(int num:basket1){
            mp[num]++;
        }
        for(int num:basket2){
            mp[num]--;
        }
        for(auto it:mp){
            /*if(it.second>0){
                if(it.second%2==1) return -1;
                for(int i=0;i<it.second/2;i++){
                    basket1elem.push_back(it.first);
                }
            }
            if(it.second<0){
                if((-it.second)%2==1) return -1;
                for(int i=0;i<(-it.second/2);i++){
                    basket2elem.push_back(it.first);
                }
            }*/if(it.second==0) continue;
             if (it.second % 2 != 0) return -1;
                int size=abs(it.second);
                for(int i=0;i<size/2;i++){
                    basketelem.push_back(it.first);
                
            }
            
        }
        sort(basketelem.begin(),basketelem.end());
        //sort(basket2elem.begin(),basket2elem.end(),greater<int>());

         /*int global_min = *min_element(basket1.begin(), basket1.end());
        global_min = min(global_min, *min_element(basket2.begin(), basket2.end()));

        //minimum element ke throuhg swapping kerni hai( indirect swapping) this is most important part 
        //jb direct swap small ho then direct swap ker do oterwise indirect swap ker do
        for(int i=0;i<basket1elem.size();i++){
           // minCost=min(basket1elem[i],basket2elem[i]);
            minCost = min(1LL * min(basket1elem[i], basket2elem[i]), 2LL * global_min);

            ans+=minCost;
        }*/
       /* int minElem=basketelem[0];
        for(int i=0;i<basketelem.size()/2;i++){
            minCost=min(basketelem[i],2*minElem);
            ans+=minCost;
        }*/
        sort(basketelem.begin(), basketelem.end());
        int minElem = min(*min_element(basket1.begin(), basket1.end()), 
        *min_element(basket2.begin(), basket2.end()));

        for (int i = 0; i < basketelem.size() / 2; i++) {
            ans += min((long long)basketelem[i], 2LL * minElem);
        }
        return ans;
    }
};