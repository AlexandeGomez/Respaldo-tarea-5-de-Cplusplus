#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista
{
private:
    Nodo *header;
public:
    Lista();
    void set_header(Nodo*);
    Nodo* get_header();

    Nodo* search_address(int);
    Nodo* get_ultimo();

    void insertar(string);
    int tamanio();
    void mostrar_todo();
    void insertar_en(int, string);
    void modificar(int, string);
    string tomar(int);
    int buscar(string);
    bool vacia();
    string tomar_primero();
    int eliminar(int);
    void purga();

    virtual ~Lista();
};

#endif // LISTA_H
