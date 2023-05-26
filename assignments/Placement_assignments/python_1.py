mydict = dict()
mystring = input("Enter a String.\n").split(' ')

hf = 0
for word in mystring:
    if word not in mydict:
        if word != ' ':
            mydict[word] = 1
    else:
        if word != ' ':
            mydict[word] += 1
    hf = mydict[word] if mydict[word]>hf else hf

mywordlen_list = set([len(i) for i in mydict if mydict[i]==hf])

for i in mywordlen_list:
    print(i,end=" ")
