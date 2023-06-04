'''
Given three integer arrays arr1, arr2 and arr3 **sorted** in **strictly increasing** order, return a sorted array of **only** the integers that appeared in **all** three arrays.

**Example 1:**

Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]

Output: [1,5]

**Explanation:** Only 1 and 5 appeared in the three arrays.

'''

def solve(l1 : list, l2 : list, l3 : list) -> list:
    i = 0
    j = 0
    k = 0
    rl = list()

    while(i<len(l1) and j<len(l2) and k<len(l3)):
        if (l1[i] == l2[j] and l2[j] == l3[k]):
            rl.append(l1[i])
            i += 1
            j += 1
            k += 1
        elif l1[i] < l2[j]:
            i += 1
        elif l2[j] < l3[k]:
            j += 1
        else:
            k += 1
    return rl


if __name__ == "__main__":
    with open("./input1.txt",'r') as f:
        t = int(f.readline())
        for test_cases in range(t):
            l1 = [int(i) for i in f.readline().split(' ')]
            l2 = [int(i) for i in f.readline().split(' ')]
            l3 = [int(i) for i in f.readline().split(' ')]
            print(solve(l1,l2,l3))
  