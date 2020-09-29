#ifndef OBJECT_H
#define OBJECT_H
#include <string>
using std::string;

class Object{

    public:

        Object();

        virtual int Comparar(Object*) = 0;

        virtual string toString() = 0;

        virtual ~Object() {}
    
};
#endif