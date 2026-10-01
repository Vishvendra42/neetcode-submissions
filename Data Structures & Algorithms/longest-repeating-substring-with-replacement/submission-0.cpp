class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int l = 0, r = 0;
        int length = 0;
        int max_freq = 0;

        while (r < n) {
            freq[s[r] - 'A']++;

             max_freq = max(max_freq, freq[s[r] - 'A']);

            int change_pos = (r - l + 1) - max_freq;

            if (change_pos <= k) {
                length = max(length, r - l + 1);
                r++;
            } else {
                // chamge_pos >k
                while (change_pos > k) {
                    freq[s[l]-'A']--;
                    l++;
                    max_freq = *max_element(freq.begin(), freq.end());

                    change_pos = (r - l + 1) - max_freq;
                }
                
                r++;
            }
        }
        return length;
    }
};
