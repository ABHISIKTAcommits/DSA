
nums = list(map(int, input("Enter array elements: ").split()))
k = int(input("Enter k: "))

n = len(nums)
k = k % n

rotated = nums[n-k:] + nums[:n-k]

for i in range(n):
    nums[i] = rotated[i]

print("Rotated array:", nums)
