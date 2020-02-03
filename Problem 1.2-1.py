import math
import itertools

second = 1000000# 1 microsecond is 1/1000000 seconds
minute = 60 * second
hour = 60 * minute
day = 24 * hour
month = 30 * day
year = 365 * day
century = 100 * year

times = [second, minute , hour, day, month, year, century]
timeNames = ['second','minute','hour','day','month','year','century']

print(times)

n=1
for (time, name) in zip(times, timeNames):
    print("\n---------------{}--({})--------------\n".format(name, time))
    
    
    #n!
    while math.factorial(n) < time:
        n = n + 1
    if math.factorial(n) != time:
        n = n-1
    x = math.factorial(n)
    print("(N!) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    n = 1
    print(x <= time)

    #2^n
    while 2**n < time:
        n = n + 1
    if 2**n != time:
        n = n-1
    x = 2**n
    print("(2^N) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    n = 1
    print(x <= time)


    #n^3
    while n**3 < time:
        n = n + 1
    if n**3 != time:
        n = n-1
    x = n**3
    print("(N^3) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    n = 1
    print(x <= time)

    #n^2
    while n**2 < time:
        n = n + 1
    if n**2 != time:
        n = n-1
    x = n**2
    print("(N^2) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    n = 1
    print(x <= time)


    #n lg n
    n = time
    near = False
    while near == False:
        while (n * (math.log(n,2))) > time:    
            temp = n-1
            n = math.floor((n/2))


        while ((n * (math.log(n,2)) < time) and (near == False)):
            n = math.floor(((n+temp)/2) )
            #print("n: {}, temp:{}".format(n,temp))
            if (temp - n) <= 1:
                #print("n: {}, temp:{}".format(n,temp))
                n = math.floor(n)
                near = True
        
    while ((n+1) * (math.log(n+1,2))) < time:
        n = n+1
    while (n * (math.log(n,2))) > time:
        n = n-1

    x = n * math.log(n,2)
    print("N LG(N) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    n=1
    print(x <= time)
                

    # #sqrt n
    # while math.sqrt(n) < time:
    #     n = n + 1
    # x = math.sqrt(n)
    # print("SQRT(N) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    # n = 1

    # # lg n
    # while math.log(n,2) < time:
    #     n = n + 1
    # x = math.log(n,2)
    # print("LG(N) largest size of n that can be solved in 1 {} is {} = {}".format(name,n,x))
    # n = 1











