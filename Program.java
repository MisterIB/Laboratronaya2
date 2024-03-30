package Прога.лаба2.Laboratronaya2;

import java.util.*;
public class Program{
    public static void main(String[] args){
        //NumberThree();
		//NumberTwo();
		NumberOne();
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
	static void NumberTwo() {
		Scanner in = new Scanner(System.in);
		System.out.println("Введите строку");
		String TextLine = in.next();
		Map<Integer, String> ColorsRings = new HashMap<Integer, String>();
		Set<Integer> Kernels = new HashSet<Integer>();
		for (int i = 1; i < TextLine.length(); i = i + 2) {
			ColorsRings.put(TextLine.charAt(i) - '0', "");
			Kernels.add(TextLine.charAt(i)-'0');
	
		}
		for (int i = 1; i < TextLine.length(); i = i + 2) {
			ColorsRings.put(TextLine.charAt(i) - '0', ColorsRings.get(TextLine.charAt(i) - '0') + TextLine.charAt(i-1));
		}
		int count = 0;
		for (int Kernel: Kernels){
			if (ColorsRings.get(Kernel).contains("R") & ColorsRings.get(Kernel).contains("W") & ColorsRings.get(Kernel).contains("B")) count += 1;
		}
		System.out.printf("%d", count);
	}
	static void NumberOne() {
		Scanner in = new Scanner(System.in);
		Vector<Integer> Birds = new Vector<Integer>();
		System.out.println("Введите дальность полета каждой птицы, чтобы перейти к следющему шагу введите 0");
		while (true){
			int FlightRange = in.nextInt();
			if (FlightRange == 0) break;
			Birds.add(FlightRange);
			FlightRange = 0;
		}
		System.out.println("Введите количество валунов");
		int AmountOfStones = in.nextInt();
		Vector<Integer> Stones = new Vector<Integer>();
		for (int i = 1;i <= AmountOfStones;i++) {
			Stones.add(i);
		}
		Set<Integer> Result = new HashSet<Integer>();
		int IsLndngOnAllStone = 0;
		for (int Stone: Stones) {
			int IsLndngOnStone = 0;
			for (int Bird : Birds) {
				if (Bird == 1) IsLndngOnAllStone = 1;
				if (Stone % Bird == 0) IsLndngOnStone = 1;
			}
			if (IsLndngOnStone == 0) Result.add(Stone);
		}
		for (int Stone : Result) {
			System.out.printf("%d ", Stone);
		}
		if (IsLndngOnAllStone == 1) System.out.println("Птицы сядут на каждый камень");
	}
}