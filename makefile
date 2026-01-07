# Compiler settings
CXX = g++
CXXFLAGS = -Wall -g -Isrc

# Define the Source Directory
SRC = src

# Targets
all: vm assembler benchmark

# 1. Compile VM
vm: $(SRC)/vm/bvm_main.cpp $(SRC)/vm/bvm.cpp
	$(CXX) $(CXXFLAGS) -o vm $(SRC)/vm/bvm_main.cpp $(SRC)/vm/bvm.cpp

# 2. Compile Assembler
# We tell make to look for files inside $(SRC)/...
assembler: $(SRC)/assembler/assembly_main.cpp $(SRC)/assembler/assembler.cpp
	$(CXX) $(CXXFLAGS) -o assembler $(SRC)/assembler/assembly_main.cpp $(SRC)/assembler/assembler.cpp

# 3. Compile Benchmark Tool
# links benchmark_main with bvm.cpp (for VM) and assembler.cpp (for assembling on fly)
benchmark: $(SRC)/benchmark_main.cpp $(SRC)/vm/bvm.cpp $(SRC)/assembler/assembler.cpp
	$(CXX) $(CXXFLAGS) -o benchmark $(SRC)/benchmark_main.cpp $(SRC)/vm/bvm.cpp $(SRC)/assembler/assembler.cpp

run: all
	./assembler tests/area.asm area.bin
	./vm area.bin

# New target to run benchmarks
test: benchmark
	./benchmark

clean:
	rm -f vm assembler benchmark *.bin