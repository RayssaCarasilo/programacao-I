#include "Produto.hpp"
#include "Usuario.hpp"
#include "Anuncio.hpp"
#include "Compra.hpp"

int main() {
    Produto produto("Notebook", 3000.00);
    Usuario usuario("user1", "pass1", "user1@example.com", "123456789", "Address 1", "123.456.789-00");

    Anuncio anuncio = usuario.criarAnuncio(produto, "Notebook usado em bom estado");
    usuario.favoritar(anuncio);
    Compra compra = usuario.comprar(anuncio);

    usuario.cancelarCompra(compra);
    usuario.deletarAnuncio(anuncio);

    return 0;
}