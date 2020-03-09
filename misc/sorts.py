#bubble sort
# a = [6,3,5,2,1,4,0]
# a = [0,1,2,3,4,5,6]
a = [6,5,4,3,2,1,0]

print ("\nBubble Sort\n-----------------------")
print(a)
print("\n")

n = len(a)
for i in range(0,n-1):
    noswap = True
    for j in range(0,n - 1 - i):
        if a[j] > a[j+1]:
            print(a)
            noswap = False
            a[j], a[j+1] = a[j+1], a[j] #swap

    if noswap == True:
        break
    print(a)


#insertion sort
a = [6,5,4,3,2,1,0]
print ("\nInsertion Sort\n-----------------------")
print(a)
print("\n")

n = len(a)
for i in range(1,n):
    key = a[i]
    j = i -1
    
    while j >=0 and a[j] > key:
        print(a)
        a[j+1] = a[j]
        j -= 1
    
    a[j+1] = key

    print(a)


#selection sort
a = [6,5,4,3,2,1,0]
print ("\nSelection Sort\n-----------------------")
print(a)
print("\n")

n = len(a)
for i in range(0, n-1):
    ind = i
    j = i+1
    
    for j in range(j, n):
        if a[ind] > a[j]:
            ind = j
    
    a[i], a[ind] = a[ind], a[i] #swap
    
    print (a)




        