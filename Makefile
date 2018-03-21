EXE = folds
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
#$(shell find $(SRC_DIR) -name '*.cpp' | sort -k 1nr | cut -f2-)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
CFLAGS = -I$(INC_DIR) -c
CC = g++

all: $(BUILD_DIR)/$(EXE)

$(BUILD_DIR)/$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/$(EXE)*