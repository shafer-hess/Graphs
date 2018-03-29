COMP = g++ -std=c++11
CFLAG = -g -c

all: program

program: Edge.o Vertex.o main.cpp
	$(COMP) -g -o program Edge.o Vertex.o main.cpp

Edge.o: Edge.cpp Edge.h
	$(COMP) $(CFLAG) Edge.cpp

Vertex.o: Vertex.cpp Vertex.h
	$(COMP) $(CFLAG) Vertex.cpp

clean: 
	$(RM) program 
