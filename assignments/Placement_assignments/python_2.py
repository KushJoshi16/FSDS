mystring = input("Enter a String.\n")

# if len(set([mystring.count(i) for i in set(mystring)])) <= 2:
#     print("Yes")
# else:
#     print("No")

print([mystring.count(i) for i in set(mystring)])