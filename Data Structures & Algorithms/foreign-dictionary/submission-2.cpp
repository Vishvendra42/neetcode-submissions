class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int>present(26,0);
        for(auto &word:words){
            for( auto &ch :word){
                present[ch-'a']=1;
            }
        }

        bool edges[26][26]={}; // for duplicate edge
        
        vector<vector<int>>adj(26);
        vector<int>indegree(26,0);
    
        for( int i =0;i<words.size()-1;i++){
            string w1= words[i];
            string w2= words[i+1];
            
            int len = min( w1.length() , w2.length());
            bool foundDifference=false;
            for( int j=0;j<len;j++){
                if( w1[j]!=w2[j]){
                   adj[w1[j]-'a'].push_back(w2[j]-'a');
                  
                    indegree[w2[j]-'a']++;
                    foundDifference=true;
                    break;
                }
            }

            if( !foundDifference && w2.length() < w1.length())return "";
        }

       

        queue<int> q;
        int noOfCharacter=0;
        for( int i=0;i<26;i++){
            if( present[i]){
                noOfCharacter++;
              if( indegree[i]==0)q.push(i);
            }
            
        }
        string ans="";
        while( !q.empty()){
            int ch =q.front();
            q.pop();
            ans+=ch+'a';
            for( auto &it: adj[ch]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }

        }

        if( ans.size() !=noOfCharacter)return "";
        return ans;


    }
};
