CXX := g++
CXXFLAGS := -g -Wall --std=c++11
GTESTLIBS := -lgtest -lgtest_main -lpthread
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec.o	: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $^ -o $@
llrec-test : llrec-test.cpp llrec.cpp llrec.h 
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 