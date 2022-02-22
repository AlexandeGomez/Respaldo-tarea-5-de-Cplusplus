#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo
{
private:
    string data;
    Nodo *address;
public:
    Nodo();

    void set_data(string);
    void set_address(Nodo*);
    string get_data();
    Nodo *get_address();

    virtual ~Nodo();
};

#endif // NODO_H
