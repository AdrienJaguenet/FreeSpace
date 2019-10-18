CXX=g++
CXXOPTIONS=--std=c++17 -g
INCLUDEDIRS=

LD=g++
LDOPTIONS=
SHARED_LDLIBS=-lpthread
CLIENT_LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system $(SHARED_LDLIBS)
SERVER_LDLIBS=$(SHARED_LDLIBS)

CLIENT_TARGET=FreeSpace
SERVER_TARGET=FreeSpace-server
CLIENT_SRC=\
	src/Scene.cpp\
	src/Game.cpp\
	src/Client.cpp\
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
SERVER_SRC=\
	src/Server.cpp\
	src/net/Socket.cpp\
	src/net/ServerSocket.cpp

CLIENT_OBJ=$(CLIENT_SRC:.cpp=.o)
CLIENT_DEP=$(CLIENT_SRC:.cpp=.d)
SERVER_OBJ=$(SERVER_SRC:.cpp=.o)
SERVER_DEP=$(SERVER_SRC:.cpp=.d)

all: $(CLIENT_TARGET) $(SERVER_TARGET)

$(CLIENT_TARGET): $(CLIENT_OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(CLIENT_LDLIBS)

$(SERVER_TARGET): $(SERVER_OBJ)
	$(LD) $^ -o $@ $(LDOPTIONS) $(SERVER_LDLIBS)

-include $(OBJ:.o=.d)

%.o: %.cpp
	$(CXX) -c $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp > $*.d

.PHONY: clean

clean:
	$(RM) -f src/*.o src/*.d $(TARGET)

