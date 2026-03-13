# 编译器
CXX = g++

# 编译参数
CXXFLAGS = -std=c++17 -Iinclude -Wall

# 源文件目录
SRC_DIR = src

# build目录
BUILD_DIR = build

# 可执行文件
TARGET = life_sim

# 自动找到所有cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# 生成对应的.o文件
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 编译cpp -> o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# 运行
run: all
	./$(TARGET)