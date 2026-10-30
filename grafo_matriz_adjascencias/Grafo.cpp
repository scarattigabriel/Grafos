/*
 * Trabalho 1 - Time to Live
 *
 * GEN505 - Grafos - 2026/2
 *
 * Nome: GABRIEL ALAN SCARATTI | LUCAS VITORIO DORNELES ALBUQUERQUE
 * Matricula: 20250015359 | 20260022301
 */

#include "Grafo.h"
#include <climits>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>

using namespace std;

Grafo::Grafo(int num_vertices) {
    if (num_vertices <= 0) {
        throw(invalid_argument("Erro no construtor Grafo(int): o numero de "
            "vertices " + to_string(num_vertices) + " eh invalido!"));
    }

    num_vertices_ = num_vertices;
    num_arestas_ = 0;
    matriz_adj_.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        matriz_adj_[i].resize(num_vertices, 0);
    }
}

int Grafo::num_vertices() {
    return num_vertices_;
}

int Grafo::num_arestas() {
    return num_arestas_;
}

bool Grafo::tem_aresta(Aresta e) {
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e) {
    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = 1;
        matriz_adj_[e.v2][e.v1] = 1;

        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (tem_aresta(e)) {
        matriz_adj_[e.v1][e.v2] = 0;
        matriz_adj_[e.v2][e.v1] = 0;

        num_arestas_--;
    }
}

void Grafo::imprime() {

    cout << "Grafo:\n";
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u;
            }
        }
        cout << "\n";
    }
}

bool Grafo::eh_passeio(vector<int> &seq_vertices) {
    if (seq_vertices.empty()) return false; 

    for (int i = 0; i + 1 < seq_vertices.size(); i++) {
        Aresta e(seq_vertices[i], seq_vertices[i + 1]);
        if (!tem_aresta(e)) {
            return false;
        }
    }
    return true;
}

bool Grafo::eh_caminho( vector<int> &seq_vertices){
    if(!eh_passeio(seq_vertices)){
        return false;
    }

    vector<int> verificador(num_vertices_);
    for(int i = 0; i < seq_vertices.size(); i++){
        if(verificador[seq_vertices[i]] == 1){
            return false;
        }
        verificador[seq_vertices[i]] = 1;
    }
    return true;
}

int Grafo::grau(int vertice){
    int grau = 0;
    for(int i = 0; i < num_vertices_; i++){
        if(matriz_adj_[vertice][i] == 1){
            grau++;
        }
    }
    return grau;
}

int Grafo::grau_minimo(){
    if(num_vertices_ == 0){return 0;}

    int grau_minimo = INT_MAX;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau(i);
        if(g < grau_minimo){
            grau_minimo = g;
        }
    }
    return grau_minimo;
}

int Grafo::grau_maximo(){
    int grau_maximo = 0;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau(i);
        if(g > grau_maximo){
            grau_maximo = g;
        }
    }
    return grau_maximo; 
}

bool Grafo::caminho(int v, int w, int marcado[], std::string str_recursiva) {

    cout << str_recursiva << "caminho(" << v << ", " << w << ")\n";

    if (v == w) return true;

    marcado[v] = 1;

    for (int u = 0; u < num_vertices_; u++) {

        if (matriz_adj_[v][u] != 0) {

            if (marcado[u] == 0) {

                if (caminho(u, w, marcado, str_recursiva + "--"))
                    return true;
            }
        }
    }
    return false;
}


void Grafo::busca_largura(int v, vector<int> &pai, vector<int> &dist) {
    vector<int> marcado(num_vertices_, 0);
    queue<int> fila;
    marcado[v]=1;
    pai[v]=-1;
    dist[v]=0;
    fila.push(v);
    while(!fila.empty()){
        int topo = fila.front();
        fila.pop();
        for(int u = 0; u < num_vertices_; u++){
            if (matriz_adj_[topo][u]!=0)
                if (marcado[u]==0)
                {
                    marcado[u]=1;
                    pai[u]=topo;
                    dist[u]=dist[topo] + 1;
                    fila.push(u);
                }
        }
    }
}

void Grafo::nao_recebem_mensagem(int no_origem, int ttl) {
    std::vector<int> pai(num_vertices_, -1);
    std::vector<int> dist(num_vertices_, -1);

    busca_largura(no_origem, pai, dist);

    std::cout << no_origem << " " << ttl << ":";

    for (int i = 0; i < num_vertices_; i++) {
        if (dist[i] == -1 || dist[i] > ttl) {
            std::cout << " " << i;
        }
    }
    std::cout << "\n";
}
