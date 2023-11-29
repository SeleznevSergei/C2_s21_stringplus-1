CFLAGS = -std=c11 -Wall -Werror -Wextra -ftest-coverage -fprofile-arcs 
LIB = s21_string.a
TESTS = tests.c 
T_OUT = tests
G_OUT = gcovreport

all: s21_string.a

test: $(LIB)
	gcc $(CFLAGS) $(TESTS) $(LIB) -lcheck -lsubunit -o $(T_OUT) -lm

s21_string.a:
	gcc $(CFLAGS) -c s21_*.c -lm
	ar rc $(LIB) *.o
	ranlib $(LIB)

gcov_report: $(LIB) test
	./$(T_OUT)
	lcov -t "$(G_OUT)" -o $(G_OUT).info -c -d .
	genhtml -o report $(G_OUT).info
	open report/index.html
	make clean

clean:
	rm -rf *.o tests s21_string *.gcda *.gcno *.info ./out

style:
	clang-format -n *.c *.h

stylecor:
	clang-format -i *.c *.h
