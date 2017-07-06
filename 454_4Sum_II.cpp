class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        unordered_map<int, int> count_map1;
        unordered_map<int, int> count_map2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                int curr_sum = A[i] + B[j];
                if (count_map1.find(curr_sum) == count_map1.end()) {
                    count_map1[curr_sum] = 1;
                } else {
                    count_map1[curr_sum] ++;
                }
            }
        }
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) {
                int curr_sum = C[i] + D[j];
                if (count_map2.find(curr_sum) == count_map2.end()) {
                    count_map2[curr_sum] = 1;
                } else {
                    count_map2[curr_sum] ++;
                }
            }
        }
        for (const auto& c : count_map1) {
            if (count_map2.find(-c.first) != count_map2.end()) {
                count += count_map2[-c.first] * c.second;
            }
        }
        return count;
    }
};
