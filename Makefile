# 编译器
CXX = g++

# SDL参数
SDL_CFLAGS := $(shell sdl2-config --cflags)
SDL_LIBS := $(shell sdl2-config --libs) -lSDL2_ttf

# 编译参数
CXXFLAGS = -std=c++17 -Iinclude -Wall $(SDL_CFLAGS)

# 源文件目录
SRC_DIR = src

# build目录
BUILD_DIR = build

# 可执行文件
TARGET = life_sim

# 自动找到所有cpp
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
#SRCS = src/game.cpp src/world.cpp src/renderer.cpp src/simulation.cpp src/text.cpp src/ui.cpp src/agent.cpp src/location.cpp

# 生成对应的.o文件
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# 默认目标
all: $(TARGET)

# 链接
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(SDL_LIBS)

# 编译cpp -> o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	rm -f datasets/*

# 运行
run: all
	./$(TARGET)