package main

import "core:fmt"
import "core:math"
import "core:mem"
import "core:math/rand"

import time "core:time"



main :: proc() {
	  ROWS :: 2000
    COLS :: 1000

	//lets make arrays
	matrixA := make([][]f32, ROWS)
	for i in 0..<ROWS{
		matrixA[i] = make([]f32, COLS)
	}
	matrixB := make([][]f32, ROWS)
	for i in 0..<ROWS{
		matrixB[i] = make([]f32, COLS)
	}
	matrixC := make([][]f32, ROWS)
	for i in 0..<ROWS{
		matrixC[i] = make([]f32, COLS)
	}
	defer delete(matrixA)
	defer for row in matrixA {
      delete(row)
    }
	defer delete(matrixB)
	defer for row in matrixB {
      delete(row)
	}
	defer delete(matrixC)
	defer for row in matrixC {
      delete(row)
  }

	fmt.println("Filling matricies")
	fillMatrix(matrixA)
	fillMatrix(matrixB)
	fmt.println("Filled matrix A/B, ready for multiplication")
	matrixMultiplySerial(matrixA, matrixB, matrixC)
	
}


fillMatrix :: proc(mat: [][]f32){
    // We can get the dimensions from the slices themselves
    rows := len(mat)
    if rows == 0 {
        return // Nothing to do
    }
    cols := len(mat[0]) // Assume all rows have the same number of columns

    // Loop through and fill the data
    for r in 0..<rows {
        for c in 0..<cols {
            // Fill with a value based on its position, e.g., r.c
            mat[r][c] = rand.float32_range(1.0,99.9)
        }
    }
}

matrixMultiplySerial ::proc(matA:  [][]f32, matB:  [][]f32, matC: [][]f32){

	fmt.println("matrix multiply serial begin")
	//only since we know all have same rows / cols
	rows := len(matA)
	cols := len(matA[0])

	//timing
	start_tick := time.tick_now()
	for i in 0..<rows {
		for j in 0..<cols {
			for k in 0..<cols {
				matC[i][j] += matA[i][k] * matB[k][j]
			}
		}
	}
	duration := time.tick_since(start_tick)
	t := f32(time.duration_seconds(duration))
	fmt.println("Time Serial: ", t)

	

}
