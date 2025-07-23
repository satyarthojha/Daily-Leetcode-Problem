//1717->Maximum Score From removeing Substrings
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        /*
        string str=(x>y) ? "ab" : "ba";
        string remainStr="";
        for(int i=0;i<s.size()-1;i++){
            if(substr(i,2)==str){
                int point= (str="ab") ? x : y;
                totPoint+= point;
            }
            else{
                remainStr.push_back(s[i]);

            }
        }*/
        string first = "ab", second = "ba";
        int firstScore = x, secondScore = y;

        if (y > x) {
            swap(first, second);
            swap(firstScore, secondScore);
        }

       // string first=(x>y) ? "ab" : "ba";
       // int firstScore= (str="ab") ? x : y;

        string temp = "";
        int total = 0;
        for (char c : s) {
            temp += c;
            int len = temp.length();
            if (len >= 2 && temp.substr(len - 2) == first) {
                temp.pop_back(); 
                temp.pop_back(); 
                total += firstScore;
            }
        }

       
        string finalStr = "";
        for (char c : temp) {
            finalStr += c;
            int len = finalStr.length();
            if (len >= 2 && finalStr.substr(len - 2) == second) {
                finalStr.pop_back();
                finalStr.pop_back();
                total += secondScore;
            }
        }

        return total;

        
    }
};