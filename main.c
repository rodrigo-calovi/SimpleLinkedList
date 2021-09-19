//Rodrigo Britto Calovi
//UERGS - Universidade Estadual do Rio Grande do Sul
//Prof. Dra. Fabrícia Damando
//Disciplina: Estrutura de dados

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dados;
    struct nodo *proximo;
}nodo, inicio, fim;

int menu();
int solicitaValor();
void criaLista(struct nodo **inicio, struct nodo **fim);
void addListaDireita(struct nodo **inicio, struct nodo **fim, int valor);
void addListaEsquerda(struct nodo **inicio, struct nodo **fim, int valor);
void inserirEntreAdireita(struct nodo **inicio, struct nodo **fim, int valor, int posicao);
void inserirEntreAEsquerda(struct nodo **inicio, struct nodo **fim, int valor, int posicao);
nodo* removeValor(struct nodo **inicio, struct nodo **fim, int valor);
nodo* removeDoInicio(struct nodo **inicio, struct nodo **fim);
nodo* removeDoFim(struct nodo **inicio, struct nodo **fim);
void limpaTela();
void limparLista(struct nodo **inicio, struct nodo **fim);
void imprimeLista(struct nodo **inicio, struct nodo **fim);

//principal
int main(){

    limpaTela();

    nodo *inicio, *fim;
    nodo *elementoRemovido;
    int valor,valor2;
    int op;

    criaLista(&inicio,&fim);

    do{
        op=menu();
        switch (op){
          //sair
          case 0:
                break;

          //adiciona a esquerda
          case 1:
                addListaEsquerda(&inicio,&fim,solicitaValor());
                limpaTela();
                imprimeLista(&inicio,&fim);
                break;

          //adiciona direita
          case 2:
                addListaDireita(&inicio,&fim,solicitaValor());
                limpaTela();
                imprimeLista(&inicio,&fim);
                break;

          //adiciona entre valor (direita)
          case 3:
                valor = solicitaValor();
                printf("\nPosicao do elemento anterior, \n");
                valor2 = solicitaValor();
                inserirEntreAdireita(&inicio, &fim, valor, valor2);
                limpaTela();
                imprimeLista(&inicio,&fim);
                break;

          //adiciona entre valor (esquerda)
          case 4:
                valor = solicitaValor();
                printf("\nPosicao do elemento anterior, \n");
                valor2 = solicitaValor();
                inserirEntreAEsquerda(&inicio, &fim, valor, valor2);
                limpaTela();
                imprimeLista(&inicio,&fim);
                break;

          //remove por valor
          case 5:
                valor = solicitaValor();
                elementoRemovido = removeValor(&inicio,&fim,valor);
                limpaTela();
                if(elementoRemovido){
                    printf("\nValor removido: %d\n",elementoRemovido->dados);
                    free(elementoRemovido);
                }else{
                    printf("\nElemento %d nao existe!\n", valor);
                }
                imprimeLista(&inicio,&fim);
                break;

          //remove do inicio
          case 6:
                elementoRemovido = removeDoInicio(&inicio,&fim);
                limpaTela();
                if(elementoRemovido){
                    printf("\nValor removido: %d\n",elementoRemovido->dados);
                    free(elementoRemovido);
                }else{
                    printf("\nLista esta vazia\n");
                }
                imprimeLista(&inicio,&fim);
                break;

          //remove do fim
          case 7:
                elementoRemovido = removeDoFim(&inicio,&fim);
                limpaTela();
                if(elementoRemovido){
                    printf("\nValor removido: %d\n",elementoRemovido->dados);
                    free(elementoRemovido);
                }else{
                    printf("\nLista esta vazia\n");
                }
                imprimeLista(&inicio,&fim);
                break;

          //limpar tela
          case 8:
                limpaTela();
                limparLista(&inicio,&fim);
                break;

          //limpa tela
          case 9:
                limpaTela();
                imprimeLista(&inicio,&fim);
                break;

          default:
                printf("\n[38;5;150mDigite uma opcao do menu![0m\n\n");
                limpaTela();
                break;
        }
    }while(op!=0);

    return 0;
}

//menu
int menu(){

    int op;
    printf("\n[38;5;11m---------Menu---------[0m");
    printf("\n[38;5;100m0[0m - Sair             ");
    printf("\n[38;5;100m1[0m - Insere no inicio");
    printf("\n[38;5;100m2[0m - Insere no final ");
    printf("\n[38;5;100m3[0m - Insere entre valores a direita");
    printf("\n[38;5;100m4[0m - Insere entre valores a esquerda");
    printf("\n[38;5;100m5[0m - Remover item por valor");
    printf("\n[38;5;100m6[0m - Remover do inicio");
    printf("\n[38;5;100m7[0m - Remover do fim   ");
    printf("\n[38;5;100m8[0m - Limpar lista     ");
    printf("\n[38;5;100m9[0m - Imprimir Lista   ");
    printf("\n\nOpcao: [38;5;100m");
    scanf("%d",&op);
    printf("[0m\n");
    return op;
}

//solicita valor para adicionar na lista
int solicitaValor(){
    int valor;
    printf("Digite um valor: ");
    scanf("%d",&valor);
    return valor;
}

//Cria lista
void criaLista(struct nodo **inicio, struct nodo **fim){
    *inicio =NULL;
    *fim =NULL;
}

