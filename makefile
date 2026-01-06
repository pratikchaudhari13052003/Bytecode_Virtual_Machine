# Compiler settings
CXX = g++
# -Isrc tells the compiler to look for header files (bvm.h) in the src folder
CXXFLAGS = -Wall -g -Isrc

# Define the Source Directory
SRC = src

# Targets
all: vm assembler

# 1. Compile VM
# We tell make to look for files inside $(SRC)/...
vm: $(SRC)/bvm_main.cpp $(SRC)/bvm.cpp
	$(CXX) $(CXXFLAGS) -o vm $(SRC)/bvm_main.cpp $(SRC)/bvm.cpp

# 2. Compile Assembler
assembler: $(SRC)/assembly_line.cpp $(SRC)/bvm_assemble_line.cpp
	$(CXX) $(CXXFLAGS) -o assembler $(SRC)/assembly_line.cpp $(SRC)/bvm_assemble_line.cpp

run: all
	
	./$(BIN_DIR)/assembler tests/area.asm area.bin
	
	./$(BIN_DIR)/vm area.bin

clean:
	rm -f vm assembler