class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> num_map
        for (int i = 0; i < nums.size(); ++i) {
        	
        	auto got = num_map.find(target - nums[i]);
        	if (got != num_map.end()) {
        		result.push_back(i);
        		result.push_back(got->second);
        		return result;
        	}
        	num_map[nums[i]] = i;
        }
        return result;
    }
};