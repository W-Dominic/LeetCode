int search(int* nums, int numsSize, int target){
    //optimal solution
    if (numsSize == 0){
        return -1;
    }
    int start = 0;
    int end = numsSize;  
    int middle = (end + start) / 2; 
    while ( (end >= start) && (end > -1) && (start < numsSize) ) {
        if (nums[middle] == target){
            return middle;
        }
        else if (nums[middle] < target){
            start = middle + 1; 
        }
        else if (nums[middle] > target){
            end = middle -1;
        }
        middle = (end + start) / 2;
    }
    return -1; 
    
}
