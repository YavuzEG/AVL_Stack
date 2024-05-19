Tum:derleme calistirma

derleme:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include/ -o ./lib/AVLLIST.o -c ./src/AVLLIST.cpp
	g++ -I ./include/ -o ./lib/AVLNode.o -c ./src/AVLNode.cpp
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Stacknode.o -c ./src/Stacknode.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Node.o ./lib/Stacknode.o ./lib/AVLNode.o ./lib/AVLLIST.o ./lib/Stack.o ./lib/AVL.o ./src/main.cpp

calistirma:
	./bin/main
