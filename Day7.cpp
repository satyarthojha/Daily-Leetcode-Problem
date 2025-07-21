//1957-> delete characters to make fancy string
class Solution {
public:
    string makeFancyString(string s) {
        int count=0;
        char ch=s[0];
        string str="";
        str.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                str.push_back(s[i]);
                count=0;
            }
            else if(s[i]==s[i-1] && count==0){
                str.push_back(s[i]);
                count++;
            }
           
            else{
                continue;
            }



        }
        

        return str;
        
    }
};