#include <iostream>
#include "nodo.h"
#include "lista.h"

using namespace std;

int main()
{
    Lista* cadena = new Lista;

    cadena->insertar("1");
    cadena->insertar("2");
    cadena->insertar("3");
    cadena->insertar("4");
    cadena->mostrar_todo();
    cout<<endl;
    cout<<cadena->tamanio()<<endl;
    cout<<endl;
    cadena->insertar_en(1, "nueva");
    cadena->mostrar_todo();
    cout<<endl;
    cadena->insertar_en(5, "cadena");
    cadena->mostrar_todo();
    cout<<endl;
    cout<<cadena->tomar(1)<<endl;
    cout<<cadena->buscar("None")<<endl;
    cout<<endl;
    cadena->insertar_en(9, "new");
    cout<<cadena->buscar("new")<<endl;
    cout<<endl;
    cadena->mostrar_todo();
    cout<<endl;
    cout<<cadena->vacia()<<endl;
    cout<<endl;
    cout<<cadena->eliminar(15)<<endl;
    cout<<endl;
    cadena->mostrar_todo();
    cout<<endl;
    cadena->purga();
    cadena->mostrar_todo();
    cout<<endl;
    cout<<cadena->tamanio()<<endl;
    return 0;
}
















