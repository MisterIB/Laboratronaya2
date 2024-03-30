def SumNumDivThree(Number):
    Sum = 0
    while (Number > 0):
        Figure = int(Number % 10)
        if (Figure % 3 == 0):
            Sum = Sum + Figure
        Number = Number // 10
    return Sum
def NumberThree():
    print("Введите количество чисел")
    AmountOfNumbers = int(input())
    print("Введите числа")
    Sum = 0
    for i in range(AmountOfNumbers):
        Number = int(input())
        Sum = Sum + SumNumDivThree(Number)
    print(Sum)
def NumberTwo():
    print("Введите строку")
    TextLine = input()
    ColorsRings = {}
    Kernels = []
    for i in range(1, len(TextLine), 2):
        ColorsRings[TextLine[i]] = ""
        if TextLine[i] not in Kernels:
            Kernels.append(TextLine[i])

    for i in range(1, len(TextLine), 2):
        ColorsRings[TextLine[i]] = ColorsRings[TextLine[i]] + TextLine[i-1]
    count = 0
    for i in Kernels:
        if (('R' in ColorsRings[i]) and ('W' in ColorsRings[i]) and ('B' in ColorsRings[i])):
            count = count + 1
    print(count)
def NumberOne():
    Birds = []
    print("Введите дальность полета каждой птицы, чтобы перейти к следющему шагу введите 0")
    while (1):
        FlightRange = int(input())
        if (FlightRange == 0):
            break
        Birds.append(FlightRange)
    print("Введите количество валунов")
    AmountOfStones = int(input())
    Stones = []
    for i in range(1, AmountOfStones + 1):
        Stones.append(i)
    Result = [] #set
    IsLndngOnAllStone = 0
    for Stone in Stones:
        IsLndngOnStone = 0
        for Bird in Birds:
            if (Bird == 1):
                IsLndngOnAllStone = 1
            if (Stone % Bird == 0):
                IsLndngOnStone = 1
        if (IsLndngOnStone == 0 and Stone not in Result):
            Result.append(Stone)

    for Stone in Result:
        print(Stone)
    if (IsLndngOnAllStone == 1):
        print("Птицы сядут на каждый камень")

print("Выберите номер задания")
TaskNumber = int(input())
match TaskNumber:
    case 1:
        NumberOne()
    case 2:
        NumberTwo()3
    case 3:
        NumberThree()
