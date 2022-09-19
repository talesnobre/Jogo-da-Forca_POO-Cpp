#include <string>
#include <vector>

using namespace std;

class Arquivo {
    public:
        vector<string> palavras;
        string nomeArquivo;

        Arquivo();

        void leArquivo(string arquivo);
        void adicionaPalavra();
        void salvaArquivo(vector<string> novaLista);
};

class Jogo : public Arquivo {
    private:
        string palavraSecreta;
        map<char, bool> chutou;
        vector<char> chutesErrados;

    public:
        int errosMax = 5;
        Jogo(){};

        void sorteiaPalavra();
        void cabecalho();
        void boneco();

        bool existeLetra(char chute);
        bool naoAcertou();
        bool naoEnforcou();

        void palavra();
        void erros();
        void chuta();

        void dificuldade(int dificuldade);
        void iniciarJogo();
        void iniciarJogo(int vidas);
        string iniciarJogo(string palavra);
};

class ForcaException : public exception {
    private:
        char* erro;

    public:
        ForcaException(char* err) : erro(err) {}
        char* what() {
            return erro;
        }
};