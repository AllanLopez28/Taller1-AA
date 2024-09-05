#include <iostream>
#include <string>

using namespace std;

// definiendo el nodo
struct Nodo {
    string nombre;  
    int stock;      
    Nodo* siguiente; 
};      

// prototiop funciones
void agregarProducto(Nodo* &lista, const std::string &nombre, int stock);
void menorStock(Nodo* lista);
void actualizarStock(Nodo* lista, const std::string &nombre, int nuevoStock);
void menu(Nodo* &lista);


void agregarProducto(Nodo* &lista, const string &nombre, int stock) {
    Nodo* nuevo = new Nodo();
    nuevo->nombre = nombre;
    nuevo->stock = stock;  
    Nodo* aux1 = lista;
    Nodo* aux2 = NULL;

    
    while ((aux1 != NULL)) {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1) {
        lista = nuevo;
    } else {
        aux2->siguiente = nuevo;
    }
    nuevo->siguiente = aux1;
}

void menorStock(Nodo* lista) {
    Nodo* actual = new Nodo;
    actual = lista; 
    cout<<"--------------PRODUCTOS----------------\n\n";
     while (actual != nullptr) { 
        if (actual->stock < 10) { 
            cout << "Nombre: " << actual->nombre << ", Stock: " << actual->stock << endl; 
        }
        actual = actual->siguiente; // 
    }
}

void actualizarStock(Nodo* lista, const string &nombre, int nuevoStock) {
    Nodo* actual = new Nodo;
    actual = lista; 

    while (actual != NULL) {
        if (actual->nombre == nombre) {
            actual->stock = nuevoStock;
            cout << "Stock actualizado de" << nombre << " a " << nuevoStock << " unidades." << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Producto no encontrado." << endl;
}

void menu(Nodo* &lista) {
    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar producto\n";
        cout << "2. Productos con menos de 10 existencias\n";
        cout << "3. Actualizar stock de un producto\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            int stock;
            cout << "Ingrese el nombre del producto: ";
            cin >> nombre;
            cout << "Ingrese el stock del producto: ";
            cin >> stock;
            agregarProducto(lista, nombre, stock);


        } else if (opcion == 2) {
            menorStock(lista);


        } else if (opcion == 3) {
            string nombre;
            int nuevoStock;
            cout << "Ingrese el nombre del producto a actualizar: ";
            cin >> nombre;
            cout << "Ingrese el nuevo stock: ";
            cin >> nuevoStock;
            actualizarStock(lista, nombre, nuevoStock);

        }


    } while (opcion != 4);
}
