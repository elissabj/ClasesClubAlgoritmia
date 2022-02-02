#include<bits/stdc++.h>
using namespace std;

struct miNodo{
    char c;
    miNodo *sig;
};

struct miPila{
    miNodo * tope = nullptr;
    int tam = 0;

    bool empty(){
        if(tam == 0) return true;
        return false;
    }

    int size(){
        return tam;
    }

    char top(){
        return tope->c;
    }

    void push (char a){
        tam++;
        miNodo *nuevoNodo = new miNodo();
        nuevoNodo->c = a;

        if(tope == nullptr){
            tope = nuevoNodo;
        }else{
            miNodo *nodoDesplazar = tope;
            tope = nuevoNodo;
            tope->sig = nodoDesplazar;
        }
        return;
    }

    void pop(){
        if(tope == nullptr) return;
        tam--;
        miNodo *nodoBye = tope;
        tope = tope->sig;
        delete nodoBye;

        return;
    }
};

bool isCorrect(string &s){

   miPila check;
   
   for(int i = 0; i < s.size(); i++){
       if((s[i] == '(') || (s[i] == '[') || (s[i] == '{')){
           check.push(s[i]);
       }else if ((s[i] == ')') || (s[i] == ']') || (s[i] == '}')){
           if(check.empty()){return false;}
           if(s[i] == ')' && check.top() != '('){
              return false;
           }else if(s[i] == ']' && check.top() != '['){
              return false;
           }else if(s[i] == '}' && check.top() != '{'){
             return false;
           }else{
               check.pop();
           }
           
       }
   }
   
   return check.empty();
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