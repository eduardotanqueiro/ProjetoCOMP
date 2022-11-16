#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


table_class* tabela_classe;
method*aux;

void semanticAnalysis(no* raiz){
	printf("%s\n",raiz->tipo);
	if (!strcmp(raiz->tipo,"Program")){
		// passar nome e MethodFieldSemicolonRep
		tabela_classe=inicialize_class_table(raiz->filho->val);
		semanticAnalysis(raiz->filho->irmao);
	}
	if (!strcmp(raiz->tipo,"MethodDecl")){
		// passar nome e MethodFieldSemicolonRep
		aux=inicialize_method_table(raiz->filho->filho->tipo,raiz->filho->filho->irmao->val);
		insert_method_on_class(aux);
		semanticAnalysis(raiz->filho->filho->irmao->irmao);
		semanticAnalysis(raiz->irmao);
	}
	if (!strcmp(raiz->tipo,"MethodParams")){
		semanticAnalysis(raiz->filho);
	}
	if (!strcmp(raiz->tipo,"ParamDecl")){
		vars*aux_var=inicialize_var_table(raiz->filho->tipo,raiz->filho->irmao->val);
		insert_varparam_on_method(aux_var,aux);
		semanticAnalysis(raiz->filho);
	}
	//COMEÇAR NO STRING ARRAY
	// if(!strcmp(raiz->tipo,"MethodBody")){

	// }

}

table_class* inicialize_class_table(char *name)
{
	table_class *newClassTable=(table_class*)malloc(sizeof(table_class));

	newClassTable->name = (char*)strdup(name);
	newClassTable->method_list = NULL;

	return newClassTable; 
}

method* inicialize_method_table(char*return_type,char *name)
{
	method *newMethodTable=(method*)malloc(sizeof(method));

	newMethodTable->name = (char*)strdup(name);
	newMethodTable->return_type= (char*)strdup(return_type);
	newMethodTable->params_list=NULL;
	newMethodTable->vars_list=NULL;
	newMethodTable->next=NULL;
	return newMethodTable; 
}

void insert_method_on_class(method* metodo)
{
	method *aux_method = tabela_classe->method_list;
	if(aux_method==NULL){
		tabela_classe->method_list=metodo;
	}
	else{
		while(aux_method->next!=NULL){
			aux_method=aux_method->next;
		}
		aux_method=metodo;
	}
}

vars* inicialize_var_table(char*type,char *name)
{
	vars *newvar=(vars*)malloc(sizeof(vars));

	newvar->name = (char*)strdup(name);
	newvar->type = (char*)strdup(type);
	newvar->next=NULL;

	return newvar; 
}

void insert_varparam_on_method(vars*var,method* metodo)
{
	vars *aux_var = metodo->params_list;
	if(aux_var==NULL) {
		metodo->params_list=var;
	}
	else{
		while(aux_var->next!=NULL){
			aux_var=aux_var->next;
		}
		aux_var=var;}
}

// ===== Class Factorial Symbol Table =====
// factorial ( int ) int
// main ( String []) void

// ===== Method factorial ( int ) Symbol Table =====
// return int
// n int param

void print_tables(){
	printf("===== Class %s Symbol Table =====\n",tabela_classe->name);
	method*aux_method=tabela_classe->method_list;
	do{
		printf("%s\t(%s)\t%s\n",aux_method->name,aux_method->return_type,aux_method->return_type);
		aux_method=aux_method->next;
	}while(aux_method!=NULL);

	aux_method=tabela_classe->method_list;
	do{
		printf("===== Class %s (%s) Symbol Table =====\n",aux_method->name,aux_method->return_type);
		printf("return\t%s\n",aux_method->return_type);

		vars*params_list_aux=aux_method->params_list;
		do{
			printf("%s\t%s\t%s\n",params_list_aux->name,params_list_aux->type,"param");
			params_list_aux=params_list_aux->next;
		}while(params_list_aux!=NULL);
		aux_method=aux_method->next;
	}while(aux_method!=NULL);
}

//Insere um novo identificador na cauda de uma lista ligada de simbolo
// table_element *insert_el(char *str, basic_type t)
// {
// 	table_element *newSymbol=(table_element*) malloc(sizeof(table_element));
// 	table_element *aux;
// 	table_element* previous;

// 	strcpy(newSymbol->name, str);
// 	newSymbol->type=t;
// 	newSymbol->next=NULL;	

// 	if(symtab)	//Se table ja tem elementos
// 	{	//Procura cauda da lista e verifica se simbolo ja existe (NOTA: assume-se uma tabela de simbolos globais!)
// 		for(aux=symtab; aux; previous=aux, aux=aux->next)
// 			if(strcmp(aux->name, str)==0)
// 				return NULL;
		
// 		previous->next=newSymbol;	//adiciona ao final da lista
// 	}
// 	else	//symtab tem um elemento -> o novo simbolo
// 		symtab=newSymbol;		
	
// 	return newSymbol; 
// }

// void show_table()
// {
// table_element *aux;
// printf("\n");
// for(aux=symtab; aux; aux=aux->next)
// 	printf("symbol %s, type %d\n", aux->name, aux->type);
// }

// //Procura um identificador, devolve 0 caso nao exista
// table_element *search_el(char *str)
// {
// table_element *aux;

// for(aux=symtab; aux; aux=aux->next)
// 	if(strcmp(aux->name, str)==0)
// 		return aux;

// return NULL;
// }





