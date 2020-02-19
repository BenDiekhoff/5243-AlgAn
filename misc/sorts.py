print ("\nBubble Sort\n-----------------------")
a = [6,3,5,2,1,4,0]
print(a)

n = len(a)
print(n)
for i in range(0,n-1):

    for j in range(0,n - 1 - i):
        print("{} {} {} \n".format(i,j, n-1-i))
        
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j] #swap

    print(a)

#insertion sort
print ("\nInsertion Sort\n-----------------------")
a = [6,3,5,2,1,4,0]
print(a)

n = len(a)

for i in range(1,n):
    key = a[i]
    j = i -1
    
    while j >=0 and a[j] > key:
        a[j+1] = a[j]
        j -= 1
    
    a[j+1] = key

    print(a)


#selection sort
print ("\nSelection Sort\n-----------------------")
a = [6,3,5,2,1,4,0]
print(a)

n = len(a)

for i in range(0, n-1):
    mindex = i
    
    for j in range(i+1, n):
        if a[mindex] > a[j]:
            mindex = j
    
    a[i], a[mindex] = a[mindex], a[i]
    
    print (a)




        