//addListaDireita
void addListaDireita(struct nodo **inicio, struct nodo **fim, int valor){
    struct nodo *p;
    p = (struct nodo*) malloc(sizeof(struct nodo));
    if(p){
        p->dados = valor;
        p->proximo = NULL;
        if(*inicio == NULL){
            *inicio = p;
        } else {
            (*fim)->proximo = p;
        }
        *fim = p;
    }
}

//adiciona na esquerda
void addListaEsquerda(struct nodo **inicio, struct nodo **fim, int valor){
    struct nodo *p;
    p = (struct nodo*) malloc(sizeof(struct nodo));
    if(p){
        p->dados = valor;
        p->proximo = NULL;
        if(*inicio == NULL){
            *inicio = p;
            *fim = p;
        } else {
             p->proximo = *inicio;
        }
        *inicio = p;
    }
}

//inserir entre (direita) - valor = valor a inserer, ant = valor de posicao
void inserirEntreAdireita(struct nodo **inicio, struct nodo **fim, int valor, int posicao){

    nodo *aux, *novo = (nodo*)malloc(sizeof(nodo));

    if(novo != NULL){
        novo->dados = valor;
        //eh o primeiro
        if(*inicio == NULL){
            novo->proximo = NULL;
            *inicio = novo;
            *fim = novo;
        } else {
            aux = *inicio;

            while((aux->dados != posicao) && (aux->proximo != NULL)){
                aux = aux->proximo;
            }

            if(aux->dados == posicao){
                //se ultimo elemento
                if(aux->proximo == NULL){
                    *fim = novo;
                }

                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }


    }
}

//insere entre (esquerda)
void inserirEntreAEsquerda(struct nodo **inicio, struct nodo **fim, int valor, int posicao){

    nodo *aux,*p, *novo = NULL;
    novo = (nodo*)malloc(sizeof(nodo));

    novo->dados = valor;

    aux = *inicio;
    //eh o primeiro
    if(*inicio == NULL){
        novo->proximo = NULL;
        *inicio = novo;
        *fim = novo;
        //insere no meio
    } else if(aux->dados != posicao && aux->proximo != NULL) {

        while(aux->dados != posicao && aux->proximo != NULL){
            p = aux;
            aux = aux->proximo;
        }

        if(aux->dados == posicao){
            p->proximo = novo;
            novo->proximo = aux;
        }
    //insere no inicio se existe 1 elemento
    } else if (((aux->proximo == NULL) || (aux->proximo != NULL)) && aux->dados == posicao){
        novo->proximo = aux;
        *inicio = novo;
    }
}

//remove item pelo valor
nodo* removeValor(struct nodo **inicio, struct nodo **fim, int valor){

    nodo *aux;
    nodo *remover = NULL;

    if(*inicio){
        if((*inicio)->dados == valor){

            remover = *inicio;
            *inicio = remover->proximo;

            if(remover->proximo == NULL){
                *fim = NULL;
            }

        } else {

            aux = *inicio;

            while(aux->proximo && aux->proximo->dados != valor){
                aux = aux->proximo;
            }

            if(aux->proximo != NULL ){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo == NULL){
                    *fim = aux;
                }
            }
        }
    }

    return remover;
}

//remove do inicio
nodo* removeDoInicio(struct nodo **inicio, struct nodo **fim){
    nodo *aux = NULL;

    if(*inicio != NULL){
        aux = *inicio;
        *inicio = aux->proximo;
        if(aux->proximo == NULL){
            *inicio = NULL;
            *fim = *inicio;
        }
    }

    return aux;
}

//remove do fim
nodo* removeDoFim(struct nodo **inicio, struct nodo **fim){

    nodo *aux, *p;
    nodo *remove = NULL;
    //remove = (struct nodo*)malloc(sizeof(struct nodo));
    //remove = *inicio;

    if(*inicio){
        //so um elemento
        if((*inicio)->proximo == NULL){
            remove = *inicio;
            //free(*inicio);
            *inicio = NULL;
            *fim = NULL;
            //printf("Elemento %d removido", remove->dados );
            return remove;

        } else if((*inicio)->proximo != NULL){

            p = *inicio;

            while(p->proximo != NULL){
                remove = p->proximo;
                aux = p;
                p = p->proximo;
            }

            aux->proximo = NULL;
            *fim = aux;
            //free(p);
        }
    }

    return remove;
}

//limpa tela
void limpaTela(){
    system("cls");
}

//limpar lista
void limparLista(struct nodo **inicio, struct nodo **fim){
    struct nodo *aux;
    aux = *inicio;
    while(aux){
        *inicio = (*inicio)->proximo;
        free(aux);
        aux = *inicio;
    }
    *fim = NULL;
}

//Imprime lista
void imprimeLista(struct nodo **inicio,struct nodo **fim){
    struct nodo *prox;
    //imprime lista Horizontal
    printf("\n[38;5;11mLista Simples Encadeada:[0m\n");
    printf("\n[38;5;100mL: [0m");
    prox = *inicio;
    while(prox !=NULL){
        printf("[38;5;85m%i [0m ", prox->dados);
        prox = prox->proximo;
    }
    printf("\n");
    //imprime lista vertical
    prox = *inicio;
    printf("\n[38;5;100mInicio da lista[0m\n");
    while(prox !=NULL){
        printf("  [38;5;75m%i[0m = [38;5;85m%i[0m -> [38;5;75m%i\n[0m", prox, prox->dados, prox->proximo);
        prox = prox->proximo;
    }
    printf("[38;5;100mfim da lista[0m\n\n");

    printf("\n\ninicio: %d - fim: %d ", *inicio, *fim);
}
