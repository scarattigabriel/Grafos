#include "Circulo.h"
#include <stack>
#include <iostream>

using namespace std;

int main() {
    try {
        double raio;
        cout << "Digite o raio do circulo: ";
        cin >> raio;
      
        Circulo circulo(raio);
        Circulo circulo2(4);
        Circulo circulo3(8);

        circulo.imprime_area();
        circulo2.imprime_perimetro();
        circulo3.imprime_perimetro();

        stack<int> pilha;

        pilha.push(5);
        pilha.push(2);

        cout << pilha.top() << "\n";
        pilha.pop();
        cout << pilha.top() << "\n";
        pilha.pop();
        
    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
