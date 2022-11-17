#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

#define PARAMS_BUFFER_SIZE 512

// typedef struct _t3{
// 	char* name;
// 	char* type;
// 	struct _t3* next;
// } vars;

// typedef struct _t2{
// 	char *name;
// 	char* return_type;

// 	struct vars* params_list;
// 	struct vars* vars_list;
// 	struct _t2* next;
// } method;

// typedef struct _t1{
// 	char* name;
// 	method* method_list;
// } table_class;

typedef struct _t{
	char* name; //para variaveis, metodos ou classes
	char* params_list; //lista dos parametros do metodo
	char* type; //para os metodos e variaveis
	int is_param;

	struct _t* body; //para os metodos, ponteiro para o body
	struct _t* next; //ponteiro para o proximo elemento da tabela, ou entao proxima variavel/parametro do metodo

}tab_element;

tab_element* insert_element( tab_element* tail, tab_element* new);
void create_table(tab_element* tail, no* raiz);
tab_element* create_element(char* name, char* params_list, char* type, int is_param);
void add_method(tab_element* tail, no* node);
void get_method_meader(tab_element* method_node, no* no_ast);
void get_method_vars(tab_element* method_node, no* no_ast);
void add_vars(tab_element* tail, no* no_ast);
void printSymbolTable(tab_element* elem);
char* get_type(char* original_type);
#endif
