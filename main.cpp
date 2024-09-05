#include <iostream>
#include <string>
#include "bodega.cpp"


using namespace std;

int main() {
    Nodo* lista = NULL;
    menu(lista);    
    while (lista != NULL) {
        Nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }
    return 0;
}