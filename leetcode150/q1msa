class Solution(object):

    def merge(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        k = m + n - 1

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1


nums1 = list(map(int, input("Enter nums1: ").split()))
m = int(input("Enter m: "))

nums2 = list(map(int, input("Enter nums2: ").split()))
n = int(input("Enter n: "))

solution = Solution()
solution.merge(nums1, m, nums2, n)

print("Merged array:", nums1)
