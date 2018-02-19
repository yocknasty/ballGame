game: game.o Textures.o
	@echo "***Creating Executable*****"
	g++ game.o -o game -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
	@ls

game.o: game.cpp game.h
	@echo "***Compiling game.cpp***"
	g++ -c game.cpp -std=c++11

Textures.o: Textures.cpp Textures.h
	@echo "****adding Textures*****"
	g++ -c Textures.cpp -std=c++11

clean: 
	@echo "*****Clearing game*****"
	rm -rf *.o game
	@ls
	