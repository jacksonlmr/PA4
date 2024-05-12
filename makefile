battleship: main.o boat.o opponentBoard.o playerBoard.o human.o ai.o player.o helpers.o
	g++ -o battleship main.o boat.o opponentBoard.o playerBoard.o human.o ai.o player.o helpers.o

main.o: main.cpp opponentBoard.h playerBoard.h boat.h human.h ai.h player.h helpers.h
	g++ -c main.cpp

boat.o: boat.cpp boat.h
	g++ -c boat.cpp

opponentBoard.o: opponentBoard.cpp opponentBoard.h
	g++ -c opponentBoard.cpp

playerBoard.o: playerBoard.cpp playerBoard.h opponentBoard.h boat.h
	g++ -c playerBoard.cpp

human.o: human.cpp human.h player.h boat.h helpers.h
	g++ -c human.cpp

ai.o: ai.cpp ai.h player.h boat.h helpers.h
	g++ -c ai.cpp

player.o: player.cpp player.h boat.h helpers.h
	g++ -c player.cpp 

helpers.o: helpers.cpp helpers.h 
	g++ -c helpers.cpp 

clean:
	rm *.o battleship

