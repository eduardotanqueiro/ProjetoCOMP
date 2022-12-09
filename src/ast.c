//  Eduardo Carneiro - 2020240332
//  Ricardo Silva - 2020227184
#include "ast.h"

info *gen_token(char *val, int line, int col)
{

    info *tok = (info *)malloc(sizeof(info));
    tok->val = (char *)strdup(val);
    tok->line = line;
    tok->col = col;

    return tok;
}

no *criar_no(char *tipo, info *tok)
{

    no *novo_no = (no *)malloc(sizeof(no));

    novo_no->filho = NULL;
    novo_no->irmao = NULL;
    novo_no->tipo = (char *)strdup(tipo);

    novo_no->info = tok;

    novo_no->notation = NULL;
    novo_no->is_valid = 1;

    return novo_no;
}

void adicionar_irmao(no *n1, no *n2)
{

    no *tmp = n1;

    while (tmp->irmao != NULL)
    {
        tmp = tmp->irmao;
    }

    tmp->irmao = n2;
}

int contador_irmaos(no *n)
{

    int contador = 0;
    no *aux = n;

    while (aux != NULL)
    {
        contador++;
        aux = aux->irmao;
    }

    return contador;
}

void print_level(int level)
{

    for (int i = 0; i < level; i++)
        printf("..");
}

void print_AST(no *no, int level)
{
    print_level(level);

    // if(no == NULL){
    //     //printf("null\n");
    //     return;
    // }
    if (no->notation == NULL)
    {
        if (strcmp(no->info->val, ""))
        {
            printf("%s(%s)\n", no->tipo, no->info->val);
        }
        else
        {
            printf("%s\n", no->tipo);
        }
    }
    else
    {
        if (strcmp(no->info->val, ""))
        {
            printf("%s(%s) - %s\n", no->tipo, no->info->val, no->notation);
        }
        else
        {
            printf("%s - %s\n", no->tipo, no->notation);
        }
    }

    if (no->filho)
        print_AST(no->filho, level + 1);
    if (no->irmao)
        print_AST(no->irmao, level);

    // if printTree and hasError==False limpa a memória depois de printar!!
    free(no);
}

/*
void print_AST(no *no, int level)
{
    print_level(level);

    // if(no == NULL){
    //     //printf("null\n");
    //     return;
    // }

    if (strcmp(no->info->val,"") )
    {
        printf("%s(%s)\n", no->tipo, no->info->val);
    }
    else{
        printf("%s\n", no->tipo);
    }

    if (no->filho)
        print_AST(no->filho, level + 1);
    if (no->irmao)
        print_AST(no->irmao, level);

    // if printTree and hasError==False limpa a memória depois de printar!!
    free(no);
}
*/