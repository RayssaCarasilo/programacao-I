#include "Usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password,
                 const std::string& email, const std::string& phone,
                 const std::string& addr, const std::string& cpf)
    : login(login), password(password), email(email), phone(phone), addr(addr), cpf(cpf) {}

Anuncio Usuario::criarAnuncio(const Produto& produto, const std::string& descricao) {
    Anuncio anuncio(produto, descricao);
    anuncios.push_back(anuncio);
    return anuncio;
}

bool Usuario::deletarAnuncio(const Anuncio& anuncioDeletar) {
    for (auto it = anuncios.begin(); it != anuncios.end(); ++it) {
        if (it->descricao == anuncioDeletar.descricao) {  // Simplificação
            anuncios.erase(it);
            return true;
        }
    }
    return false;
}

Compra Usuario::comprar(const Anuncio& anuncioComprar) {
    Compra compra(anuncioComprar, "2024-07-09");  // Data fixa para simplificação
    compras.push_back(compra);
    return compra;
}

bool Usuario::cancelarCompra(const Compra& compraCancelar) {
    for (auto it = compras.begin(); it != compras.end(); ++it) {
        if (it->data == compraCancelar.data) {  // Simplificação
            compras.erase(it);
            return true;
        }
    }
    return false;
}

bool Usuario::favoritar(const Anuncio& anuncioFavoritar) {
    favoritos.push_back(anuncioFavoritar);
    return true;
}