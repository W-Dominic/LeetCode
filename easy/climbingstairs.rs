impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        /* naiive (python)
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n == 2: 
            return 2
        
        return self.climbStairs(n-1) + self.climbStairs(n-2);
        */
        //more efficient (O(n))
        let mut pre: i32 = 1;
        let mut curr: i32 = 1; 
        let mut tmp: i32 = 0;
        for i in 1..n {
            tmp = curr;
            curr = curr + pre;
            pre = tmp; 
        }
        curr
    }
}
