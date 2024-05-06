battleship: main.o opponentBoard.o playerBoard.o boat.o
	g++ -o battleship main.o opponentBoard.o playerBoard.o boat.o

main.o: main.cpp opponentBoard.h playerBoard.h boat.h
	g++ -c main.cpp

opponentBoard.o: opponentBoard.cpp opponentBoard.h
	g++ -c opponentBoard.cpp

playerBoard.o: playerBoard.cpp playerBoard.h
	g++ -c playerBoard.cpp

boat.o: boat.cpp boat.h
	g++ -c boat.cpp

clean:
	rm *.o battleship