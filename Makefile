INC_DIRECOTRY=src -I src/util -I src/projection
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

CPPC=g++ -std=c++11 -g

OBJECT_FILES=obj/main.o obj/FunctionGrapher.o obj/Projector.o obj/Vector2D.o

FunctionGrapher.out: $(OBJECT_FILES)
	$(CPPC) $(OBJECT_FILES) -o bin/FunctionGrapher.out $(LIBS)

obj/main.o: main.cpp
	$(CPPC) -c main.cpp -I $(INC_DIRECOTRY) -o obj/main.o

obj/FunctionGrapher.o: src/FunctionGrapher.h src/FunctionGrapher.cpp
	$(CPPC) -c src/FunctionGrapher.cpp -I $(INC_DIRECOTRY) -o obj/FunctionGrapher.o

obj/Projector.o: src/projection/Projector.h src/projection/Projector.cpp
	$(CPPC) -c src/projection/Projector.cpp -I $(INC_DIRECOTRY) -o obj/Projector.o

obj/Vector2D.o: src/util/Vector2D.h src/util/Vector2D.cpp
	$(CPPC) -c src/util/Vector2D.cpp -I $(INC_DIRECOTRY) -o obj/Vector2D.o

clean:
	rm obj/*.o bin/FunctionGrapher.out
