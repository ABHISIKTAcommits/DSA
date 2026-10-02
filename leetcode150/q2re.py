class Solution(object):

    def removeElement(self, nums, val):
        k = 0

        for i in range(len(nums)):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1

        return k
val=int(input("Enter the value to remove"))
nums = list(map(int, input("Enter array: ").split())) # Takes space-separated array input, converts each value into an integer, and stores them in a list.
solution=Solution()
k=solution.removeElement(nums,val)
print("k=",k)
print("Array =", nums[:k])  # slicing in list
