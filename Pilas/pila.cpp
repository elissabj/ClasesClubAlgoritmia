#include<bits/stdc++.h>
using namespace std;

struct node{
    char c;
    node *sig;
};

struct myStack{
    node * tope = nullptr;
    int tam = 0;

    bool empty(){
        if(tam == 0) return true;
        return false;
    }

    char top(){
        return tope->c;
    }

    void push (char a){
        tam++;
        node *nuevoNodo = new node();
        nuevoNodo->c = a;

        if(tope == nullptr){
            tope = nuevoNodo;
        }else{
            node *nodoDesplazar = tope;
            tope = nuevoNodo;
            tope->sig = nodoDesplazar;
        }
        return;
    }

    void pop(){
        if(tope == nullptr) return;
        tam--;
        node *nodoBye = tope;
        tope = tope->sig;
        delete nodoBye;

        return;
    }
};

bool isCorrect(string &s){

    myStack check;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            check.push(s[i]);
        }else{
            if((s[i] == ')' &&  check.top() != '(') || (s[i] == ')' &&  check.isEmp())){
                return false;
            }else if((s[i] == ']' &&  check.top() != '[') || (s[i] == ']' &&  check.isEmp()) ){
                return false;
            }else if((s[i] == '}' &&  check.top() != '{') || (s[i] == '}' &&  check.isEmp())){
                return false;
            }            
        }
    }

    return check.isEmp();
}


int main(){

    int t; cin >> t;

    while(t--){
        string s; cin >> s; 
        if(isCorrect(s)){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
    }

return 0;
}