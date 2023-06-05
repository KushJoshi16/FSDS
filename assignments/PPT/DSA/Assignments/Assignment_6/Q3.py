'''
Given an array of integers arr, return *true if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
'''

def validMountainArray(arr: list[int]) -> bool:
    n = len(arr)
    if n<3:
        return False
    direction = 1
    f1 = False
    f2 = False
    prev = arr[0]
    for i in range(1,n):
        if arr[i]*direction > prev:
            if not f2:
                f1 = True
            prev = arr[i]*direction
        elif arr[i]*direction < prev and direction > 0:
            f2 = True
            direction = -1
            prev = arr[i]*direction
        else:
            return False
    
    return f1 and f2