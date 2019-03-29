#include <stdio.h>
#include <stdlib.h>

typedef int TipoL;

typedef struct ListaNo
{
    TipoL info;
    struct ListaNo *prox;
} *pListaNo;

typedef struct TLista
{
    pListaNo primeiro, ultimo, iterador;
    int longitude;
} * Lista;

Lista inicLista()
{

    Lista lst;
    lst=(Lista) malloc(sizeof(struct TLista)); // alocando a struct TLista
    lst->longitude = 0;   // zero elmentos
    lst->iterador = NULL;
    lst->primeiro = NULL;
    lst->ultimo = NULL;
    return lst; // retorna o endereco onde a struct Lista foi alocada
}





int fimLista(Lista lst)
{

    return (lst->iterador == NULL);

}

void segLista(Lista lst)
{

    if(lst->iterador == NULL)
    {
        printf("\n erro: iterador indefindio \n");
    }
    else
    {
        lst->iterador = lst->iterador->prox;
    }
}


//3 casos: Lista vazia, iterador sobre o ultimo elemento, iterador sobre um elemento intermediario
void anxLista( Lista lst, TipoL elem )
{

    //tratamento de erro
    if(lst->iterador == NULL && lst->longitude > 0)
    {
        printf("\n erro: iterador indefinido e lista cheia \n");

    }
    else
    {

        //alocar memória para o novoNo a ser adicionado
        pListaNo novoNo = ( pListaNo )malloc( sizeof( struct ListaNo ) );
        novoNo->info = elem; // atribuir o elemento a ser armazenado
        novoNo->prox= NULL;  // atribuir NULL para deixar o novoNo preparado

        if (lst->longitude == 0)  // lista vazia
        {
            //apontar para o novoNo
            lst->primeiro = novoNo;
            lst->ultimo = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }
        else if (lst->iterador == lst->ultimo )  // iterador sobre o ultimo elemento
        {
            //por no campo prox do ultimo no o endereco do novoNo
            lst->iterador->prox = novoNo;
            //lst->ultimo->prox = novoNo;
            //atualizar o campo ultimo com o endereco do novoNo
            lst->ultimo = novoNo;
            //atualizar o campo iterador com o endereco do novoNo
            lst->iterador = novoNo;
            //incrementar a quantidade de nos
            lst->longitude++;
        }
        else  //iterador sobre um noh intermediario
        {
            // o prox do novoNo aponta para o proximo Noh depois do iterador
            // fazer o prox do iterador apontar para o novoNo
            novoNo->prox = lst->iterador->prox;
            lst->iterador->prox = novoNo;
            lst->iterador = novoNo;
            lst->longitude++;
        }

    }

}







int ordenadaLista(Lista lst1 )
{
    pListaNo p;

    for(p = lst1->primeiro, lst1->iterador = p->prox;!fimLista(lst1); )
    {
        if(p->info > lst1->iterador->info)
            return 0;
        else
            segLista(lst1);
    }
    return 1;

}

int main()
{
    int resultado;
    Lista lst2 = inicLista();
    anxLista(lst2,10);
    anxLista(lst2,20);
    anxLista(lst2,30);
    anxLista(lst2,0);

    resultado = ordenadaLista(lst2);
    if(resultado == 1)
        printf("As listas esta ordenada");
    else
        printf("As listas nao esta ordenada");
    return 0;
}
