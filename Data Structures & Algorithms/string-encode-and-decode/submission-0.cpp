class Solution {
   public:
    string encode(vector<string>& strs) {
        string encoded = "#";
        for (auto& it : strs) {
            int n = it.size();
            encoded = encoded + to_string(n) + "#" + it ;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 1;
        while (i < s.size()) {

           int j=i+1;

           while(s[j]!='#')j++;

           int size =stoi( s.substr( i,j-i));

           i=j+1;
           string temp = s.substr(i,size);

           i+=size;

           ans.push_back(temp);
        }
        return ans;
    }
};
