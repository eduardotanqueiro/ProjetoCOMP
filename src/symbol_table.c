#include "symbol_table.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>
#include "ast.h"

extern table_class* symtab;

void semanticAnalysis(no* raiz){

	

}

table_class* insert_class(char *name, method* ml)
{
	table_class *newClass=(table_class*)malloc(sizeof(table_class));
	table_class *aux;
	table_class* previous;

	newClass->name = (char*)strdup(name);
	newClass->method_list = ml;

	return newClass; 
}

method* insert_method(no* method_decl_head){

	method* method_head = (method*)malloc(sizeof(method));
	method_head->name = (char*)strdup(method_decl_head->


} 


//Insere um novo identificador na cauda de uma lista ligada de simbolo
table_element *insert_el(char *str, basic_type t)
{
	table_element *newSymbol=(table_element*) malloc(sizeof(table_element));
	table_element *aux;
	table_element* previous;

	strcpy(newSymbol->name, str);
	newSymbol->type=t;
	newSymbol->next=NULL;	

	if(symtab)	//Se table ja tem elementos
	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
		for(aux=symtab; aux; previous=aux, aux=aux->next)
			if(strcmp(aux->name, str)==0)
				return NULL;
		
		previous->next=newSymbol;	//adiciona ao final da lista
	}
	else	//symtab tem um elemento -> o novo simbolo
		symtab=newSymbol;		
	
	return newSymbol; 
}

void show_table()
{
table_element *aux;
printf("\n");
for(aux=symtab; aux; aux=aux->next)
	printf("symbol %s, type %d\n", aux->name, aux->type);
}

//Procura um identificador, devolve 0 caso nao exista
table_element *search_el(char *str)
{
table_element *aux;

for(aux=symtab; aux; aux=aux->next)
	if(strcmp(aux->name, str)==0)
		return aux;

return NULL;
}





