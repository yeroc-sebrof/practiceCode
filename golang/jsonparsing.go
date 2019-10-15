package main

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	//userreader := bufio.NewReader(os.Stdin)

	//useranswer, _ := userreader.ReadString('\n')
	useranswer := "JSON"

	var dat map[string]map[string]interface{}

	byt, err := ioutil.ReadFile(useranswer)
	if err := json.Unmarshal(byt, &dat); err != nil {
		panic(err)
	}

	//	fmt.Println(reflect.TypeOf(dat["intro"]))
	fmt.Println(dat["intro"]["options"])

	check(err)

}
