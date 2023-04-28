FLAGS=#-Wall -Wextra -Werror
CC=gcc
SOURCES=smart_calc.c
OBJECTS=$(SOURCES:.c=.o)
#TESTSFLAGS= -lm -lcheck -lm -lpthread -lrt -lsubunit# -fsanitize=address -g
TESTSFLAGS=-lcheck
COVERAGE_FLAGS=--coverage
LDFLAGS="-lgcov"

all: install 

q_make:
	cd Calculator/ && qmake
install: q_make
	cd Calculator/ && make
uninstall:
	# rm -r Calculator/release/
	rm Calculator/*.o

clean:
	rm -f *.out *.a *.o asd.c s21_test *.html *.gcno *.gcda coverage_report.css *.info *.gch
	rm -rf report cov-report
	cd Calculator/ && make clean
dvi:
	doxygen doc/Doxyfile.txt
	open ./html/index.html
dist: 
	tar -czvf Smart_calc.tar.gz ../src
test: library
	$(CC) -c unit_test.c -o test.o
	$(CC) test.o smart_calc.a $(TESTSFLAGS) -o s21_test
gcov_report:
	$(CC) $(FLAGS) $(COVERAGE_FLAGS) -c $(SOURCES) $(OBGECTS)
	ar rc smart_calc.a $(OBJECTS)
	ranlib smart_calc.a
	$(CC) test.o smart_calc.a $(TESTSFLAGS) $(LDFLAGS) -o s21_test
	./s21_test
	lcov -t "gcov_report" -o s21_smart_calc.info -c -d .
	genhtml -o report s21_smart_calc.info
	open report/index.html
library:
	$(CC) -c $(SOURCES) $(OBGECTS) -lm
	ar rc smart_calc.a $(OBJECTS)
	ranlib smart_calc.a
