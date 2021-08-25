hepsi: program calistir

Stack.o:
	g++ -I "./include" -c ./src/Stack.cpp -o ./lib/Stack.o
Kisi.o:
	g++ -I "./include" -c ./src/Kisi.cpp -o ./lib/Kisi.o
Node.o:
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
AVLTree.o:
	g++ -I "./include" -c ./src/AVLTree.cpp -o ./lib/AVLTree.o
main.o:
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
program: Stack.o Kisi.o Node.o AVLTree.o main.o
	g++ ./lib/Stack.o ./lib/Kisi.o ./lib/Node.o ./lib/AVLTree.o ./lib/main.o -o ./bin/cikti -lstdc++
calistir:
	./bin/cikti.exe