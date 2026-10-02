nums = list(map(int, input("Enter array: ").split()))

count = 0
candidate = 0

for num in nums:
    if count == 0:
        candidate = num

    if num == candidate:
        count += 1
    else:
        count -= 1

print("Majority element:", candidate)
