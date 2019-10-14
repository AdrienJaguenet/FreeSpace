RM=rm

CXX=g++
CXXOPTIONS=--std=c++17 -g
INCLUDEDIRS=

LD=g++
LDOPTIONS=
LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system

TARGET=FreeSpace
SRC=\
	src/Scene.cpp\
	src/Game.cpp\
	src/Main.cpp\
	src/Space.cpp\
	src/SpaceInputManager.cpp\
	src/Entity.cpp\
	src/GraphicsSystem.cpp\
	src/PhysicsSystem.cpp\
	src/InputSystem.cpp\
	src/ResourceCollectSystem.cpp\
	src/AISystem.cpp

OBJ=$(SRC:.cpp=.o)
DEP = $(SRC:.cpp=.d)

all: $(TARGET)

%.o: %.cpp
	$(CXX) -MMD -c $^ -o $@ $(CXXOPTIONS) $(INCLUDEDIRS)

$(TARGET): $(OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(LDLIBS)


.PHONY: clean

clean:
	$(RM) src/*.o src/*.d $(TARGET)

-include $(DEP)
