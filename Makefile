CXX=g++
CXXOPTIONS=--std=c++17 -g
INCLUDEDIRS=

LD=g++
LDOPTIONS=-L/usr/local/lib # this is where protobuf is placed
SHARED_LDLIBS=-lpthread -lprotobuf
CLIENT_LDLIBS=-lsfml-graphics -lsfml-window -lsfml-system $(SHARED_LDLIBS)
SERVER_LDLIBS=$(SHARED_LDLIBS)

PROTOBUF_COMPILER=protoc
PROTOBUF_OPTIONS=
PROTOBUF_SRC_DIR=src/net
PROTOBUF_MSG=$(PROTOBUF_SRC_DIR)/BaseMessage.proto
PROTOBUF_GEN=$(PROTOBUF_MSG:.proto=.cpp)

CLIENT_TARGET=FreeSpace
SERVER_TARGET=FreeSpace-server

COMMON_SRC=src/Scene.cpp\
	src/net/Socket.cpp\
	src/PhysicsSystem.cpp\
	$(PROTOBUF_GEN)

CLIENT_SRC=\
	$(COMMON_SRC)\
	src/Space.cpp\
	src/Game.cpp\
	src/Client.cpp\
	src/SpaceInputManager.cpp\
	src/GraphicsSystem.cpp\
	src/InputSystem.cpp\
	src/ClientScene.cpp\
	src/net/ClientSocket.cpp\
	src/Menu.cpp\
	src/MenuInputManager.cpp\

SERVER_SRC=\
	$(COMMON_SRC)\
	src/Server.cpp\
	src/net/ServerSocket.cpp\
	src/ServerScene.cpp\
	src/AISystem.cpp\
	src/ResourceCollectSystem.cpp\
	src/WeaponSystem.cpp\
	src/ProjectileSystem.cpp\

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

$(PROTOBUF_GEN): $(PROTOBUF_MSG)
	$(PROTOBUF_COMPILER) -I=$(PROTOBUF_SRC_DIR) --cpp_out=$(PROTOBUF_SRC_DIR) $^;
	mv $(PROTOBUF_SRC_DIR)/$(basename $(notdir $^)).pb.cc $@;

%.o: %.cpp
	$(CXX) -c $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXOPTIONS) $(INCLUDEDIRS) $*.cpp > $*.d

.PHONY: clean

clean:
	$(RM) -f src/*.o src/*.d $(TARGET) $(PROTOBUF_GEN)

