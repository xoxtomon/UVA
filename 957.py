from collections import deque
from sys import stdin

def myBisect(lst, num):
    startIndex = 0
    endIndex = len(lst)
    
    while startIndex < endIndex:
        mid = startIndex + (endIndex - startIndex) // 2

        if num >= lst[mid]:
            startIndex = mid + 1
        else:
            endIndex = mid
    
    return startIndex


def main():
    myRawString = stdin.readlines()

    myPeriod = int()
    myPopes = int()

    index = 0

    while index < len(myRawString):
        myPeriod = int(myRawString[index].strip('\n'))
        myPopes = int(myRawString[index+1].strip('\n'))

        myCase = [int(x.strip('\n')) for x in myRawString[index+2:index+2+myPopes]]
        

        myCurrent = 0
        myFinal = [0,0,0]
        for i in range(len(myCase)):
            #myComp = bisect.bisect(myCase, myCase[i] + myPeriod - 1)
            myComp = myBisect(myCase, myCase[i] + myPeriod - 1)
            if(myComp - i > myCurrent):
                myCurrent = myComp - i
                myFinal[0] = myCurrent
                myFinal[1] = myCase[i]
                myFinal[2] = myCase[myComp-1]


        #print(f'period: {myPeriod}, popes: {myPopes}')
        #print(myRawString[index:myPopes+2])
        print(f'{myFinal[0]} {myFinal[1]} {myFinal[2]}')

        index += (3 + myPopes)
    #myCases = myRawString.split(' ')
    #print(myRawString)

main()