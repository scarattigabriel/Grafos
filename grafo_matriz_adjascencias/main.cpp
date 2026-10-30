#include "Aresta.h"
#include "Grafo.h"
#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    try {
        Grafo g(6);

        Aresta e(1, 3);
        cout << "Tem aresta (1,3): " << g.tem_aresta(e) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:

        g.insere_aresta(Aresta(1, 3));

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1: 3
        // 2:
        // 3: 1
        // ...
        // 5:

        g.remove_aresta(Aresta(1, 3));
        g.remove_aresta(Aresta(2, 5)); //aresta que nao esta no grafo

        cout << "\n";
        cout << "Tem aresta (1,3): " << g.tem_aresta(Aresta(1, 3)) << "\n";
        cout << "Tem aresta (2,5): " << g.tem_aresta(Aresta(2, 5)) << "\n";
        g.imprime();
        // Grafo:
        // 0:
        // 1:
        // 2:
        // 3:
        // ...
        // 5:

        // int n_nos, c_conexoes, x, y, o_operacao;
        // cin >> n_nos >> c_conexoes;

        // Grafo grafo(n_nos);

        // for (int i = 0; i < c_conexoes; i++) {
        //     cin >> x >> y;
        //     grafo.insere_aresta(Aresta(x, y));
        // }

        // cin >> o_operacao;

        // for (int j = 0; j < o_operacao; j++) {
        //     cin >> x >> y;
        //     grafo.nao_recebem_mensagem(x, y);
        // }

    }
    catch (const exception &e) {
        cerr << "exception: " << e.what() << "\n";
    }

    return 0;
}
