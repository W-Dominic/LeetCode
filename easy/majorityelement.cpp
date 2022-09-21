class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Morre majority voting algorithm
        int possible_element = nums[0];
        int count = 1; 
        for (int i = 1; i < nums.size(); i++){
            int current = nums[i];
            if (current == possible_element){
                count += 1;
            }
            else {
                count --;
            }
            if (count == 0){
                possible_element = current;
                count = 1;
            }
        }
        return possible_element;
        
        // [2,2,1,1,1,2,2]
        // possible, count
        // 2,1
        // 2,2
        // 2,1
        // 2,0
        // 1,1
        // 2,1
        // 2,2
        
    }
};
