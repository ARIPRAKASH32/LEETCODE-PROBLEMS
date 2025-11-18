def Isort(nums):
    for i in range(len(nums)):
        j=i
        while arr[j-1]  >  arr[j] and j>0:
            arr[j-1] ,arr[j] = arr[j],arr[j-1]
            j-=1
    print(*nums)

n = int(input())
arr = list(map(int, input().split()))
arr = arr[:n]

Isort(arr)


