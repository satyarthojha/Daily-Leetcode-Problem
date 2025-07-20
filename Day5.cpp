1233->Remove sub floaders from the file system
vector<string> removeSubfolders(vector<string>& folder) {
        /*set<string>vec;
        sort(folder.begin(),folder.end());
        for( int i=0;i<folder.size()-1;i++){
            for(int j=i+1;j<folder.size();j++){
                int n=folder[i].size();
                if(folder[i]==folder[j].substr(0,n) && folder[j][n] == '/'
){
                    vec.insert(folder[i]);

                }
                else{
                    break;
                }

            }
        }
        vector<string>ans(vec.begin(),vec.end());
        return ans;*/
         sort(folder.begin(), folder.end());
        vector<string> result;
        result.push_back(folder[0]);
        //floder[0]is always a parent because it is lixiographically sorted so sabse chota sbse aage aayega
    
        for (int i = 1; i < folder.size(); i++) {
            string last = result.back();
            string current = folder[i];
        // Check if 'current' is a sub-folder of 'last'
            if (current.size() > last.size() && 
                current.substr(0, last.size()) == last && 
                current[last.size()] == '/') {
                continue; // Skip sub-folder
                //jo string apne adajcent ka parent nhi hua vo kisi ka nhi hoga because adj ke bad aur lagre alphabet aayege
            } else {
                result.push_back(current);
            }
        }
        return result;
        
    }