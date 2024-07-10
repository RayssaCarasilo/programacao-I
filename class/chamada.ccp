#include <iostream>
#include <vector>
#include "Chamada.hpp"
#include "classFunc.hpp"


Chamada::Chamada(int _dtaEmprestimo[3], int _idLivro, int _idUsuario){
    dtaEmprestimo[0] = _dtaEmprestimo[0];
    dtaEmprestimo[1] = _dtaEmprestimo[1];
    dtaEmprestimo[2] = _dtaEmprestimo[2];
    adicionarDias(dtaEmprestimo, 15, &dtaVenc); //15 dias à data de empréstimo
    idLivro = _idLivro;
    idUsuario = _idUsuario;
    status = true;
    atrasado = false;
}

int* Chamada::getDtaVenc(){
    return dtaVenc;
}

void Chamada::setDtaVenc(int &_dtaVenc){
    *dtaVenc = _dtaVenc;
}

int* Chamada::getDtaEmprestimo(){
    return dtaEmprestimo;
}

int Chamada::getIdLivro(){
    return idLivro;
}

int Chamada::getIdUsuario(){
    return idUsuario;
}

bool Chamada::getStatus(){
    return status;
}

void Chamada::setStatus(){ // Altera o estado de atraso da chamada. Se estiver atrasado, define como não atrasado, e vice-versa.
    if (status)
    {
        status = false;
    }
    else
    {
        status = true;
    }
}

bool Chamada::getAtrasado(){
    return atrasado;
}

void Chamada::setAtrasado(){
    if (atrasado)
    {
        atrasado = false;
    }
    else
    {
        atrasado = true;
    }
}

int Chamada::getId(){
    return id;
}

void Chamada::setId(vector<Chamada> &Chamadas){ //Define o identificador da chamada com base nas informações de livro, usuário e data de empréstimo. Percorre o vetor de chamadas Chamadas e encontra a chamada correspondente aos critérios especificados.
    for (int i = 0; i < Chamadas.size(); i++)
    {
        if (Chamadas.at(i).getIdLivro() == idLivro and Chamadas.at(i).getIdUsuario() == idUsuario and dtaEmprestimo == Chamadas.at(i).getDtaEmprestimo())
        {
            id = i;
        }
    }
}