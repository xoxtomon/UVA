from collections import deque
from sys import stdin

index = 0
case = 1
myString = stdin.readlines()

while index < len(myString):
    myCase = myString[index].strip('\n').split()
    myPopulation = int(myCase[0])
    myIteration = int(myCase[1])
    myDeque = deque()

    if myPopulation == 0 and myIteration == 0:
        break
    

    for num in range(min(myPopulation, 1000)):
        myDeque.append(num+1)
    
    print(f'Case {case}:')
    
    #print(myCase)
    mySeries = myString[index+1:index+1+myIteration]
    
    for i in mySeries:
        myPatient = i.strip('\n').split()
        #print(caso)
        if len(myPatient) > 1:
            # Lógica para E 
            myDeque.appendleft(int(myPatient[1]))
            #myDeque.remove(int(myPatient[1]))
            for i in range(len(myDeque)-1):
                if myDeque[i+1] == int(myPatient[1]):
                    del myDeque[i+1]
                    break
        else:
            # Lógica para N
            print(myDeque[0])
            myDeque.append(myDeque[0])
            myDeque.popleft()
            

    """print(myDeque)
    myDeque.remove(myIteration)
    print(myDeque)"""
    
    #index += myIteration + 1
    index += myIteration + 1
    case += 1