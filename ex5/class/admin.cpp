#include <iostream>
#include <vector>
#include <string>
#include "admin.hpp"
#include "usuario.hpp"
#include "livro.hpp"
#include "chamada.hpp"
#include "classF.hpp"

using namespace std;

// Construtor da classe Admin
Admin::Admin(string _nome, string _senha)
{
    nome = _nome;
    senha = _senha;
}

// Método para obter a senha do administrador
string Admin::getSenha()
{
    return senha;
}

// Método para cadastrar um novo usuário
Usuario Admin::cadastrarUsuario()
{
    string nome;
    string senha;
    int dtaNascimento[3];
    string email;
    string telefone;

    // Solicita informações do usuário ao administrador
    cout << "Digite o nome do Usuario: ";
    getline(cin, nome);
    cout << "Digite a senha do Usuario: ";
    cin >> senha;
    cout << "Digite o dia de nascimento do Usuario: ";
    cin >> dtaNascimento[0];
    cout << "Digite o mes de nascimento do Usuario: ";
    cin >> dtaNascimento[1];
    cout << "Digite o ano de nascimento do Usuario: ";
    cin >> dtaNascimento[2];
    cout << "Digite o email do Usuario: ";
    cin >> email;
    cout << "Digite o telefone do Usuario: ";
    cin >> telefone;

    // Limpa o buffer do teclado
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cria um objeto Usuario com as informações fornecidas e o retorna
    Usuario user(nome, senha, dtaNascimento, email, telefone);
    return user;
}

// Método para deletar um usuário existente
void Admin::deletarUsuario(vector<Usuario> &Usuarios)
{
    string nome;
    int op;

    // Solicita o nome do usuário a ser deletado
    cout << "Digite o nome do Usuario que deseja deletar: ";
    getline(cin, nome);

    // Percorre o vetor de usuários procurando pelo nome informado
    for (int i = 0; i < Usuarios.size(); i++)
    {
        if (Usuarios.at(i).nome == nome)
        {
            // Remove o usuário do vetor caso seja encontrado
            Usuarios.erase(Usuarios.begin() + i);
            cout << "Usuario deletado com sucesso!" << endl;
            return;
        }
    }

    // Caso o usuário não seja encontrado, oferece a opção de tentar novamente
    cout << "Usuario nao encontrado!" << endl;
    cout << "Tentar novamente? (1 - sim, 0 - nao)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Se o usuário optar por tentar novamente, chama recursivamente o método
    if (op == 1)
    {
        deletarUsuario(Usuarios);
    }
}

// Método para cadastrar um novo livro
Livro Admin::novoLivro()
{
    string titulo;
    string autor;
    string editora;
    string publicacao;
    string isbn;

    // Solicita informações do livro ao administrador
    cout << "Digite o titulo do Livro: ";
    getline(cin, titulo);
    cout << "Digite o autor do Livro: ";
    getline(cin, autor);
    cout << "Digite a editora do Livro: ";
    getline(cin, editora);
    cout << "Digite a data de publicacao do Livro: ";
    getline(cin, publicacao);
    cout << "Digite o ISBN do Livro: ";
    cin >> isbn;

    // Limpa o buffer do teclado
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cria um objeto Livro com as informações fornecidas e o retorna
    Livro book(titulo, autor, editora, publicacao, isbn);
    return book;
}

// Método para deletar um livro existente
void Admin::deletarLivro(vector<Livro> &Livros)
{
    string titulo;
    int op;

    // Solicita o título do livro a ser deletado
    cout << "Digite o titulo do Livro que deseja deletar: ";
    getline(cin, titulo);

    // Percorre o vetor de livros procurando pelo título informado
    for (int i = 0; i < Livros.size(); i++)
    {
        if (Livros.at(i).titulo == titulo)
        {
            // Remove o livro do vetor caso seja encontrado
            Livros.erase(Livros.begin() + i);
            cout << "Livro deletado com sucesso!" << endl;
            return;
        }
    }

    // Caso o livro não seja encontrado, oferece a opção de tentar novamente
    cout << "Livro nao encontrado!" << endl;
    cout << "Tentar novamente? (1 - sim, 0 - nao)" << endl;
    cin >> op;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Se o usuário optar por tentar novamente, chama recursivamente o método
    if (op == 1)
    {
        deletarLivro(Livros);
    }
}

// Método para registrar um novo empréstimo de livro
Chamada Admin::novoEmprestimo(vector<Livro> &Livros, vector<Usuario> &Usuarios, int livroID, int usuarioId)
{
    int dtaEmprestimo[3];

    // Solicita a data de empréstimo ao administrador
    cout << "Digite o dia de emprestimo: " << endl;
    cin >> dtaEmprestimo[0];
    cout << "Digite o mes de emprestimo: " << endl;
    cin >> dtaEmprestimo[1];
    cout << "Digite o ano de emprestimo: " << endl;
    cin >> dtaEmprestimo[2];

    // Limpa o buffer do teclado
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Cria um objeto Chamada com as informações fornecidas e o retorna
    Chamada call(dtaEmprestimo, livroID, usuarioId);
    return call;
}