Main : main.o Object.o Tree_Node.o TDA_Tree.o 
	g++ main.o Object.o Tree_Node.o TDA_Tree.o -o CTJ.out
Main.o : main.cpp Object.cpp Tree_Node.cpp TDA_Tree.cpp 
	g++ -c main.cpp	