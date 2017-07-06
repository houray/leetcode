class Solution {
public:
    int reverse(int x) {
        bool flag = x < 0;
        int result = 0;
        int prev = 0;
        x = x > -1 ? x : -x;
        while (x > 0) {
            int curr_d = x % 10;
            x = x / 10;
            if (result > 214748364) {
                return 0;
            }
            result = result * 10 + curr_d;
            
            
        }
        return flag ? -result : result;
    }
};
