#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include <stdbool.h>

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

	int line;
	int col;

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
char* search_symbol(tab_element* func, char* name, int isVar, int inMethod);
char* search_method(tab_element* func, char* name, char* params_list);
void make_notations_ast(no* node, tab_element* elem, char* func);
void check_two_part_op(no* node,char* func_name, int isLogical);
void check_one_part_op(no* node, char* func_name, int isLogical);
char* get_var_type(no* var_node,char* func_name);
int one_part_op(char* tipo);
int two_part_op(char* tipo);
bool isIntDoubleBool(no* node);
bool check_compatible_type(char* func_param, char* call_variable);
int count_number_char(char* str, char chr);
void check_call(no* node, tab_element* elem, char* func_name);
char* get_node_operator(char* tipo_no);
#endif
