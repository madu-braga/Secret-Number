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
        printf("-------- Adivinhe o número --------\n\n");
        cout<<"Record até o momento: "<< record <<" tentativa(s)!"<<endl;
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

int palpite(int tent)
{
    int palp;
    cout<<"\nTente adivinhar o número de 1 até 100."<<endl;
    
    printf("Tentativa %d: ", tent);
    cin >> palp;
    
    if(palp>0 && palp<=100)
        return palp;
    else
        cout<<"Só vale números de 1 até 100"<<endl;
}

int checa(int gerado, int palp)
{
    if(gerado == palp)
        return 1;
    else
        return 0;
}

void dica(int gerado, int palp)
{
    if(palp<gerado)
        cout<<"ERROU! Seu palpite foi MENOR que o número sorteado!"<<endl;
    else
        if(palp>gerado)
            cout<<"ERROU! Seu palpite foi MAIOR que o número sorteado!"<<endl;
        else
            cout<<"Parabéns, você acertou o número!"<<endl;
}

void encerra(int tent)
{
    cout<<"\nVocê acertou em "<<tent<<" tentativa(s)!"<<endl;

    if(record==0)
        record = tent;

    if(tent<=record){
        cout<<"Parabéns! O record é seu!"<<endl;
        record = tent;
    }
    else
        cout<<"O record ainda é de "<<record<<" tentativa(s)"<<endl;
}

int continuar()
{
    int cont=1;

    cout<<"\nJogar de novo?"<<endl;
    cout<<"0. Sair"<<endl;
    cout<<"1. De novo!"<<endl;
    cin >> cont;

    return cont;
}
