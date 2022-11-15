#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef enum {integer, character, doub} basic_type;

typedef struct _t2{

} MethodParam;

typedef struct _t1{
	char *name;
	char* type;

	basic_type type;
	struct _t1 *next;
} element;


table_element *insert_el(char *str, basic_type t);
void show_table();
table_element *search_el(char *str);

#endif
