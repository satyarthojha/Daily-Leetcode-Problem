//3136->valid word
class Solution {
public:
    bool isValid(string word) {
        int digit=0;
        int vowel=0;
        int consonant=0;
        if(word.size()<3){
            return false;
        }
        for(int i=0;i<word.size();i++){
            if(isdigit(word[i])){
                digit=1;
            }
            else if(isalpha(word[i])){
                char ch = tolower(word[i]);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    vowel=1;
                }
                else{
                    consonant=1;
                }
            }
            else{
                return false;
            }
        }
        if(vowel==1 && consonant==1){
            return true;
        }
        else{
            return false;
        }
    }
};