#ifndef AST_H
#define AST_H

typedef struct No{
        char* tipo;
        char* val;

        struct No* irmao;
        struct No* filho;

}no;

no* criar_no(char* tipo);
void adicionar_irmao(no* n1, no* n2);
#endif