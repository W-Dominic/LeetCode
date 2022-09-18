// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		let mut curr: i32 = n;
        
        while (curr != 0 && self.isBadVersion(curr)) {
            curr -= 1;   
        }
        curr+1
    }
    
    // bad = 1, n = 3
    // isbad(3) -> true, 2 != 0 -> true
    // isbad(2) -> true, 1 != 0 -> true
    // isbad(1) -> true, 0 != 0 -> false

}
