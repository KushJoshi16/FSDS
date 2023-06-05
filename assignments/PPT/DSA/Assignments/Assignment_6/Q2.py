'''
You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

You must write a solution in O(log(m * n)) time complexity.
'''

def search_2DMatrix(matrix: list[list[int]], target: int) -> bool:
    m = len(matrix)
    n = len(matrix[0])
    l = 0
    h = m*n-1

    while(l<=h):
        mid = l + (h-l)//2
        mid_elem = matrix[mid//n][mid%n]

        if mid_elem == target:
            return True
        elif mid_elem > target:
            h = mid-1
        else:
            l = mid+1

    return False