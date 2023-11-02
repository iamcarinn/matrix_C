CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
OS=$(shell uname)
ifeq ($(OS), Darwin)
 CHECK= -lcheck -lpthread -lm
else
 CHECK= -lcheck -lpthread -lm -lsubunit
endif

all: clean s21_matrix.a test gcov_report

s21_matrix.a:
	$(CC) $(CFLAGS) -c func/*.c
	ar r s21_matrix.a *.o
	rm *.o

test:
	$(CC) $(CFLAGS) -c func/*.c
	$(CC) $(CFLAGS) Tests.c -o test *.o $(CHECK)
	rm *.o
	./test

gcov_report:
	$(CC) $(CFLAGS) -o test -fprofile-arcs -ftest-coverage Tests.c func/*.c $(CHECK)
	./test
	lcov -t "report" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

clean:
	-rm -rf *.o *.a test *.gcno *.gcda test.info report

rebuild: clean all

val: clean test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

style:
	clang-format -n func/*.c *.c
