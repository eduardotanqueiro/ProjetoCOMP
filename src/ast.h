    //  Eduardo Carneiro - 2020240332
    //  Ricardo Silva - 2020227184
#ifndef AST_H
#define AST_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct info{
    char* val;
    int line;
    int col;
}info;

typedef struct No{
        char* tipo;
        info* info;

        struct No* irmao;
        struct No* filho;

        char* notation;
        int is_valid; //aux variable for errors on duplicate methods
}no;

no* criar_no(char* tipo, info* info);
void adicionar_irmao(no* n1, no* n2);
void print_AST(no* no, int level);
int contador_irmaos(no* n);
void print_level(int level);
info* gen_token(char* val, int line, int col);
#endif