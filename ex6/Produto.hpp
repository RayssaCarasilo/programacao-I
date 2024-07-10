#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto {
public:
    std::string nome;
    float preco;

    Produto(const std::string& nome, float preco);
};

#endif