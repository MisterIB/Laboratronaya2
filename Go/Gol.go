package Go

import (
	"fmt"
	"os"
	"strings"
)

func SumNumDivThree(Number int) int {
	var Sum int = 0
	for ; Number > 0; Number = Number / 10 {
		var Figure int = Number % 10
		if Figure%3 == 0 {
			Sum = Sum + Figure
		}
	}
	return Sum
}

func NumberThree() {
	fmt.Fprintln(os.Stdout, "Введите количество чисел")
	var AmountOfNumbers int = 0
	fmt.Fscan(os.Stdin, &AmountOfNumbers)
	fmt.Fprintln(os.Stdout, "Введите числа")
	var Sum int = 0
	for i := 0; i < AmountOfNumbers; i++ {
		var Number int = 0
		fmt.Fscan(os.Stdin, &Number)
		Sum = Sum + SumNumDivThree(Number)
	}
	fmt.Fprintln(os.Stdout, Sum)
}

type void struct{}

var member void

func NumberTwo() {
	fmt.Fprintln(os.Stdout, "Введите строку")
	var TextLine string
	fmt.Fscan(os.Stdin, &TextLine)
	var ColorsRings map[byte]string
	var Kernels map[byte]struct{}
	for i := 1; i <= len(TextLine); i = i + 2 {
		ColorsRings = make(map[byte]string)
		ColorsRings[TextLine[i]] = ""
		Kernels = make(map[byte]struct{})
		Kernels[TextLine[i]] = member
	}
	for i := 1; i <= len(TextLine); i = i + 2 {
		ColorsRings[TextLine[i]] = ColorsRings[TextLine[i]] + string(TextLine[i-1])
	}
	var count int = 0
	for Kernel := range Kernels {
		if strings.Contains(ColorsRings[Kernel], "R") && strings.Contains(ColorsRings[Kernel], "W") && strings.Contains(ColorsRings[Kernel], "B") {
			count = count + 1
		}
	}
	fmt.Fprintln(os.Stdout, count)
}
func NumberOne() {
	var Birds []int
	fmt.Fprintln(os.Stdout, "Введите дальность полета каждой птицы, чтобы перейти к следющему шагу введите 0")
	for {
		var FlightRange int
		fmt.Fscan(os.Stdin, &FlightRange)
		if FlightRange == 0 {
			break
		}
		Birds = append(Birds, FlightRange)
	}
	fmt.Fprintln(os.Stdout, "Введите количество валунов")
	var AmountOfStones int
	fmt.Fscan(os.Stdin, &AmountOfStones)
	var Stones []int
	for i := 1; i <= AmountOfStones; i++ {
		Stones = append(Stones, i)
	}
	var Result map[int]struct{}
	var IsLndngOnAllStone int = 0
	for Stone := range Stones {
		var IsLndngOnStone int = 0
		for Bird := range Birds {
			if Bird == 1 {
				IsLndngOnAllStone = 1
			}
			if Stone%Bird == 0 {
				IsLndngOnStone = 1
			}
		}
		if IsLndngOnStone == 0 {
			Result = make(map[int]struct{})
			Result[Stone] = member
		}
	}
	for Stone := range Result {
		fmt.Fprintln(os.Stdout, Stone)
	}
	if IsLndngOnAllStone == 1 {
		fmt.Fprintln(os.Stdout, "Птицы сядут на каждый камень")
	}
}
func main() {
	//NumberThree()
	//NumberTwo()
	NumberOne()
}
