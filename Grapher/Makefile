INC_DIRECOTRY=src -I src/util -I src/util/vectors -I src/rendering -I src/rendering/objects -I src/functionGrapher -I src/functionGrapher/function -I ../Expression
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

CPPC=g++ -std=c++11 -g

OBJECT_FILES=obj/main.o obj/FunctionGrapher.o obj/Projector.o obj/Vector2D.o obj/Vector3D.o obj/Camera.o obj/Function.o

FunctionGrapher.out: $(OBJECT_FILES)
	$(CPPC) $(OBJECT_FILES) -o bin/FunctionGrapher.out $(LIBS)

obj/main.o: main.cpp
	$(CPPC) -c main.cpp -I $(INC_DIRECOTRY) -o obj/main.o

obj/FunctionGrapher.o: src/functionGrapher/FunctionGrapher.h src/functionGrapher/FunctionGrapher.cpp
	$(CPPC) -c src/functionGrapher/FunctionGrapher.cpp -I $(INC_DIRECOTRY) -o obj/FunctionGrapher.o

obj/Projector.o: src/rendering/Projector.h src/rendering/Projector.cpp
	$(CPPC) -c src/rendering/Projector.cpp -I $(INC_DIRECOTRY) -o obj/Projector.o

obj/Vector2D.o: src/util/vectors/Vector2D.h src/util/vectors/Vector2D.cpp
	$(CPPC) -c src/util/vectors/Vector2D.cpp -I $(INC_DIRECOTRY) -o obj/Vector2D.o

obj/Vector3D.o: src/util/vectors/Vector3D.h src/util/vectors/Vector3D.cpp
	$(CPPC) -c src/util/vectors/Vector3D.cpp -I $(INC_DIRECOTRY) -o obj/Vector3D.o

obj/Camera.o: src/rendering/Camera.h src/rendering/Camera.cpp
	$(CPPC) -c src/rendering/Camera.cpp -I $(INC_DIRECOTRY) -o obj/Camera.o

obj/Function.o: src/functionGrapher/function/Function.h ../Expression/Expression.h src/functionGrapher/function/Function.cpp
	$(CPPC) -c src/functionGrapher/function/Function.cpp -I $(INC_DIRECOTRY) -o obj/Function.o

clean:
	rm obj/*.o bin/FunctionGrapher.out
