# --- Compiler Settings ---
CXX      = g++
# -Isrc tells the compiler to look in the 'src' folder for header files like bvm.h
CXXFLAGS = -Wall -g -Isrc

# --- Directories ---
SRC_DIR   = src
BUILD_DIR = build
BIN_DIR   = bin

# --- File Lists ---
# We define the specific filenames (without extension) for each program
ASM_NAMES = assembly_line bvm_emit bvm_assemble_line
VM_NAMES  = bvm bvm_run bvm_stack_operation bvm_initialise

# Convert names to full paths: src/filename.cpp
# AND convert them to object paths: build/filename.o
ASM_OBJS = $(patsubst %, $(BUILD_DIR)/%.o, $(ASM_NAMES))
VM_OBJS  = $(patsubst %, $(BUILD_DIR)/%.o, $(VM_NAMES))

# --- Main Targets ---
all: directories assembler vm

# Ensure the output directories exist before compiling
directories:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# --- 1. Assembler Build ---
assembler: $(ASM_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/assembler $(ASM_OBJS)

# --- 2. VM Build ---
vm: $(VM_OBJS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/vm $(VM_OBJS)

# --- 3. Generic Compilation Rule ---
# This says: "To make build/X.o, look for src/X.cpp"
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/bvm.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# --- 4. Test / Run ---
run: all
	
	./$(BIN_DIR)/assembler tests/area.asm area.bin
	
	./$(BIN_DIR)/vm area.bin

# --- 5. Clean ---
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR) *.bin