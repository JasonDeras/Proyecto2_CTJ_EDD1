#include <iostream>
#include <fstream>
#include "TDA_Tree.h"
using namespace std;

//Método que imprime el árbol en postorder
void postOrder(TreeNode* treenode) {
	
	for (int i = 0; i < treenode->getChildren().size(); i++) {
		postOrder(treenode->getChild(i));
		cout << ',';
	}
	cout << treenode->getTag();

}

//Método que imprime el árbol en inorder
void inOrder(TreeNode* treenode) {

	if (treenode->getChildren().size() != 0) {
		inOrder(treenode->getChild(0));
		cout << ',';
	}
	
	cout << treenode->getTag();
	
	for (int i = 1; i < treenode->getChildren().size(); i++) {
		cout << ',';
		inOrder(treenode->getChild(i));
	}

}

//Método que imprime el árbol en preorder
void preOrder(TreeNode* treenode) {

	cout << treenode->getTag();
	
	if (treenode->getChildren().size() != 0) {
		
		for (int i = 0; i < treenode->getChildren().size(); i++) {
			cout << ',';
			TreeNode* temp = treenode->getChild(i);
			preOrder(temp);
			temp = nullptr;
			delete temp;
		}
	}
}

//Método que revisa si un string es esta vacio
bool isEmpty(string validar) {
	
	for (int i = 0; i < validar.size(); i++) {
		if (validar[i] != '\t')
			return false;
	}
	return true;
}

//Método que retorna un vector de string con las etiquetas
vector<string> returnTags(string recibir) {
	
	vector<string> tags;
	
	int posicion = 0;
	
	for (int i = 0; i < recibir.size(); i++) {
		
		if (recibir[i] == ',') {
			tags.push_back(recibir.substr(posicion, i - posicion));
			posicion = i + 1;
		}
	}

	if (recibir.substr(posicion, recibir.size() - posicion) != "")
		tags.push_back(recibir.substr(posicion, recibir.size() - posicion));
	return tags;

}

//Método que valida que la entrada es del tipo de dato correcto (entero)
int Validar_Opcion() {
	
	int ingreso;
	cin >> ingreso;
	
	while (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Debe de ingresar un número entero.\n";
		cout<<"Ingréselo nuevamente: ";
		cin >> ingreso;
	}
	
	return ingreso;

}//fin del metodo para validar el ingreso del usuario

