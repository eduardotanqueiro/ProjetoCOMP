#include "symbol_table.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "ast.h"

extern table_class* symtab;

void create_table(tab_element* tail, no* raiz){

	if(raiz == NULL)
		return;

	// Verificar que tipo de nó temos
	else if( !strcmp(raiz->tipo,"Program") ){
		symtab = tail;
		create_table(tail, raiz->filho);
	}
	else if( !strcmp(raiz->tipo,"MethodDecl") )
		add_method(tail, raiz);

	else if( !strcmp(raiz->tipo,"FieldDecl") )
		add_vars(tail, raiz);

	// atualizar o fim da tabela de simbolos
	while(tail->next != NULL)
		tail = tail->next;

	// passar para o próximo nó da AST
	create_table(tail,raiz->irmao);

}

tab_element* create_element(char* name, char* params_list, char* rt_type){

	tab_element* new = (tab_element*)malloc(sizeof(tab_element));

	new->name = name;
	new->params_list = params_list;
	new->return_type = rt_type;

	new->body = NULL;
	new->next = NULL;

	return new;
}

void add_method(tab_element* tail, no* node){
	
	// variaveis auxiliares (apenas para leitura mais fácil)
	char* aux_params;
	char* aux_name  = (char*)strdup(node->filho->filho->irmao->val); // aceder ao methodheader, nome do metodo
	char* aux_return_type = (char*)strdup(node->filho->filho->tipo); // aceder ao methodheader, tipo de retorno
	
	//TODO mudar
	if(node->filho->filho->irmao->irmao != NULL){ // se existirem parametros
		aux_params = parse_params(node->filho->filho->irmao->irmao)
	}else{ // sem parametros
		aux_params = "";
	}

	tab_element* new = create_element(aux_name,aux_params,aux_return_type); //criar novo elemento

	


}

char* parse_params(no* mp){

	no* aux = mp->filho;
	char* params[PARAMS_BUFFER_SIZE] = (char*)malloc(PARAMS_BUFFER_SIZE);

	//TODO
	while(aux != NULL){
		strcat(params,aux->filho->tipo);
		aux = aux->irmao;
	}

	return params;
}