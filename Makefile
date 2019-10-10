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
	src/LinearPhysicsComponent.cpp\
	src/SpaceInputManager.cpp\
	src/Entity.cpp\
	src/StaticSpriteGraphicsComponent.cpp\
	src/ShipSpriteGraphicsComponent.cpp\
	src/ProjectilePhysicsComponent.cpp\
	src/ProjectileCollisionsComponent.cpp\
	src/CollisionsComponent.cpp\
	src/DestructibleDamageComponent.cpp\
	src/RockDestructionComponent.cpp

OBJ=$(SRC:.cpp=.o)

all: $(TARGET)

%.o: %.cpp
	$(CXX) -c $^ -o $@ $(CXXOPTIONS) $(INCLUDEDIRS)

$(TARGET): $(OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(LDLIBS)


.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJ)

