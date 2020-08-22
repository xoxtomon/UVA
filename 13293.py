from sys import stdin

def main():
    myString = stdin.readlines()

    index = 0
    case = 1
    while index < len(myString):
        print(f'Case {case}:')
        myString[index].strip("\n")
        myInt = int(myString[index])

        mySeries = myString[index+1:index+myInt+1]
        myList = []

        for player in mySeries:
            aux = player.split(';')
            name = aux[0]
            points = int()
            
            for i in aux[1:]:
                points += int(i[0]) + int(i[2]) + int(i[4]) + int(i[6]) + (int(i[8]) * 2)

            #myPlayer = Jugador(name, points)
            myPlayer = (name,points)
            myList.append(myPlayer)
        
        myList.sort(key=lambda x: (-x[1], x[0].lower()))

        for player in myList:
            print(f'{player[0]} {player[1]}')
            #print(f'{player.name} {player.points}')

        index += myInt + 1
        case += 1


main()
"""
def compare(first, second):
    if(first.point != second.point):
        return first.point > second.point
    else:
        x = first.name.lower()
        y = second.name.lower()
        return x < y"""