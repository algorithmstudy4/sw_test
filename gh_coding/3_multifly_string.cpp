// 리트코드 (string)
// https://leetcode.com/problems/multiply-strings/

    string multiply(string num1, string num2) {
        map<int, vector<int>> position;
        string big, small, return_answer;
        if (!num1.compare("0") || !num2.compare("0"))
            return "0";
        if (num1.size() > num2.size()) {
            big = num1; small = num2;
        } else {
            big = num2; small = num1;
        }
        int start = 0;
        for (int i = (int)small.size()-1; i>= 0; i --) {
            for (int j = (int)big.size()-1; j>=0; j--) {
                int v = (small[i] - '0') * (big[j] - '0');
                position[(int)big.size()-j-1+start].push_back(v);
            }
            start ++;
        }
        vector<char> char_ans;
        int up = 0 ;
        for (int i = 0 ; i < (int)position.size() ; i ++) {
            vector<int> aaa = position[i];
            int sum = 0 ;
            for (int aa : aaa) {
                sum += aa;
            }
            sum += up;

            char_ans.push_back((char)(sum%10) + '0');
            up = sum / 10;
        }
        if (up >0) {
            char_ans.push_back((char)up+'0');
        }
        
        reverse(char_ans.begin(), char_ans.end());
        return_answer = string(char_ans.begin(), char_ans.end());
        return return_answer;
    }