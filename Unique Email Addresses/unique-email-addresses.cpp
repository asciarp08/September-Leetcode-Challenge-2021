/**
Time = O(n*m), n= emails.size() and m = average of emails[i].size()
Space = O(n*m)
**/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        
        unordered_map<string,bool> uniqueEmails;
        
        for(auto s:emails){
            int n = s.size();
            int i = 0;
            string t = "";
            
            while(i<n && s[i]!='+' && s[i]!='@'){
                if(s[i]!='.')
                    t+=s[i];
                i++;
            }
            
            while(i<n && s[i]!='@')i++;
            
            while(i<n){
                t+=s[i++];
                
            }
            
            uniqueEmails[t] = 1;
        }
        
        return uniqueEmails.size();
    }
};
