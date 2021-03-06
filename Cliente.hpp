#include <utility>


#ifndef HOTEL_ESTOQUE_HPP
#define HOTEL_ESTOQUE_HPP
#include <iostream>
#include <stdio.h>
#include "Fila.hpp"
#include "Money.hpp"
using namespace std;
/*
 * essa classe é para administar o estoque, toalhas, papel, comida por exemplo
 */
class Cliente {
public:

/*
     * essa funcao adiciona novos clientes
     */
    void addFILA(string nome, int dia, int mes, int ano,int idade,
                 string doc,string city,string estado,string tel, string cel,string email,bool sexo){
        gente.insere(nome,dia,mes,ano,idade,doc,city,estado,tel,cel,email,sexo);
    }

    //essa funcao apenas imprime o estoque ja cadastrado
    void imprimeClientes(){
       gente.imprime2();
    }

    void removeCliente(string nome,string doc){
        gente.remove1(nome,doc);

    }

    void busca(string nome, string RG){
     gente.busca(nome,RG);
    }
    
private:

    Fila gente;

};


#endif //HOTEL_ESTOQUE_HPP
