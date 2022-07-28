#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> myMap;
        for (int i = 0; i<nums.size(); i++){
            int val = target - nums[i];
            if (myMap.find(val) != myMap.end()){
                vector<int> result;
                result.push_back(myMap[val]);
                result.push_back(i);
                return result;
            }
            myMap[nums[i]] = i;
        }
        return nums;
    }
};
