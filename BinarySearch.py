def BinarySearch(arr, target):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid-1
    return -1

n = int(input())
arr = list(map(int, input().split()))
target = int(input())
arr=sorted(arr)
result = BinarySearch(arr, target)
print(result)

