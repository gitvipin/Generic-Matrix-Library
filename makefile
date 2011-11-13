CC:= g++
DEL:= rm 
CFLAGS:= -O3 -c -g 
LFLAGS:= -o

run : matrix.o main.o
	$(CC) $(LFLAGS) run matrix.o main.o 

main.o: main.cpp common.h matrix.h
	$(CC) $(CFLAGS) main.cpp

matrix.o: matrix.cpp matrix.h common.h
	$(CC) $(CFLAGS) matrix.cpp 

clean: 
	$(DEL) main.o matrix.o run 
	
