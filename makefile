game: game.o 
	@echo "***Creating Executable*****"
	g++ game.o -o game -lsfml-graphics -lsfml-window -lsfml-system

game.o: game.cpp game.h
	@echo "***compiling game.cpp***"
	g++ -c game.cpp 

clean: 
	@echo "*****Cleaning game*****"
	rm -rf *.o game
	@ls -l
	