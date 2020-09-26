#include "Arista.h"
#include <string>
using namespace std;


Arista::Arista() {
	origen = 0;
	direccion = 0;
	peso = 0;
}

Arista::Arista(int P_origen, int P_direccion, int P_peso) {
	origen = P_origen;
	direccion = P_direccion;
	peso = P_peso;

}

int Arista::getOrigen() {
	return origen;
}

int Arista::getDireccion() {
	return direccion;
}

int Arista::getPeso() {
	return peso;
}

void Arista::setOrigen(int P_origen) {
	origen = P_origen;
}

void Arista::setDireccion(int P_direccion) {
	direccion = P_direccion;
}

void Arista::setPeso(int P_peso) {
	peso = P_peso; 
}

string Arista::toString(){
	string retornar = " ";
	retornar += origen;
	retornar += ",";
	retornar += direccion;
	retornar += ",";
	retornar += peso;
	return retornar;

}

Arista::~Arista() {
}