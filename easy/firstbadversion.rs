// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
		/* naiive solution
        let mut curr: i32 = n;
        
        while (curr != 0 && self.isBadVersion(curr)) {
            curr -= 1;   
        }
        curr+1
        */
        
        //binary search, more efficient
        let mut start: i32 = 1;
        let mut end: i32 = n;
        let mut mid: i32 = end/2;
        let mut curr: i32 = mid;
        while (start <= end) {
            mid = start + (end-start)/2;
            let res = self.isBadVersion(mid);
            if res {
                curr = mid;
                end = mid - 1; 
            }
            else {
                start = mid + 1;
            }
            
        }
        curr        
    }
    
}
