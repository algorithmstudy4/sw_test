 // leetcode
 // longestCommonPrefix
 // https://leetcode.com/problems/longest-common-prefix/
 
   string longestCommonPrefix(vector<string>& strs) {
        string res;
        int i = 0;
        bool more = true;
        int sz = strs.size();
        if(sz == 0) return res;
        while(more) {
            if(i >= strs[0].size()) {
                more = false;
                break;
            }
            char c = strs[0][i];
            for(int j = 1; j < sz; j++) {
                if(i >= strs[j].size() || c != strs[j][i]) {
                    more = false;
                    break;
                }
            }
            if(more) {
                res += c;
            }
            i++;
        }
        return res;
    }