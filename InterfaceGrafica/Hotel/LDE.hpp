#include <iostream>
#include "No.hpp"

#ifndef LDE_HPP
#define LDE_HPP

using namespace std;

class LDE: public No{
private:
    int n;
    No* primeiro;

public:
    LDE() : n(0), primeiro(nullptr){

    }

    bool insere(string senha, string cargo, string nome){
        No* novo = (No*)malloc(sizeof(No));
        novo->escravo.nome = nome;
        novo->escravo.senha = senha;
        novo->escravo.cargo = cargo;


        if(novo == nullptr)
            return false;

        No* anterior = nullptr;
        No* atual = primeiro;

        while(atual){
            anterior = atual;
            atual = atual->proximo;
        }
        novo->proximo = atual;
        if(anterior!=nullptr){
            anterior->proximo = novo;
        }else{
            primeiro = novo;
        }
        n++;
        return true;
    }



    bool remove(string nome,string cargo) {
        No *atual = primeiro;
        No *fututo = primeiro->proximo;
        bool ok = false;
        while (atual) {
            if ((fututo->escravo.nome == nome+"\n") && (fututo->escravo.cargo == cargo+"\n")) {
                No *aux = fututo;
                atual->proximo = fututo->proximo;
                delete fututo;
                puts("contato apagado");
                ok = true;
                break;
            }
            atual = atual->proximo;
            fututo = atual->proximo;
        }
        imprime();
        return ok;
    }

    void imprime(){
        No* atual = primeiro;
        while(atual){
            cout << atual->escravo.nome << " ";
            atual = atual->proximo;
        }
        cout << endl;
    }



    virtual ~LDE(){
        No* atual = primeiro;
        No* prox;
        while(atual){
            prox = atual->proximo;
            delete atual;
            atual = prox;
        }
    }

};

#endif
