battleship: main.o boat.o
	g++ -o battleship main.o boat.o

main.o: main.cpp opponentBoard.h playerBoard.h boat.h
	g++ -c main.cpp

boat.o: boat.cpp boat.h
	g++ -c boat.cpp

clean:
	rm *.o battleship