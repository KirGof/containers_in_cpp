

CC := gcc
# CFLAGS := -std=c++17 -g -Wall -Werror -Wextra
CFLAGS := -std=c++17 -g 
LIBFLAGS := -lstdc++ -lm
TEST_FLAGS :=  -lgtest 
OBJ := s21_containers.cpp



all:
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS)

obj:

test:

val:
	valgrind --tool=memcheck --leak-check=yes -s --track-origins=yes ./a.out

clean:
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
