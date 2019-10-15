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
	src/AISystem.cpp\
	src/WeaponSystem.cpp\
	src/ProjectileSystem.cpp
OBJ=$(SRC:.cpp=.o)
DEP=$(SRC:.cpp=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(LDLIBS)

-include $(OBJ:.o=.d)

%.o: %.cpp
	$(CXX) -c $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp > $*.d

.PHONY: clean

clean:
	$(RM) -f src/*.o src/*.d $(TARGET)

