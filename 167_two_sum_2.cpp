class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> num_map;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i) {
            auto got = num_map.find(target - numbers[i]);
        	if (got != num_map.end()) {
        	    result.push_back(got->second + 1);
        	    result.push_back(i + 1);
        		return result;
        	}
        }
        return result;
    }
};