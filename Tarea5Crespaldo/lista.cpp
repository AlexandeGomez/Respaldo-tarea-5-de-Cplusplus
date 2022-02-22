#include "lista.h"

Lista::Lista()
{
    this->header = NULL;
}

void Lista::set_header(Nodo* _address){
    this->header = _address;
}

Nodo* Lista::get_header(){
    return this->header;
}


Nodo* Lista::search_address(int posicion){
    Nodo *direccion = this->get_header();
    int cont = 1;
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL && cont<posicion){
            direccion = direccion->get_address();
            cont++;
        }
        return direccion;
    }
    return NULL;
}

Nodo* Lista::get_ultimo(){
    Nodo *direccion = this->get_header();
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
        }
        return direccion;
    }
    return NULL;
}

//METODOS PROPIOS DEL EJERCICIO
void Lista::insertar(string dato){
        Nodo* ultimo = this->get_ultimo();
        Nodo* nuevo = new Nodo;
        nuevo->set_data(dato);
        if(ultimo!=NULL){
            this->get_ultimo()->set_address(nuevo);
        }
        else{
            this->set_header(nuevo);
        }
}


int Lista::tamanio(){
    int cont = 0;
    Nodo *direccion = this->get_header();
    if(direccion!=NULL){
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
            cont++;
        }
        return cont+1;
    }
    else{
        return cont;
    }
}


void Lista::mostrar_todo(){
    Nodo* direccion = this->get_header();
    int tamanio = this->tamanio();
    for(int i=0; i<tamanio; i++){
        cout<<direccion->get_data()<<endl;
        direccion = direccion->get_address();
    }
}

void Lista::insertar_en(int posicion, string newData){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        if(posicion==1){
            Nodo* direccion = this->get_header();
            Nodo* newNode = new Nodo;
            newNode->set_data(newData);
            this->set_header(newNode);
            newNode->set_address(direccion);
        }
        else{
            Nodo* nodoPosicion = this->search_address(posicion);
            Nodo* direccion = this->get_header();
            Nodo* anterior = NULL;
            Nodo* newNode = new Nodo;
            while(direccion!=nodoPosicion){
                anterior = direccion;
                direccion = direccion->get_address();
            }
            newNode->set_data(newData);
            anterior->set_address(newNode);
            newNode->set_address(direccion);
        }
    }
    else if(posicion>0 && tamanio>0 && posicion>tamanio){
        for(int i=0; i<(posicion-tamanio);i++){
            Nodo* newNode = new Nodo;
            this->get_ultimo()->set_address(newNode);
        }
        this->modificar(posicion, newData);
    }
}

string Lista::tomar(int posicion){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* direccion = this->search_address(posicion);
        return direccion->get_data();
    }
    return "";
}

int Lista::buscar(string dato){
    int tamanio = this->tamanio();
    if(tamanio!=0){
        Nodo* direccion = this->get_header();
        int cont = 1;

        if(direccion->get_data()==dato){
            return cont;
        }
        while(direccion->get_address()!=NULL){
            direccion = direccion->get_address();
            cont++;
            if(direccion->get_data()==dato){
                return cont;
            }
        }
    }
    return -1;
}

void Lista::modificar(int posicion, string dato){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* direccion = this->search_address(posicion);
        direccion->set_data(dato);
    }
}

bool Lista::vacia(){
    int tamanio = this->tamanio();
    if(tamanio!=0)
        return false;
    else
        return true;
}

string Lista::tomar_primero(){
    return this->tomar(1);
}

int Lista::eliminar(int posicion){
    int tamanio = this->tamanio();
    if(posicion>0 && posicion<=tamanio){
        Nodo* nodoBuscado = this->search_address(posicion);
        Nodo* direccion = this->get_header();
        Nodo* anterior = NULL;
        if(posicion==1){
            this->set_header(direccion->get_address());
            delete direccion;
            return 1;
        }
        while(direccion!=nodoBuscado){
            anterior = direccion;
            direccion = direccion->get_address();
        }
        anterior->set_address(direccion->get_address());
        delete direccion;
        return 1;
    }
    return -1;
}

void Lista::purga(){
    int tamanio = this->tamanio();
    if(tamanio!=0){
        for(int i=tamanio;i!=0;i--){
            this->eliminar(i);
        }
    }
}

Lista::~Lista()
{

}
