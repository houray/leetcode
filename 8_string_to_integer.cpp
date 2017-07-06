class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        // Skip prefix spaces.
        int curr_idx = 0;
        bool negative = false;
        while (curr_idx < str.size()) {
            if (str[curr_idx] != ' ') {
                if (str[curr_idx] == '-') {
                    negative = true;
                    curr_idx++;
                    break;
                } else if (str[curr_idx] == '+') {
                    curr_idx++;
                    break;
                } else if (str[curr_idx] >= '0' && str[curr_idx] <= '9') {
                    break;
                } else { return 0; }
            }
            curr_idx++;
        }
        while (curr_idx < str.size() && str[curr_idx] >= '0' && str[curr_idx] <= '9') {
            result = result * 10 + (str[curr_idx] - '0');
            curr_idx ++;
            if (negative) {
                if (-result < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                if (result > INT_MAX) {
                    return INT_MAX;
                }
            }
        }
        
        return negative? -result : result;
    }
};
