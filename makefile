CXX=g++
CXXFLAGS=-Wall
RM=rm -f

calc: pair.o stack.o eval.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

eval.o: eval.cpp eval.h
pair.o: pair.cpp pair.h
stack.o: stack.cpp stack.h

%.o: %.cpp; $(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) stack.o pair.o calc.o eval.o main.o