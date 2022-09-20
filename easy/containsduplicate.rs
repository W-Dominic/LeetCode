use std::collections::HashMap;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hmap: HashMap<i32, i32> = HashMap::new();
        for i in nums{
            if !hmap.contains_key(&i) {
                hmap.insert(i,i);
            }
            else {
                return true;
            }
        }
        return false;
    }
}
