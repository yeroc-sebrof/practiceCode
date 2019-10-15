package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"io"
	"os"
)

// type QNA struct {
// 	question string
// 	answer   int
// }

func main() {

	quizfile, _ := os.Open("quiz.csv")
	quizreader := csv.NewReader(bufio.NewReader(quizfile))

	var QNA [][]string

	for {
		line, error := quizreader.Read()

		if error == io.EOF {
			fmt.Println("Quiz loaded\n")
			break

		} else if error != nil {
			fmt.Println("An Unexpected error occured:")
			fmt.Println(error)
		}

		QNA = append(QNA, line)
	}

	userreader := bufio.NewReader(os.Stdin)

	for i := 0; i < len(QNA); i++ {
		fmt.Println(QNA[i][0], "= ")

		useranswer, _ := userreader.ReadString('\n')

		if QNA[i][1][0:] == useranswer {
			fmt.Println("Correct")
		} else {
			fmt.Print("Incorrect, ", useranswer) // Why you pushing a new line
			fmt.Println("isnt equal to ", QNA[i][1])

			fmt.Print("Debug")
			fmt.Println(len(QNA[i][1]))
			fmt.Println(len(useranswer))

		}
	}

	fmt.Println()
}
