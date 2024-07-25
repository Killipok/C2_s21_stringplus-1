CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -g
HEADERS=*.h
SCRIPTS=scripts/*.c
TESTS=*.c
CODES=$(SCRIPTS) $(TESTS)
LIBS=-lcheck -lsubunit -lm -pthread -lrt

all: clean gcov_report

s21_string.a: clean
	$(CC) $(CFLAGS) -c $(SCRIPTS) 
	ar rc ./s21_string.a *.o

test: s21_string.a $(SCRIPTS)
	$(CC) $(CFLAGS) $(CODES) $(LIBS) -o test
	./test

gcov_report: s21_string.a $(SCRIPTS)
	$(CC) $(CFLAGS) --coverage $(CODES) $(LIBS) -o test
	./test
	lcov -t "gcov-test" -o report.info -c -d .
	genhtml -o report report.info
	open ./report/index.html

style:
	clang-format -style=Google -i $(HEADERS) $(CODES)

mem: clean test
	valgrind --tool=memcheck --leak-check=yes  ./test

clean:
	rm -rf test *.o *.a *.gc* report *.info

