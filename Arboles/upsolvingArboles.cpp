//cpp20
#include<bits/stdc++.h>
using namespace std;

struct miNodo{

    int valor;
    miNodo * izq;
    miNodo * der;

    miNodo(int val){
        valor = val;
        izq = nullptr;
        der = nullptr;
    }

};

class arbolBinario{

    private: 

    vector<int>valuesBST;


    public:
    miNodo* inserta(miNodo* raiz, int valor) {
        if(raiz == nullptr) {
            return new miNodo(valor);
        } else {
            miNodo* actual;
            if(valor <= raiz->valor) {
                actual = inserta(raiz->izq, valor);
                raiz->izq = actual;
            } else {
                actual = inserta(raiz->der, valor);
                raiz->der = actual;
            }
            return raiz;
        }
    }

    miNodo* insertaBST(miNodo* raiz, int valor) {
        if(raiz == nullptr) {
            return new miNodo(valor);
        } else {
            miNodo* actual;
            if(valor < raiz->valor) {
                actual = inserta(raiz->izq, valor);
                raiz->izq = actual;
            } else if( valor > raiz->valor) {
                actual = inserta(raiz->der, valor);
                raiz->der = actual;
            }
            return raiz;
        }
    }
    


    int alturaMax (miNodo *raiz){
        if(raiz == nullptr){
            return -1;
        }
        return max(alturaMax(raiz->izq)+1, alturaMax(raiz->der)+1);
    }

    void preOrden(miNodo *raiz){
        if(raiz == nullptr){
            return;
        }

        cout << raiz->valor <<" ";
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }

    void postOrden(miNodo *raiz){
        if(raiz == nullptr){
            return;
        }

        postOrden(raiz->izq);
        postOrden(raiz->der);
        cout << raiz->valor <<" ";
    }

    void inOrden(miNodo *raiz){
        if(raiz == nullptr){
            return;
        }

        inOrden(raiz->izq);
        cout << raiz->valor <<" ";
        inOrden(raiz->der);
    }

    void inOrdenCheckBST(miNodo *raiz){
        if(raiz == nullptr){
            return;
        }

        inOrdenCheckBST(raiz->izq);
        valuesBST.push_back(raiz->valor);
        inOrdenCheckBST(raiz->der);
    }

    bool isBST (miNodo * raiz){
        inOrdenCheckBST(raiz);
        for(int i = 1; i < valuesBST.size(); i++){
            if(valuesBST[i-1] >= valuesBST[i]){
                return false;
            }
        }

        return true;
    }

    void BFS (miNodo * raiz){
        queue<miNodo*>nodoAImprimir;
        nodoAImprimir.push(raiz);

        while(!nodoAImprimir.empty()){
            miNodo * nodoActual = nodoAImprimir.front();
            cout << nodoActual->valor << " ";
            
            if(nodoActual->izq != nullptr){
                nodoAImprimir.push(nodoActual->izq);
            }

            if(nodoActual->der != nullptr){
                nodoAImprimir.push(nodoActual->der);
            }

            nodoAImprimir.pop();
        }
    }
};


int main(){

    arbolBinario miArbol;
    miNodo *raiz = nullptr;

    int n, etiqueta;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> etiqueta;
        raiz = miArbol.inserta(raiz,etiqueta);
    }

    //Problem A
    int altura = miArbol.alturaMax(raiz);
    cout << altura <<"\n";

    //Problem B
    //miArbol.preOrden(raiz);

    //Problem C 
    //miArbol.postOrden(raiz);

    //Problem D
    //miArbol.inOrden(raiz);
    
    //Problema F
    /*for(int i = 0; i < n; i++){
        cin >> etiqueta;
        raiz = miArbol.insertaBST(raiz,etiqueta);
    }*/ 

    //Problema G : como HR tiene problemas hacemos técnica split pero 
    // tiene un problema con un test case y la forma de insertar entonces 
    //manden la funcion (:
    /*string cad;
    getline(cin, cad);
    cad += " ";
    string aux; 
    for(int i = 0; i < cad.size(); i++){
        if(cad[i] == ' '){
            etiqueta = stoi(aux);
            raiz = miArbol.inserta(raiz,etiqueta);
            aux = "";
        }else{
            aux += cad[i];
        }
        
    }

    cout << (miArbol.isBST(raiz)?  "Yes\n": "No\n");*/

    //Problema H
    //miArbol.BFS(raiz);


return 0; 
}