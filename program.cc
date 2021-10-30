#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int record=0;

void limpa();       // Limpa a tela
int gerar();        // Sorteia o número
int palpite(int);   // Pega o palpite do usuário
int checa(int, int);// Checa se errou ou acertou
void dica(int, int);// Da a dica se o número é maior ou menor
void encerra(int);  // Exibe as informações da partida
int continuar();    // Opção de jogar novamente

int main()
{
    int tentativas,
        gerado,
        palp;

    do{
        limpa();
        tentativas=0;
        cout<<"Record até o momento: "<< record <<" tentativas!"<<endl;
        gerado = gerar();
        cout<<"\nNúmero sorteado! "<<endl;

        do{
            tentativas++;
            palp = palpite(tentativas);
            dica(gerado, palp);
        }while(checa(gerado, palp) != 1);

        encerra(tentativas);
    }while( continuar() );

    return 0;
}

void limpa()
{
    if(system("CLS")) system("clear");
}

int gerar()
{
    unsigned seed = time(0);
    srand(seed);

    return 1+rand()%100;
}
