RM=rm

CXX=g++
CXXOPTIONS=--std=c++17 -g
INCLUDEDIRS=

LD=g++
LDOPTIONS=
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

TARGET=FreeSpace
SRC=src/game.cpp src/main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXOPTIONS) $(INCLUDEDIRS)

$(TARGET): $(OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(LDLIBS)


.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJ)

