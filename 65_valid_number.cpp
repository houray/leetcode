class Solution {
public:
    pair<bool, int> check_valid(const string& s, int i, bool deci) {
        bool has_digit = false;
        bool negative = false;

        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            i++;
            negative = true;
        }
        while (i < s.size()) {
                if (s[i] >= '0' && s[i] <= '9') {
                    ++i;
                    has_digit = true;
                } else { 
                    if (s[i] == '.' && !deci){
                        deci = true;
                        ++i;
                    } else {
                        return make_pair(has_digit, i);
                }
            } 
        }
        return make_pair(has_digit, i);
    }
    
    bool isNumber(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ' ') break;
            ++i;
        }
        if (i == s.size()) return false;
        pair<bool, int> num = check_valid(s, i, false);
        if (!num.first) return false;
        if (num.second == s.size()) return true; 
        i = num.second;
        if (s[num.second] == 'e') {
            pair<bool, int> num2 = check_valid(s, i + 1, true);
            if (!num2.first) return false;
            if (num2.second == s.size()) return true;
            i = num2.second;
        }
        while (i < s.size()) {
            if (s[i] != ' ') return false;
            ++i;
        }
        return true;
    }
};
