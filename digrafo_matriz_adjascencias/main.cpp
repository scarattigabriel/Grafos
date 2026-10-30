#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    try {

        Grafo g(7);

        // Cada insercao informa um peso inteiro positivo.
        g.insere_aresta(Aresta(0, 1), 2);
        g.insere_aresta(Aresta(1, 3), 5);
        g.insere_aresta(Aresta(1, 4), 3);
        g.insere_aresta(Aresta(3, 4), 1);
        g.insere_aresta(Aresta(3, 5), 4);
        g.insere_aresta(Aresta(4, 3), 6);
        g.insere_aresta(Aresta(4, 6), 2);
        g.insere_aresta(Aresta(5, 0), 7);
        g.insere_aresta(Aresta(5, 2), 3);
        g.insere_aresta(Aresta(5, 6), 5);
        g.insere_aresta(Aresta(6, 1), 4);

        g.imprime_saida();
        
        cin.get();
        cout << "\n";

        cout << "Grau de saída do vértice 6: " << g.grau_saida(6) << "\n";//1
        cout << "Grau de entrada do vértice 6: " << g.grau_entrada(6) << "\n";//2

        cin.get();
        cout << "\n";

        cout << "Grau mínimo de saída: " << g.grau_saida_min() << "\n";//0
        cout << "Grau máximo de saída: " << g.grau_saida_max() << "\n";//3

        cin.get();
        cout << "\n";

        cout << "Grau mínimo de entrada: " << g.grau_entrada_min() << "\n";//1
        cout << "Grau máximo de entrada: " << g.grau_entrada_max() << "\n";//2

        cin.get();
        cout << "\n";
 
        g.remove_aresta(Aresta(1, 3));

        cout << "Após remover a aresta (1,3):\n";
        g.imprime_saida();

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
