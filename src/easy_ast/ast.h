#ifndef AST_H
#define AST_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No{
        char* tipo;
        char* val;

        struct No* irmao;
        struct No* filho;

}no;

no* criar_no(char* tipo,char* val);
void adicionar_irmao(no* n1, no* n2);
void print_AST(no* no, int level);
int contador_irmaos(no* n);
void print_level(int level);
#endif