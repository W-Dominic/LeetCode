use std::collections::HashMap;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let s1: Vec<char> = ransom_note.chars().collect();
        let s2: Vec<char> = magazine.chars().collect();
        if s1.len() > s2.len() {
            return false;
        }
        //make hashmap of char, frequency
        let mut hmap: HashMap<char, i32> = HashMap::new();
        for i in s2 {
                hmap.entry(i).and_modify(|entry| *entry += 1)
                             .or_insert(1);
        }
        for i in s1 {
            if !hmap.contains_key(&i){
                return false;
            }
            if hmap[&i] == 0{
                return false;
            }
            else {
                hmap.entry(i).and_modify(|entry| *entry -= 1);
            }
        }
        return true;
    }
}
