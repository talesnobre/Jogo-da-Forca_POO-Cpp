// Biblioteca padrão de Entrada e Saída.
#include <iostream>
// Biblioteca para manipular Strings.
#include <string>
// Bibliteca para manipular Arrays.
#include <map>
// Bibliteca para manipular Vetores.
#include <vector>
// Biblioteca para manipular Arquivos.
#include <fstream>
// Biblioteca para obter e manipular funções de data e hora.
#include <ctime>
// Biblioteca de Utilitários gerais padrão.
#include <cstdlib>
// Biblioteca que utilizamos para transformar caracteres.
#include <algorithm>
//
#include "main.hpp"

using namespace std;

template <typename T>
void print(T t) {
    cout << t << endl;
};

Arquivo::Arquivo() { print("Inicializando..."); };

void Arquivo::leArquivo(string nomeArquivo) {
    ifstream arquivo;
    this->nomeArquivo = nomeArquivo;
    try {
        arquivo.open(this->nomeArquivo);

        int quantidadePalavras;
        arquivo >> quantidadePalavras;

        vector<string> palavrasDoArquivo;

        for (int i = 0; i < quantidadePalavras; i++) {
            string palavraLida;
            arquivo >> palavraLida;
            palavrasDoArquivo.push_back(palavraLida);
        }

        arquivo.close();
        this->palavras = palavrasDoArquivo;
    } catch (exception ex) {
        print("Não foi possível acessar o banco de palavras.");
        exit(0);
    }
}

void Arquivo::adicionaPalavra() {
    try {
        print("Digite a nova palavra");
        string novaPalavra;
        cin >> novaPalavra;

        transform(novaPalavra.begin(), novaPalavra.end(), novaPalavra.begin(),
                  ::toupper);

        vector<string> lista_palavras = this->palavras;
        lista_palavras.push_back(novaPalavra);

        this->salvaArquivo(lista_palavras);
    } catch (exception ex) {
        print("Erro ao adicionar palavra ao banco de palavras.");
        exit(0);
    }
}

void Arquivo::salvaArquivo(vector<string> novaLista) {
    try {
        ofstream arquivo;
        arquivo.open(this->nomeArquivo);
        arquivo << novaLista.size() << endl;

        for (string palavra : novaLista) {
            arquivo << palavra << endl;
        }
        arquivo.close();
    } catch (exception ex) {
        print("Não foi possível acessar o banco de palavras.");
        exit(0);
    }
};

void Jogo::cabecalho() {
    print("----------------------");
    print("|                    |");
    print("|   JOGO DA FORCA    |");
    print("|                    |");
    print("----------------------");
    print("");
};

void Jogo::boneco() {
    print(" ________             ");
    print("|         |           ");
    print("|         |           ");
    print("|         |           ");
    print("|         T           ");
    print("|      ___|___         ");
    if (Jogo::chutesErrados.size() == 0) {
        print("|     / -   - \\      ");
        print("|    |  U ^ U  |      ");
        print("|     \\  W   /       ");
        print("|         T           ");
        print("|         |           ");
        print("|        /|\\         ");
        print("|       / | \\        ");
        print("|      /  |  \\       ");
        print("|         |           ");
        print("|         |           ");
        print("|        / \\         ");
        print("|       /   \\        ");
        print("|      |     |        ");
        print("|_    _|     |_       ");
    } else if (Jogo::chutesErrados.size() == 1) {
        print("|     / ^   ^ \\      ");
        print("|    |  o ^ o  |      ");
        print("|     \\  -   /       ");
        print("|         T           ");
        print("|         |           ");
        print("|         |\\         ");
        print("|         | \\        ");
        print("|         |  \\       ");
        print("|         |           ");
        print("|         |           ");
        print("|        / \\         ");
        print("|       /   \\        ");
        print("|      |     |        ");
        print("|_    _|     |_       ");
    } else if (Jogo::chutesErrados.size() == 2) {
        print("|     / `   ´ \\      ");
        print("|    |  O ^ O  |      ");
        print("|     \\ ___   /      ");
        print("|         T           ");
        print("|         |           ");
        print("|         |\\         ");
        print("|         | \\        ");
        print("|         |  \\       ");
        print("|         |           ");
        print("|         |           ");
        print("|        /            ");
        print("|       /             ");
        print("|      |              ");
        print("|_    _|              ");
    } else if (Jogo::chutesErrados.size() == 3) {
        print("|     / \\  /+ \\     ");
        print("|    | Ծ ^ Ծ   |      ");
        print("|     \\  __   /      ");
        print("|         T           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|        /            ");
        print("|       /             ");
        print("|      |              ");
        print("|_    _|              ");
    } else if (Jogo::chutesErrados.size() == 4) {
        print("|     / !! !! \\      ");
        print("|    |  = ^ =  |      ");
        print("|     \\  ☐   /      ");
        print("|         T           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|                     ");
        print("|                     ");
        print("|                     ");
        print("|_                    ");
    } else {
        print("|     / _   _ \\      ");
        print("|    |  + ^ +  |      ");
        print("|     \\  X   /      ");
        print("|         T           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|         |           ");
        print("|                     ");
        print("|                     ");
        print("|                     ");
        print("|_                    ");
    }
    print("");
}

