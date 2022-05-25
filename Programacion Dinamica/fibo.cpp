#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

bool vis[1000006];
long long int mem[1000006];


long long int fibo (long long int n){

    if(n == 1 || n == 2){
        return 1;
    }

    if(!vis[n]){
        vis[n] = true;
        mem[n] = ( fibo(n-1) + fibo (n-2) ) % MOD;
    }

    return mem[n];
}

//Iterativa
long long int fib (long long int n){
    mem[0] = 0;
    mem[1] = 1;
    
    for(int i = 2; i <= n; i++){
        mem[i] = (mem[i-1] + mem[i-2]) % MOD;
    }

    return mem[n];
}

int main(){

    long long int n; cin >> n; 
    cout << fib(n) <<"\n";

return 0;
}