'''
A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

**Example 1:**

**Input:** s = "IDID"

**Output:**

[0,4,1,3,2]
'''

def strPerm(s: str) -> list[int]:
    l = 0
    h = len(s)
    rl = []

    for i in s:
        if i == 'I':
            rl.append(l)
            l+=1
        else:
            rl.append(h)
            h-=1
            
    rl.append(l)

    return rl