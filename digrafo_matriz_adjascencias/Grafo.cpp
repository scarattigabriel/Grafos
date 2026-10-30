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

void Grafo::valida_vertice(int v) {
    if (v < 0 || v >= num_vertices_) {
        throw out_of_range("Vertice invalido");
    }
}

bool Grafo::tem_aresta(Aresta e) {
    valida_vertice(e.v1);
    valida_vertice(e.v2);
    if (matriz_adj_[e.v1][e.v2] != 0) {
        return true;
    }
    return false;
}

void Grafo::insere_aresta(Aresta e, int peso) {
    if (peso <= 0) {
        throw invalid_argument("O peso da aresta deve ser positivo");
    }
    if (!tem_aresta(e) && (e.v1 != e.v2)) {
        matriz_adj_[e.v1][e.v2] = peso; // Armazena o peso na matriz
        // matriz_adj_[e.v2][e.v1] = 1; remocao 
        num_arestas_++;
    }
}

void Grafo::remove_aresta(Aresta e) {
    if (tem_aresta(e)) {
        matriz_adj_[e.v1][e.v2] = 0;
        // matriz_adj_[e.v2][e.v1] = 0; remocao

        num_arestas_--;
    }
}

//imprime -> imprime_saida (imprime o vertice de origem e os vertices de destino das arestas)
void Grafo::imprime_saida() {

    cout << "Grafo:\n";
    for (int v = 0; v < num_vertices_; v++) {
        cout << v << ":";
        for (int u = 0; u < num_vertices_; u++) {
            if (matriz_adj_[v][u] != 0) {
                cout << " " << u << "(peso=" << matriz_adj_[v][u] << ")"; // Exibe destino e peso.
            }
        }
        cout << "\n";
    }
}

bool Grafo::eh_passeio(vector<int> &seq_vertices) {
    if (seq_vertices.empty()) {
        return false;
    }

    valida_vertice(seq_vertices.front());

    for (size_t i = 0; i + 1 < seq_vertices.size(); ++i) {
        Aresta e(seq_vertices[i], seq_vertices[i + 1]);

        if (!tem_aresta(e)) {
            return false;
        }
    }

    return true;
}

bool Grafo::eh_caminho(vector<int> &seq_vertices){
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

//grau -> grau_saida
int Grafo::grau_saida(int vertice){
    valida_vertice(vertice);
    int grau = 0;
    for(int i = 0; i < num_vertices_; i++){
        if(matriz_adj_[vertice][i] != 0){
            grau++;
        }
    }
    return grau;
}

//novo metodo. inversao de linha e coluna em comparacao com grau_saida
int Grafo::grau_entrada(int vertice){
    valida_vertice(vertice);
    int grau = 0;
    for(int i = 0; i < num_vertices_; i++){
        if(matriz_adj_[i][vertice] != 0){
            grau++;
        }
    }
    return grau;
}

//Novos metodos para grau minimo e maximo de saida e entrada

int Grafo::grau_saida_min(){
    if(num_vertices_ == 0){return 0;}

    int grau_minimo = INT_MAX;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau_saida(i);
        if(g < grau_minimo){
            grau_minimo = g;
        }
    }
    return grau_minimo;
}

int Grafo::grau_saida_max(){
    int grau_maximo = 0;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau_saida(i);
        if(g > grau_maximo){
            grau_maximo = g;
        }
    }
    return grau_maximo; 
}
int Grafo::grau_entrada_min(){
    if(num_vertices_ == 0){return 0;}

    int grau_minimo = INT_MAX;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau_entrada(i);
        if(g < grau_minimo){
            grau_minimo = g;
        }
    }
    return grau_minimo;
}

int Grafo::grau_entrada_max(){
    int grau_maximo = 0;
    for(int i = 0; i < num_vertices_; i++){
        int g = grau_entrada(i);
        if(g > grau_maximo){
            grau_maximo = g;
        }
    }
    return grau_maximo; 
}

bool Grafo::caminho(int v, int w, int marcado[], std::string str_recursiva) {

    valida_vertice(v);
    valida_vertice(w);

    if(marcado == nullptr) throw invalid_argument("Vetor marcado nao pode ser nulo");

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
    valida_vertice(v);
    if(&pai == &dist) throw invalid_argument("OS vetores pai e dist devem ser diferentes");
    pai.assign(num_vertices_, -1);
    dist.assign(num_vertices_, -1);
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
    valida_vertice(no_origem);
    if(ttl < 0) throw invalid_argument("Valor ttl inválido");

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
