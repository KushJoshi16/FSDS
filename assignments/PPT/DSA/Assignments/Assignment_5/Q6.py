'''
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears **once** or **twice**, return *an array of all the integers that appears **twice***.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

**Example 1:**

**Input:** nums = [4,3,2,7,8,2,3,1]

**Output:**

[2,3]
'''

def findDuplicates(nums: list[int]) -> list[int]:
    n = len(nums)
    for i in range(n):
        nums[(nums[i]-1)%n] += n
    
    rv = [(i+1) for i in range(n) if nums[i]>2*n]
        
    return rv