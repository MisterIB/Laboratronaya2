package Прога.лаба2.Laboratronaya2;

import java.util.Scanner;
public class Program{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        NumberThree();
    }
    static void NumberThree() {
        Scanner in = new Scanner(System.in);
    	System.out.println("Введите количество чисел");
        int AmountOfNumbers = in.nextInt();
	    System.out.println("Введите числа");
	    int Sum = 0;
	    for (int i = 0; i < AmountOfNumbers; i++) {
			int Number = in.nextInt();
			Sum = Sum + SumNumDivThree(Number);
		}
	    System.out.printf("Sum = %d", Sum);
    }
    static int SumNumDivThree(int Number) {
        int Sum = 0;
	    for (; Number > 0; Number = Number / 10) {
		    int Figure = Number % 10;
		    if (Figure % 3 == 0) Sum = Sum + Figure;
	    }
	    return Sum;
    }
}