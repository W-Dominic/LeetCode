class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        
        def calc_dist(p1, p2):
            x1 = p1[0]
            x2 = p2[0]
            y1 = p1[1]
            y2 = p2[1]
            return sqrt((x1-x2)**2 + (y1-y2)**2)
        
        distances = []
        hmap = {}
        for x,y in points:
            dist = calc_dist([0,0],[x,y])
            if dist in hmap:
                hmap[dist].append([x,y])
            else:
                hmap[dist] = [[x,y]]
            distances.append(dist)
        results = []
        heapq.heapify(distances)
        i = 0 
        while (i in range(k)):
            curr = heapq.heappop(distances)
            vals = hmap[curr]
            i += len(vals)
            results.extend(vals)
        return results
            
        
        
