# ======================
# Variables
# ======================
CC=g++
OPT=-Wall
#OPT=-O3 -Wall

all : dibfr

final : main.o matrix.o
	$(CC) -o final $(OPT) main.o matrix.o -lm

main.o : main.cpp
	$(CC) -c $(OPT) main.cpp

matrix.o : matrix.cpp
	$(CC) -c $(OPT) matrix.cpp

# ======
# Clean
# ======
clean :
	rm -f *.o
realclean : clean
	rm -f final
