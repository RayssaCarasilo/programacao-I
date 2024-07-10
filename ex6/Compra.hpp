#ifndef COMPRA_HPP
#define COMPRA_HPP

#include "Anuncio.hpp"
#include <string>

class Compra {
public:
    Anuncio anuncio;
    std::string data;

    Compra(const Anuncio& anuncio, const std::string& data);
};

#endif // COMPRA_HPP