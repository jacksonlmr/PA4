battleship: main.o boat.o opponentBoard.o playerBoard.o
	g++ -o battleship main.o boat.o opponentBoard.o playerBoard.o

main.o: main.cpp opponentBoard.h playerBoard.h boat.h
	g++ -c main.cpp

boat.o: boat.cpp boat.h
	g++ -c boat.cpp

opponentBoard.o: opponentBoard.cpp opponentBoard.h
	g++ -c opponentBoard.cpp

playerBoard.o: playerBoard.cpp playerBoard.h opponentBoard.h boat.h
	g++ -c playerBoard.cpp

clean:
	rm *.o battleship