//Menu de las opciones de los arboles
void M_Arboles(){

	TDATree* tree = nullptr;
	int opcion;
	bool operaciones=true;

	while(operaciones){

		cout<<"Algoritmos sobre Árboles\n\n";
    	cout<<"1. Leer árbol de un archivo\n";
    	cout<<"2. Imprimir recorrido pre-order\n";
    	cout<<"3. Imprimir recorrido in-order\n";
    	cout<<"4. Imprimir recorrido post-order\n";
    	cout<<"5. Codificador de Huffman\n";
    	cout<<"6. Decodificador de Huffman\n";
    	cout<<"7. Regresar al Menú Principal\n\n"; 
    	cout<<"Ingrese una opcion: ";
    	opcion=Validar_Opcion();
    	cout<<"\n\n";

    	switch(opcion){

    		//Caso para Leer un arbol desde un archivo
    		case 1:{

    			ifstream file;
				string nombre, linea;
				int times;
				vector<string> lineas;
				vector<TDATree*> arboles;
				
				cout << "Ingrese el nombre del archivo en el que está guardado el árbol (no es necesario agregarle la extensión): ";
				cin.ignore();
				getline(cin, nombre);
				file.open(nombre + ".txt", ios::in);
				
				if (file) {
					
					cout << "El archivo se abrió exitósamente" << endl;
					getline(file, linea, '\n');
					times = stoi(linea);
					
					for (int j = 0; j < times; j++) {
						getline(file, linea, '\n');
						if (isEmpty(linea))
							linea = "";
						lineas.push_back(linea);
					}

					file.close();
					
					for (int i = lineas.size() - 1; i >= 0; i--) {
						
						if (lineas[i] != "") {
							
							TDATree* tr = nullptr;
							vector<TDATree*> aux;
							
							for (int j = 0; j < returnTags(lineas[i]).size(); j++) {
								
								bool exists = false;
								
								if (arboles.size() != 0) {
									
									for (int k = 0; k < arboles.size(); k++) {
										
										if (arboles[k]->getRoot()->getTag() == returnTags(lineas[i])[j]) {
											tr = arboles[k];
											exists = true;
											arboles.erase(arboles.begin() + k);
											break;
										}
									}
								}
								
								if (!exists)
									tr = new TDATree(returnTags(lineas[i])[j]);
								aux.push_back(tr);
							}
							
							tr = new TDATree;
							tr->create(to_string(i), aux);
							arboles.push_back(tr);
						}
					}
					tree = arboles[0];
					arboles.clear();
				
				}else{
					cout << "No se pudo abrir el archivo" << endl;
				}
				
    		break;}
    		
    		//Caso para Imprimir recorrido preorder
    		case 2:{

    			if (tree) {
					preOrder(tree->getRoot());
					cout << endl;
				}else{
					cout << "No ha abierto ningun árbol" << endl;
				}

    		break;}
    		
    		//Caso para Imprimir recorrido in-order
    		case 3:{
    			
    			if (tree) {
					inOrder(tree->getRoot());
					cout << endl;
				}else{
					cout << "No ha abierto ningun árbol" << endl;
				}

    		break;}
    		
    		//Caso para Imprimir recorrido post-order
    		case 4:{

    			if (tree) {
					postOrder(tree->getRoot());
					cout << endl;
				}else{
					cout << "No ha abierto ningun árbol" << endl;
				}
				
    		break;}
    		
    		//Caso para Codificador de Huffman
    		case 5:{
    		break;}
    		
    		//Caso para Decodificador de Huffman
    		case 6:{
    		break;}
    		
    		//Caso para volver al menu principal desde arboles
    		case 7:
    			cout<<"Volviendo al menu principal\n\n\n";
    			operaciones=false;
    		break;
    		
    		//Caso para las opciones no validas
    		default:{
    			cout<<"Opcion no valida\n\n\n";
    		break;}

    	}//fin de los caso de las operaciones con los arboles
	
	}//while repetitivo de las operaciones con los arboles
	

}//fin del metodo del menu de los arboles

//Menu de las opciones de los grafos
void M_Grafos(){
	
	int opcion;
	bool operaciones=true;

	while(operaciones){
		
		cout<<"Algoritmos sobre Grafos\n\n";
    	cout<<"1. Leer grafo de un archivo\n";
    	cout<<"2. Prim\n";
    	cout<<"3. Kruskal\n";
    	cout<<"4. Floyd\n";
    	cout<<"5. Regresar al Menú principal\n\n"; 
		cout<<"Ingrese una opcion: ";
		opcion=Validar_Opcion();
		cout<<"\n\n";
		
		switch(opcion){

			//Caso para leer un grafo desde un archivo
			case 1:{
			break;}

			//Caso para prim
			case 2:{
			break;}
			
			//Caso para Krustal
			case 3:{
			break;}
			
			//Caso para floyd
			case 4:{
			break;}
			
			//Caso para regresar al menu pirncipal desde grafos
			case 5:{
				cout<<"Volviendo al menu principal\n\n\n";
				operaciones=false;
			break;}
			
			//Caso para las opciones no validas
			default:{
				cout<<"Opcion no valida\n\n\n";
			}
		}//fin de las opciones de los grafos

	}//fin del while repetitivo de las opciones de los grafos 


}//fin del metodo del menu para los grafos

int main() {

	bool usuario=true;

	while(usuario){
		
		int opcion;
	
		cout<<"Menú Principal\n\n"; 
    	cout<<"1. Algoritmos sobre Árboles\n";
    	cout<<"2. Algoritmos sobre Grafos\n";
    	cout<<"3. Salir\n\n"; 
    	cout<<"Ingrese una opcion: ";
    	opcion=Validar_Opcion();
    	cout<<"\n\n";
		
		switch(opcion){

			//Caso para el menu de los arboles 
			case 1:{
				M_Arboles();			
			break;}

			//Caso para el menu de grafos
			case 2:{
				M_Grafos();
			break;}

			//Caso para salir del programa
			case 3:{
				usuario=false;
			break;}
			
			//Caso para una opcion no valida
			default:{
				cout<<"Opcion no valida\n\n\n";
			break;}

		}//fin del swith del menu principal

	}//fin del while repetitivo del usuario
	cout<<"Salio del programa\n\n";
	return 0;
}//fin del main del proyecto