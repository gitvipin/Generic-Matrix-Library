CC:= g++
DEL:= rm 
CFLAGS:= -O3 -c -g 
LFLAGS:= -o

run : matrix.o main.o error.o
	$(CC) $(LFLAGS) run matrix.o main.o error.o

main.o: main.cpp common.h matrix.h
	$(CC) $(CFLAGS) main.cpp

matrix.o: matrix.cpp matrix.h common.h
	$(CC) $(CFLAGS) matrix.cpp 


error.o: error.cpp error.h
	$(CC) $(CFLAGS) error.cpp

clean: 
	$(DEL) main.o matrix.o run 
	
