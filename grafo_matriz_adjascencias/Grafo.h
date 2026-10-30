/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: GABRIEL ALAN SCARATTI | LUCAS VITORIO DORNELES ALBUQUERQUE
 * Matricula: 20250015359 | 20260022301
 */

#ifndef GRAFO_H

#define GRAFO_H

#include "Aresta.h"
#include <string>
#include <vector>

class Grafo{
public: 
    Grafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    bool tem_aresta(Aresta e);
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
    bool eh_passeio(std::vector<int> &seq_vertices);
    bool eh_caminho(std::vector<int> &seq_vertices);
    int grau(int vertice);
    int grau_minimo();
    int grau_maximo();

    bool caminho(int v1, int v2, int marcado[], std::string str_recursiva = "");

    void busca_largura(int v, std::vector<int> &pai, std::vector<int> &dist);

    void nao_recebem_mensagem(int no_origem, int ttl);

    

private:
    int num_vertices_;
    int num_arestas_;
    std::vector<std::vector<int>> matriz_adj_;

};


#endif /*GRAFO_H*/
