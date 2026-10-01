nums = list(map(int, input("Enter array: ").split()))

k = 0

for i in range(len(nums)):
    if k < 2 or nums[i] != nums[k - 2]:
        nums[k] = nums[i]
        k += 1

print("k =", k)
print("Array =", nums[:k])
