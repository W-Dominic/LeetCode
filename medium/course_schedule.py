class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # this problem can be solved using a cycle detection algorithm
        # the adjacency list given can be modeled as a directed graph
        # traverse the graph from a selected starting vertex
        # if a cylce is detected, return false
        # else return true
        
        hmap = { i:[] for i in range(numCourses) } # initialize hmap with empty list values for each course
        for course, prereq in prerequisites: # Fill hmap with prereqs
            hmap[course].append(prereq) 
            
        visited = set() # keep track of visited nodes
        def dfs_cycle_detector(course): 
            if course in visited: # already visited
                return False
            if hmap[course] == []: # course has no prereqs so we can return true
                return True
            
            visited.add(course)
            for pre in hmap[course]:
                if not dfs_cycle_detector(pre): return False
            visited.remove(course)
            hmap[course] = []
            return True
        
        for course in range(numCourses):
            if not dfs_cycle_detector(course): return False
        return True
        
