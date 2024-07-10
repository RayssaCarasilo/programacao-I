#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "Anuncio.hpp"
#include "Compra.hpp"
#include <string>
#include <vector>

class Usuario {
public:
    std::string login;
    std::string password;

protected:
    std::string email;
    std::string phone;
    std::string addr;
    std::string cpf;
    std::vector<Anuncio> favoritos;
    std::vector<Anuncio> anuncios;
    std::vector<Compra> compras;

public:
    Usuario(const std::string& login, const std::string& password,
            const std::string& email, const std::string& phone,
            const std::string& addr, const std::string& cpf);

    Anuncio criarAnuncio(const Produto& produto, const std::string& descricao);
    bool deletarAnuncio(const Anuncio& anuncioDeletar);
    Compra comprar(const Anuncio& anuncioComprar);
    bool cancelarCompra(const Compra& compraCancelar);
    bool favoritar(const Anuncio& anuncioFavoritar);
};

#endif // USUARIO_HPP