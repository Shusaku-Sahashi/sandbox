package main

import (
	"fmt"
	"syscall"
)

func main() {
	var fileStat syscall.Stat_t

	if err := syscall.Lstat("./main.go", &fileStat); err != nil {
		panic(err)
	}

	if fileStat.Mode&syscall.S_IFMT == syscall.S_IFREG {
		fmt.Print("種類: ファイル")
	}
}
