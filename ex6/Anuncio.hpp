#ifndef ANUNCIO_HPP
#define ANUNCIO_HPP

#include "Produto.hpp"
#include <string>

class Anuncio {
public:
    Produto produto;
    std::string descricao;

    Anuncio(const Produto& produto, const std::string& descricao);
};

#endif // ANUNCIO_HPP