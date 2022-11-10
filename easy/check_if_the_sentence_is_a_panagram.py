class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        used = set()
        for c in sentence:
            if not c in used:
                used.add(c)
        return len(used) == 26
