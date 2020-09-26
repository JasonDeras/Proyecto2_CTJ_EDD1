#ifndef ARISTA_H
#define ARISTA_H
#include "Object.h"
#include <string>
using namespace std;

class Arista : public Object{

    public:
    
        Arista();
        
        Arista(int, int, int);
        
        ~Arista();

        
        int getOrigen();
        
        int getDireccion();
    
        int getPeso();
    
        void setOrigen(int);
    
        void setDireccion(int);
    
        void setPeso(int);
    
        string toString();

    private:
        
        int origen;
        
        
        int direccion;
        
        int peso;

};
#endif