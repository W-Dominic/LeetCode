class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # we cant use extra memory so lets use two pointers
        p1 = 1
        p2 = len(numbers)

        while(p1 != p2):
            if (numbers[p1-1] + numbers[p2-1] > target): p2 -= 1
            elif (numbers[p1-1] + numbers[p2-1] < target): p1 += 1
            else: return [p1, p2]
