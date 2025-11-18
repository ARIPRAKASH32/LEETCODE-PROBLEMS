def Ssort(nums):
    for i in range(len(nums)):
        minpos = i
        for j in range(i+1, len(nums)):
            if nums[j] < nums[minpos]:
                minpos = j
        nums[i], nums[minpos] = nums[minpos], nums[i]

        print(*nums)

n = int(input())
arr = list(map(int, input().split()))
arr = arr[:n]

Ssort(arr)


