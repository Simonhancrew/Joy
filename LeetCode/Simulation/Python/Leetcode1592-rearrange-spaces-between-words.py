class Solution:
    def reorderSpaces(self, text: str) -> str:
        words = text.split()
        sp = text.count(' ')
        if len(words) == 1:
            return words[0] + ' ' * sp
        inter,extra = divmod(sp,len(words) - 1)
        return (' ' * inter).join(words) + ' ' * extra