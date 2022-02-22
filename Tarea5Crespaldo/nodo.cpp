#include "nodo.h"

Nodo::Nodo()
{
    this->data = "";
    this->address = NULL;
}

void Nodo::set_data(string _data){
    this->data = _data;
}

void Nodo::set_address(Nodo *_address){
    this->address = _address;
}

string Nodo::get_data(){
    return this->data;
}

Nodo* Nodo::get_address(){
    return this->address;
}

Nodo::~Nodo(){
}
