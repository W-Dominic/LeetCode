class Solution {
public:
    int search(vector<int>& nums, int target) {
        //naiive solution
        int ptr1 = 0;
        int ptr2 = nums.size() -1;
        
        while (ptr2 > ptr1) {
            if (nums[ptr1] == target) return ptr1; 
            else if (nums[ptr2] == target) return ptr2;
            else{
                ptr1 ++;
                ptr2 --;
            } 
        }
        if (nums[ptr1] == target){
            return ptr1;
        }
        
        return -1; 
    }
};
