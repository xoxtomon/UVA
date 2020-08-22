
from sys import stdin

myString = stdin.readlines()

index = 0

while index < len(myString):
    myString[index].strip("\n")
    myInt = int(myString[index])

    if myInt == 0:
        break

    myCase = list(map(int,myString[index+1].strip('\n').split(' ')))

    peaks = 0

    for point in range(myInt):
        if point != myInt-1:
            #print(f'a[n]={myCase[point]}, a[n-1]={myCase[point-1]}, a[n+1]={myCase[point+1]}, a[n]>a[n+1]={myCase[point] > myCase[point+1]}, a[n]>a[n-1]={myCase[point] > myCase[point-1]}')
            if ((myCase[point] > myCase[point+1] and myCase[point] > myCase[point-1]) or 
            (myCase[point] < myCase[point+1] and myCase[point] < myCase[point-1])):
                peaks += 1
        else:
            #print(f'a[N]={myCase[point]}, a[n-1]={myCase[point-1]}, a[n+1]={myCase[0]}, a[n]>a[n+1]={myCase[point] > myCase[0]}, a[n]>a[n-1]={myCase[point] > myCase[point-1]}')
            if ((myCase[point] > myCase[0] and myCase[point] > myCase[point-1]) or 
            (myCase[point] < myCase[0] and myCase[point] < myCase[point-1])):
                peaks += 1

    print(peaks)

    index += 2