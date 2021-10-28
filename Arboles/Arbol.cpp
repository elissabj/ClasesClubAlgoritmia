#include<bits/stdc++.h>
using namespace std;

struct miNodo {
    int valor;
    miNodo * izquierda;
    miNodo * derecha;

    //Constructor
    miNodo(int dato){
        valor = dato;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

void preOrden (miNodo * raiz){

    if(raiz == nullptr) return;

    cout << raiz->valor<<" ";

    preOrden(raiz->izquierda);
    preOrden(raiz->derecha);
}

void inOrden (miNodo * raiz){
    
    if (raiz == nullptr) return;

    inOrden(raiz->izquierda);
    cout<<raiz->valor<<" ";
    inOrden(raiz->derecha);
}

void postOrden (miNodo * raiz){

    if(raiz == nullptr) return;
    postOrden(raiz->izquierda);
    postOrden(raiz->derecha);
    cout << raiz->valor<<" ";
}

int main(){

    miNodo* raiz = new miNodo(1);
    
    /* 
             1
            / \
          NULL NULL
    */

    raiz->izquierda = new miNodo(2);
    raiz->derecha = new miNodo (3);

    /*
                    1
                  /    \
                 2       3
               /  \     /  \
            NULL NULL  NULL NULL
    */
 
    raiz->izquierda->izquierda = new miNodo(4);
    
    /*
               1
            /     \
           2       3
          / \     / \
         4  NULL NULL NULL
        / \
     NULL NULL
    */

    preOrden(raiz);

    return 0;
}