#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"

typedef struct _t3{
	char* name;
	char* type;
	struct _t3* next;
} vars;

typedef struct _t2{
	char *name;
	char* return_type;

	struct vars* params_list;
	struct vars* vars_list;
	struct _t2* next;
} method;

typedef struct _t1{
	char* name;
	method* method_list;
} table_class;

void semanticAnalysis(no* raiz);
table_class* inicialize_class_table(char *name);
method* inicialize_method_table(char*return_type,char *name);
void insert_method_on_class(method* metodo);
vars* inicialize_var_table(char *name,char*type);
void insert_varparam_on_method(vars*var,method* metodo);
void print_tables();

// table_element *insert_el(char *str, basic_type t);
// void show_table();
// table_element *search_el(char *str);

#endif
