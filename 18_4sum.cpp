class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return vector<vector<int>>();
    unordered_map<int, vector<pair<int, int> > > sum_map;
    for (int i = 0; i < nums.size() - 1; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        int curr_sum = nums[i] + nums[j];
        sum_map[curr_sum].push_back(make_pair(i, j));
      }
    }

    set<vector<int>> tmp_result;
    
    for (const auto& s : sum_map) {
      int diff = target - s.first;
      if (diff <= s.first && sum_map.find(diff) != sum_map.end()) {
        for(const auto& s1 : sum_map[diff]) {
          for (const auto& s2 : sum_map[s.first]) {
            if (s2.first != s1.first && s2.first != s1.second && s2.second != s1.first && s2.second != s1.second) {
              vector<int> curr;
              curr.push_back(nums[s1.first]);
              curr.push_back(nums[s1.second]);
              curr.push_back(nums[s2.first]);
              curr.push_back(nums[s2.second]);
              sort(curr.begin(), curr.end());
              tmp_result.insert(curr);
            }
          }
        }
      }
    }
    vector<vector<int>> result(tmp_result.begin(), tmp_result.end());
    return result;
  }
};
