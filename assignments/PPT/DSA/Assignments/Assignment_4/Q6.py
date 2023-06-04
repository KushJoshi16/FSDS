'''
Given an integer array nums sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

Input: nums = [-4,-1,0,3,10]

Output: [0,1,9,16,100]

**Explanation:** After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100]

'''

def sortedSquares(nums: list[int]) -> list[int]:
    nums = [i**2 for i in nums]
    i = 0
    j = len(nums)-1
    rv = []
    while(i<=j):
        a = nums[j]
        if(nums[i]>a):
            a = nums[i]
            i+=1
        else:
            j-=1
        rv.insert(0,a)
    return rv