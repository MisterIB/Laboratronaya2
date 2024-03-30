import java.util.*
import kotlin.collections.HashSet

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
        ColorsRings[TextLine[i] - '0'] = "";
        Kernels.add(TextLine[i] - '0')

    }
    for (i in 1..TextLine.length step 2) {
        ColorsRings[TextLine[i] - '0'] = ColorsRings[TextLine[i] - '0'] + TextLine[i-1];
    }
    var count: Int = 0
    for (Kernel in Kernels){
        if ((ColorsRings[Kernel]!!.contains('R', true) and ColorsRings[Kernel]!!.contains('W') and ColorsRings[Kernel]!!.contains('B'))) count = count + 1
    }
    println("$count")
}
fun main(){
    //NumberThree()
    NumberTwo()
}