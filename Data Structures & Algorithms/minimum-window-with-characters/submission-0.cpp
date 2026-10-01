class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlen = 1e9;

        unordered_map<char, int> mp;
        for (auto it : t) {
            mp[it]++;
        }

        int l = 0, r = 0;
        int char_present = 0;
        int start = -1;

        while (r < n) {
            if (mp[s[r]] > 0) {
                char_present++;
            }
            mp[s[r]]--;

            if (char_present == m) {
                // req char presenr in the  l-r
                while (char_present == m) {
                    if (mp[s[l]] >= 0) char_present--;
                    mp[s[l]]++;

                    if (minlen > r - l + 1) {
                        minlen = min(minlen, r - l + 1);
                        start = l;
                    }
                    l++;
                }

              
            }
            r++;
        }

        if (start == -1) return "";
        return s.substr(start, minlen);
    }
};