void Jogo::sorteiaPalavra() {
    srand(time(NULL));
    int indiceSorteado = rand() % this->palavras.size();

    this->palavraSecreta = this->palavras[indiceSorteado];
};

bool Jogo::naoAcertou() {
    for (char letra : this->palavraSecreta) {
        if (!chutou[letra])
            return true;
    }
    return false;
};

bool Jogo::naoEnforcou() {
    return this->chutesErrados.size() < this->errosMax;
};

void Jogo::erros() {
    cout << "Chutes errados: ";
    for (char letra : this->chutesErrados) {
        cout << letra << " ";
    }
    print("");
};

void Jogo::palavra() {
    for (char letra : this->palavraSecreta) {
        if (chutou[letra])
            cout << letra << " ";
        else
            cout << "_ ";
    }
    print("");
};

bool Jogo::existeLetra(char chute) {
    for (char letra : this->palavraSecreta) {
        if (chute == letra)
            return true;
    }
    return false;
};

void Jogo::chuta() {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;
    chute = toupper(chute);

    chutou[chute] = true;

    if (this->existeLetra(chute)) {
        print("Você acertou! ;)");
        print("Essa letra esta na palavra!");
    } else {
        print("Voce errou! :(");
        print("Essa letra nao esta na palavra.");
        this->chutesErrados.push_back(chute);
    }
    print("");
};

void Jogo::iniciarJogo() {
    this->cabecalho();
    this->sorteiaPalavra();

    while (this->naoAcertou() && this->naoEnforcou()) {
        this->erros();
        this->palavra();
        this->chuta();
        this->boneco();
    }

    print("Fim de jogo!");
    print("A palavra secreta era: " + this->palavraSecreta);
    if (this->naoAcertou())
        print("Você perdeu! Tente novamente");
    else {
        print("Parabens! :) ");
        print("Você acertou a palavra!");
        bool fim;
        while (!fim) {
            cout << "Voce deseja adicionar uma nova palavra a lista? (S/N) ";
            char resposta;
            cin >> resposta;
            resposta = toupper(resposta);

            if (resposta == 'S') {
                this->adicionaPalavra();
                fim = true;
            } else if (resposta == 'N') {
                print("Obrigado por Jogar!");
                fim = true;
            } else {
                print("Resposta inválida!");
            }
        }
        fim = false;
    }
};

void Jogo::iniciarJogo(int vidas) {
    this->errosMax = vidas;
    this->cabecalho();
    this->sorteiaPalavra();

    while (this->naoAcertou() && this->naoEnforcou()) {
        this->erros();
        this->palavra();
        this->chuta();
        this->boneco();
    }

    print("Fim de jogo!");
    print("A palavra secreta era: " + this->palavraSecreta);
    if (this->naoAcertou())
        print("Voce perdeu! Tente novamente");
    else {
        print("Parabens! :) ");
        print("Voce acertou a palavra!");
        bool fim;
        while (!fim) {
            cout << "Voce deseja adicionar uma nova palavra a lista? (S/N) ";
            char resposta;
            cin >> resposta;
            resposta = toupper(resposta);

            if (resposta == 'S') {
                this->adicionaPalavra();
                fim = true;
            } else if (resposta == 'N') {
                print("Obrigado por Jogar!");
                fim = true;
            } else {
                print("Resposta inválida!");
            }
        }
        fim = false;
    }
};

string Jogo::iniciarJogo(string palavra) {
    this->cabecalho();
    this->palavraSecreta = palavra;

    while (this->naoAcertou() && this->naoEnforcou()) {
        this->erros();
        this->palavra();
        this->chuta();
        this->boneco();
    }

    print("Fim de jogo!");
    print("A palavra secreta era: " + this->palavraSecreta);
    if (this->naoAcertou())
        print("Voce perdeu! Tente novamente");
    else {
        print("Parabens! :) ");
        print("Voce acertou a palavra!");
        bool fim;
        while (!fim) {
            cout << "Voce deseja adicionar uma nova palavra a lista? (S/N) ";
            char resposta;
            cin >> resposta;
            resposta = toupper(resposta);

            if (resposta == 'S') {
                this->adicionaPalavra();
                fim = true;
            } else if (resposta == 'N') {
                print("Obrigado por Jogar!");
                fim = true;
            } else {
                print("Resposta inválida!");
            }
        }
        fim = false;
    }
};

void Jogo::dificuldade(int dificuldade) {
    print("----------------------");
    if (dificuldade == 0) {
        this->leArquivo("facil.txt");
        print("|      F A C I L     |");
    } else if (dificuldade == 1) {
        this->leArquivo("medio.txt");
        print("|      M E D I O     |");
    } else if (dificuldade == 2) {
        this->leArquivo("dificil.txt");
        print("|    D I F I C I L   |");
    } else {
        throw ForcaException("Dificuldade não existente!");
    }
};

int main() {
    Jogo jogo;
    int dif;
    print("Qual dificuldade voce deseja jogar?");
    print("0 - Facil    1 - Medio    2 - Dificil");
    cin >> dif;

    try {
        jogo.dificuldade(dif);
    } catch (ForcaException ex) {
        cout << ex.what() << endl;
        jogo.dificuldade(0);
    }

    jogo.iniciarJogo();   

    return 0;
};