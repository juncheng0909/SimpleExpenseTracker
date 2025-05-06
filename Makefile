CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall
SRC = src/main.cpp src/Account.cpp src/Transaction.cpp
TARGET = expense_tracker

all:
	$(CXX) $(SRC) $(CXXFLAGS) -o $(TARGET)

clean:
	del $(TARGET).exe 2>nul
