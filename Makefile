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
DEP=$(SRC:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(LDLIBS)

.PHONY: all clean

clean:
	$(RM) src/*.o src/*.d $(TARGET)

-include $(DEP)

%.o: %.cpp Makefile
	$(CXX) $(CXXOPTIONS) $(INCLUDEDIRS) -MMD -MP -c $< -o $@
