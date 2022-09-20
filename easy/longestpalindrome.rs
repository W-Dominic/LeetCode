use std::collections::HashMap;
impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        // iterate over string
        // construct hashmap <char,freq> for each unique char
        // palindrome can be created using the even freq and one odd freq
        // find the length of that longest palindrome
        
        let arr: Vec<char> = s.chars().collect();
        let mut hmap: HashMap<char, i32> = HashMap::new();
        for i in arr {
            hmap.entry(i).and_modify(|freq| *freq += 1)
                         .or_insert(1);
        }
        println!("{:?}", hmap);
        //find the length
        let mut length: i32 = 0;
        let mut maxOdd: i32 = 0;
        for (key, value) in hmap {
            if value % 2 == 0 {
                length += value;
            } 
            else if value > maxOdd {
                if maxOdd > 0 {
                    length += (maxOdd - 1);
                }
                maxOdd = value;
            }
            else {
                length += (value - 1);
            }
        }
        length + maxOdd
    }
}
