'''
Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].

*Return the array in the form* [x1,y1,x2,y2,...,xn,yn].

**Example 1:**

**Input:** nums = [2,5,1,3,4,7], n = 3

**Output:** [2,3,5,4,1,7]
'''


def shuffle(nums: list[int], n: int) -> list[int]:
    rl = []
    tgl = 0
    for i in range(n):
        rl.append(nums[i])
        rl.append(nums[n+i])

    return rl