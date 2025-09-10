# **Matrix Multiplication Performance Review**

A comprehensive project for benchmarking the performance of matrix multiplication across various programming languages and execution models. This repository explores the computational differences between serial, parallel (shared memory), and distributed (non-shared memory) approaches.

## **🚀 Project Goal**

The primary objective of this project is to quantitatively measure and compare the efficiency of different programming languages and paradigms for a CPU-intensive task: matrix multiplication. By implementing the same core logic in multiple environments, we aim to answer questions like:

* How much performance is gained when moving from a serial to a parallel implementation?  
* What is the overhead and performance benefit of using a distributed system for this task?  
* How do modern languages like Go and Odin compare against established languages like C++ in terms of performance and implementation complexity?  


## **🛠️ Implementations**

The core matrix multiplication algorithm is implemented in three distinct models to test different computational environments.

### **1\. Serial (Single-Threaded)**

This is the most straightforward implementation, using a single thread of execution to perform the multiplication. It serves as the baseline for all performance comparisons.

* **Logic:** Standard three-loop (i, j, k) matrix multiplication.  
* **Purpose:** Establish baseline performance for each language.

### **2\. Parallel (Shared Memory)**

This implementation leverages multi-core processor architectures by dividing the matrix multiplication workload across multiple threads on a single machine.

* **Technology:** Utilizes threading libraries native(ish) to each language (e.g., openMP in C++, Goroutines in Go).  
* **Purpose:** Measure speed-up and efficiency of shared-memory parallelism.

### **3\. Distributed (Non-Shared Memory)**

This model is designed for a multi-machine or cluster environment. The workload is distributed among different processes that may be running on separate nodes, communicating over a network.

* **Technology:** Employs frameworks or libraries for message passing (e.g., MPI \- Message Passing Interface).  
* **Purpose:** Analyze the performance, scalability, and communication overhead of distributed computing for this task.

## **💻 Languages & Technologies**

This project is currently implemented in C++, with plans to expand to other languages. The following table details the current status:

| Language | Serial | Parallel (Shared Memory) | Distributed Memory |
| :---- | :---- | :---- | :---- |
| **C++** | ✅ | OpenMP ✅ | OpenMPI  |

## **⚙️ How to Run**

Each language and implementation has its own directory. To build and run a specific test, navigate to the respective folder and follow the instructions in the README.md file contained within it.  
A general example for running the C++ serial version:  
\# Navigate to the C++ serial implementation directory  
cd cpp

\# Compile the source code (example using g++)  
make serial


\# Run the executable  
./seriale

Refer to the scripts directory for automated build and test scripts that can be used to run all benchmarks systematically.

## **📊 Performance Results**


The results of the performance benchmarks will be compiled and analyzed here. Key metrics to be included are (curently in cpp dir for cpp):

* Execution time vs. language 
* Speed-up factor for parallel and distributed versions relative to the serial baseline.  


**Example Chart:**  
*(Consider adding plots and tables summarizing your benchmark results for easy comparison.)*

## **Contributing**

Contributions and suggestions are welcome\! If you'd like to add an implementation in a new language or improve an existing one, please feel free to fork the repository and submit a pull request.

1. Fork the Project  
2. Create your Feature Branch (git checkout \-b feature/NewLanguage)  
3. Commit your Changes (git commit \-m 'Add some NewLanguage')  
4. Push to the Branch (git push origin feature/NewLanguage)  
5. Open a Pull Request

## **License**

Distributed under the MIT License. See LICENSE for more information.  
