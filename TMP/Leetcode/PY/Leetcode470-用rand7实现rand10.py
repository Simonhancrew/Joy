
#
# class Solution:
#     def rand10(self):
#         while True:
#             t = (rand7() - 1) * 7 + rand7()
#             if 0 <= t <= 10:
#                 return t
#         return -1


class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            t = (rand7() - 1) * 7 + rand7()
            if t <= 40:
                return t % 10 + 1
        return -1