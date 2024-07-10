#include "Anuncio.hpp"

Anuncio::Anuncio(const Produto& produto, const std::string& descricao)
    : produto(produto), descricao(descricao) {}