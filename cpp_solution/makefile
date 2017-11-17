CXX=g++
CPPFLAGS=-march=native -Ofast -frename-registers -funroll-loops 

all: main.o street.o person.o hints.o generator.o algorithm.o
	$(CXX) $(CPPFLAGS) main.o street.o person.o hints.o generator.o algorithm.o -o solve

main.o: main.cpp
	$(CXX) $(CPPFLAGS) -c main.cpp

street.o: street.cpp
	$(CXX) $(CPPFLAGS) -c street.cpp

person.o: person.cpp
	$(CXX) $(CPPFLAGS) -c person.cpp

hints.o: hints.cpp
	$(CXX) $(CPPFLAGS) -c hints.cpp

generator.o: generator.cpp
	$(CXX) $(CPPFLAGS) -c generator.cpp

algorithm.o: algorithm.cpp
	$(CXX) $(CPPFLAGS) -c algorithm.cpp	

clean:
	-@rm -rf *.o 2>/dev/null || true
