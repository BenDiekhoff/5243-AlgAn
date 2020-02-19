a = [6,3,5,2,1,4,0]
n = len(a)-1

for i in range(0,n):

    for j in range(0,n-i):
  
        if a[j] > a[j+1]:
            a[j], a[j+1] = a[j+1], a[j] #swap

print(a)

#insertion sort
a = [6,3,5,2,1,4,0]

for i in range(1,len(a)):
   
    key = a[i]
    j = i -1
    
    while j >=0 and a[j] > key:
       
        a[j+1] = a[j]
        j -= 1
    
    a[j+1] = key

print(a)


#selection sort
a = [6,3,5,2,1,4,0]

for i in range(0, len(a)-1):
    mindex = i
    for j in range(i+1, len(a)):
        if a[mindex] > a[j]:
            mindex = j
    a[i], a[mindex] = a[mindex], a[i]
print (a)




        