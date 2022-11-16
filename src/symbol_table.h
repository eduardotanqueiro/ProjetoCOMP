#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define PARAMS_BUFFER_SIZE 512

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

typedef struct _t{
	char* name; //para variaveis, metodos ou classes
	char* params_list; //lista dos parametros do metodo
	char* return_type; //para os metodos

	struct _t* body; //para os metodos, ponteiro para o body
	struct _t* next; //ponteiro para o proximo elemento da tabela, ou entao proxima variavel/parametro do metodo

} tab_element;


void show_table();


#endif
