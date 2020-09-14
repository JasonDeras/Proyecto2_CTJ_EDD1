#ifndef OBJECT_H
#define OBJECT_H
#include <string>

using namespace std;

class Object{

    public:

        virtual ~Object(){};
        
        virtual bool equals(Object*) = 0;

        virtual string toString() = 0;
};
#endif