#include "ast.h"

no* criar_no(char* tipo,char* val){

    no* novo_no = (no*)malloc(sizeof(no));

    novo_no->filho = NULL;
    novo_no->irmao = NULL;
    novo_no->tipo = (char*)strdup(tipo);
    novo_no->val = (char*)strdup(val);

    return novo_no;
}

void adicionar_irmao(no* n1, no* n2){

    no* tmp= n1;

    while(tmp->irmao != NULL){
        tmp = tmp->irmao;
    }

    tmp->irmao = n2;
}

void print_AST(no* raiz){
    
}
