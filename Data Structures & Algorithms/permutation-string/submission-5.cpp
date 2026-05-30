    class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if (s1.length() > s2.length()) return false;
            vector<int> count(26, 0);

            for(int i=0;i<s1.size();i++) {
                count[s1[i]-'a']++;
                count[s2[i]-'a']--;
            }

            int l = 0, r = s1.size(), diff = 0;
            for(auto i: count) {
                if(i!=0) diff++;
            }

            while(r<s2.size()) {
                if(diff == 0) return true;

                int cr = s2[r]-'a';
                if(--count[cr] == 0) {
                    diff--;
                } else if(count[cr] == -1) diff++;

                int cl = s2[l]-'a';
                if(++count[cl] == 0) {
                    diff--;
                } else if(count[cl] == 1) diff++;
                r++;
                l++;
            }
            return diff == 0;

        }
    };
