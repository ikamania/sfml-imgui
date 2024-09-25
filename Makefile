TARGET=./bin/sfmlgame
CXX=g++ -std=c++11
DEBUG=-g
OPT=-O0
WARN=-Wall
SFML=-lsfml-graphics -lsfml-window -lsfml-system
OPENGL=-lGL
CXXFLAGS=$(DEBUG) $(OPT) $(WARN) $(SFML) $(OPENGL)
LD=g++
OBJS= main.o imgui.o imgui_draw.o imgui-SFML.o imgui_tables.o imgui_widgets.o

all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm -f $(OBJS)

run:
	@$(TARGET)

main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) src/main.cpp -o main.o

imgui.o: src/include/imgui.cpp
	$(CXX) -c $(DEBUG) $(OPT) src/include/imgui.cpp -o imgui.o

imgui_draw.o: src/include/imgui_draw.cpp
	$(CXX) -c $(DEBUG) $(OPT) src/include/imgui_draw.cpp -o imgui_draw.o

imgui-SFML.o: src/include/imgui-SFML.cpp
	$(CXX) -c $(DEBUG) $(OPT) src/include/imgui-SFML.cpp -o imgui-SFML.o

imgui_tables.o: src/include/imgui_tables.cpp
	$(CXX) -c $(DEBUG) $(OPT) src/include/imgui_tables.cpp -o imgui_tables.o

imgui_widgets.o: src/include/imgui_widgets.cpp
	$(CXX) -c $(DEBUG) $(OPT) src/include/imgui_widgets.cpp -o imgui_widgets.o

clean:
	rm -f $(OBJS) $(TARGET_PATH)
