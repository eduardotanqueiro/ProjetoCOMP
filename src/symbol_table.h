#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H


typedef struct _t3{
	char* name;
	char* type;
	_t3* next;
} vars;

typedef struct _t2{
	char *name;
	char* return_type;

	struct vars* params_list;
	struct vars* vars_list;
	_t2* next;
} method;

typedef struct _t1{
	char* name;
	method* method_list;
} table_class;



table_element *insert_el(char *str, basic_type t);
void show_table();
table_element *search_el(char *str);

#endif
