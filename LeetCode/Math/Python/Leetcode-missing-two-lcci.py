class Solution:
    def missingTwo(self, nums):
        ans, n, acc = [0] * 2, len(nums) + 2, 0
        for num in nums:
            acc ^= num
        for i in range(1, n + 1):
            acc ^= i
        lowbit = acc & (-acc)
        print(bin(lowbit))
        for num in nums:
            print(num & lowbit)
            if (num & lowbit) != 0:
                ans[0] ^= num
            else:
                ans[1] ^= num
        for i in range(1, n + 1):
            if (i & lowbit) != 0:
                ans[0] ^= i
            else:
                ans[1] ^= i
        return ans


# if __name__ == '__main__':
#     input = [2]
#     solve = Solution()
#     print(solve.missingTwo(input))
