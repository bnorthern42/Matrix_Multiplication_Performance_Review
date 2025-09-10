# Makefile for compiling Serial, Parallel (OpenMP), and Distributed (OpenMPI) versions.
#
# Author: Gemini only vibe code on ths repo is makefiles
# C++ Standard: C++17
# Optimization: None (-O flags are intentionally omitted)
#
# --- Prerequisites ---
# For Linux:
#   - A C++ compiler (g++)
#   - OpenMP support (usually included with g++)
#   - An OpenMPI implementation (e.g., install via 'sudo apt-get install openmpi-bin libopenmpi-dev')
#
# For Windows:
#   This Makefile is designed for a GNU Make environment. The easiest way to use it on
#   Windows is through:
#   1. WSL (Windows Subsystem for Linux): Recommended. Install a Linux distro and the prerequisites above.
#   2. MinGW-w64 with MSYS2: You will need to install g++, make, and the OpenMPI library through the pacman package manager.
#

# --- Compiler Definitions ---
# Standard C++ compiler
CXX = g++
# MPI C++ compiler wrapper. This is the standard way to compile MPI code.
MPICXX = mpic++

# --- Flags ---
# CXXFLAGS: Flags for all C++ compilations.
# -std=c++17 : Enforce C++17 standard
# -Wall      : Enable all common warnings (good practice)
CXXFLAGS = -std=c++17 -Wall

# OPENMP_FLAGS: Flags required for OpenMP.
# -fopenmp : Tells the compiler to enable OpenMP support.
OPENMP_FLAGS = -fopenmp

# --- Target Executables ---
SERIAL_EXEC = seriale
PARALLEL_EXEC = parallele
DISTRIBUTED_EXEC = distributede

# --- Source Files ---
SERIAL_SRC = serial.cpp
PARALLEL_SRC = parallel.cpp
DISTRIBUTED_SRC = distributed.cpp


# --- Build Rules ---

# The 'all' target is the default. Running 'make' will build all three executables.
all: $(SERIAL_EXEC) $(PARALLEL_EXEC) $(DISTRIBUTED_EXEC)

# Rule to build the serial executable
$(SERIAL_EXEC): $(SERIAL_SRC)
	@echo "Compiling serial version..."
	$(CXX) $(CXXFLAGS) -o $(SERIAL_EXEC) $(SERIAL_SRC)
	@echo "Serial executable '$(SERIAL_EXEC)' created."
	@echo ""

# Rule to build the parallel executable with OpenMP
$(PARALLEL_EXEC): $(PARALLEL_SRC)
	@echo "Compiling parallel version with OpenMP..."
	$(CXX) $(CXXFLAGS) $(OPENMP_FLAGS) -o $(PARALLEL_EXEC) $(PARALLEL_SRC)
	@echo "Parallel executable '$(PARALLEL_EXEC)' created."
	@echo ""

# Rule to build the distributed executable with OpenMPI
$(DISTRIBUTED_EXEC): $(DISTRIBUTED_SRC)
	@echo "Compiling distributed version with OpenMPI..."
	$(MPICXX) $(CXXFLAGS) -o $(DISTRIBUTED_EXEC) $(DISTRIBUTED_SRC)
	@echo "Distributed executable '$(DISTRIBUTED_EXEC)' created."
	@echo ""


# --- Phony Targets ---
# These targets are not files. 'make clean' removes generated files.
# The executable names are also phony so you can type 'make serial' to force a rebuild.
.PHONY: all clean serial parallel distributed

# Add the individual build commands to the phony targets list
serial: $(SERIAL_EXEC)
parallel: $(PARALLEL_EXEC)
distributed: $(DISTRIBUTED_EXEC)

# Clean up the project directory
clean:
	@echo "Cleaning up compiled files..."
	rm -f $(SERIAL_EXEC) $(PARALLEL_EXEC) $(DISTRIBUTED_EXEC)
	@echo "Cleanup complete."
