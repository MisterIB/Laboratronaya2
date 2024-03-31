import java.util.*
import kotlin.collections.HashSet
import java.util.Vector
fun SumNumDivThree(Number: Int): Int{
    var Sum: Int = 0
    var Num: Int = Number
    while(Num > 0) {
        var Figure: Int = Num % 10
        if (Figure % 3 == 0) Sum = Sum + Figure
        Num = Num / 10
    }
    return Sum
}

fun NumberThree() {
    val scan = Scanner(System.`in`)
    println("Введите количество чисел")
    var AmountOfNumbers: Int = scan.nextInt()
    println("Введите числа")
    var Sum: Int = 0
    for (i in 1..AmountOfNumbers) {
        var Number: Int = scan.nextInt()
        Sum = Sum + SumNumDivThree(Number)
    }
    println("$Sum")
}
fun NumberTwo() {
    val scan = Scanner(System.`in`)
    println("Введите строку")
    var TextLine: String = scan.next()
    val ColorsRings = HashMap<Int, String>()
    val Kernels = HashSet<Int>()
    for (i in 1..TextLine.length step 2) {
        ColorsRings[TextLine[i] - '0'] = ""
        Kernels.add(TextLine[i] - '0')
    }
    for (i in 1..TextLine.length step 2) {
        ColorsRings[TextLine[i] - '0'] = ColorsRings[TextLine[i] - '0'] + TextLine[i-1]
    }
    var count: Int = 0
    for (Kernel in Kernels){
        if ((ColorsRings[Kernel]!!.contains('R', true) and ColorsRings[Kernel]!!.contains('W') and ColorsRings[Kernel]!!.contains('B'))) count = count + 1
    }
    println("$count")
}
fun NumberOne() {
    val scan = Scanner(System.`in`)
    var Birds = Vector<Int>()
    println("Введите дальность полета каждой птицы, чтобы перейти к следющему шагу введите 0")
    while (true){
        var FlightRange: Int = scan.nextInt()
        if (FlightRange == 0) break
        Birds.add(FlightRange)
        FlightRange = 0
    }
    println("Введите количество валунов")
    var AmountOfStones: Int = scan.nextInt()
    var Stones = Vector<Int>()
    for(i in 1..AmountOfStones){
        Stones.add(i);
    }
    val Result = HashSet<Int>()
    var IsLndngOnAllStone: Int = 0
    for (Stone in Stones) {
        var IsLndngOnStone: Int = 0
        for (Bird in Birds) {
        if (Bird == 1) IsLndngOnAllStone = 1
        if (Stone % Bird == 0) IsLndngOnStone = 1
    }
        if (IsLndngOnStone == 0) Result.add(Stone)
    }
    for (Stone in Result) {
        println("$Stone ")
    }
    if (IsLndngOnAllStone == 1) println("Птицы сядут на каждый камень")
}
fun main(){
    //NumberThree()
    //NumberTwo()
    NumberOne()
}