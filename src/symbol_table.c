#include "symbol_table.h"
#define DEBUG 0

extern tab_element* symtab;

tab_element* insert_element( tab_element* tail, tab_element* new){
	if(DEBUG) printf("insert elem \n");
	tail->next = new;
	return new;
}

void create_table(tab_element* tail, no* raiz){

	if(raiz == NULL)
		return;

	if(DEBUG) printf("criar tabela %s!\n",raiz->tipo);

	// Verificar que tipo de nó temos
	if( !strcmp(raiz->tipo,"Program") ){
		symtab = tail;
		create_table(tail, raiz->filho->irmao);
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

tab_element* create_element(char* name, char* params_list, char* type, int is_param){

	tab_element* new = (tab_element*)malloc(sizeof(tab_element));

	new->name = name;
	new->params_list = params_list;
	new->type = type;
	new->is_param = is_param;

	new->body = NULL;
	new->next = NULL;

	return new;
}

void add_method(tab_element* tail, no* node){
	
	if(DEBUG) printf("add method\n");

	// variaveis auxiliares (apenas para leitura mais fácil)
	char* aux_params;
	char* aux_name  = (char*)strdup(node->filho->filho->irmao->info->val); // aceder ao methodheader, nome do metodo
	char* aux_return_type = get_type(node->filho->filho->tipo); // aceder ao methodheader, tipo de retorno

	// TODO: checkar se a variavel/func ja existe. OBS: há aqui algum erro, só não sei qual
	// if( search_symbol(symtab, aux_name, 0) == NULL){
		//criar o nó do metodo
		tab_element* new_method = create_element(aux_name, "" ,aux_return_type,0); //criar novo elemento
		
		//inserir o metodo no fim da tabela de simbolo
		tail = insert_element(tail, new_method);

		//obter o cabeçalho do metodo
		get_method_meader(new_method, node->filho->filho->irmao->irmao); // manda o nó ParamDecl/FormalParams

		//obter as variaveis dentro do metodo
		get_method_vars(new_method, node->filho->irmao); //manda o nó MethodBody
	// }
	// else{
	// 	printf("Line %d, column %d: Symbol %s already defined\n", node->filho->filho->irmao->info->line, node->filho->filho->irmao->info->col, aux_name);
	// }

}

/*
	adicionar o cabeçalho à tabela de simbolos do metodo
*/
void get_method_meader(tab_element* method_node, no* no_ast){

	if(DEBUG) printf("get header\n");

	method_node->body = create_element("return", "", method_node->type,0); 
	tab_element* last_elem_method_table = method_node->body;

	char* str_params = (char*)malloc(1);
	strcat(str_params, "");
	no* aux_node = no_ast->filho;

	tab_element* aux_elem; //elemento auxiliar para adicionar na tabela de variaveis do cmetodo


	while(aux_node != NULL){ // iterar por todos os ParamDecl do metodo

		// verificar se a variavel já existe
		if( search_symbol(method_node->body,aux_node->filho->irmao->info->val,1) == NULL){

			aux_elem = create_element(aux_node->filho->irmao->info->val, "", get_type(aux_node->filho->tipo),1); //criar novo elemento para o parametro

			last_elem_method_table->body = aux_elem; //adicionar elemento à tabela do metodo
			last_elem_method_table = aux_elem; //atualizar o ponteiro auxiliar para o ultimo elemento da tabelo do metodo

			// adicionar o paramatro à string de parametros do metodo
			if( !strcmp(str_params,"") ){ //se a string está vazia, é o primeiro parametro
				if(DEBUG) printf("add str params\n");
				str_params = realloc(str_params, strlen(str_params)+strlen(aux_node->filho->tipo)+1 );
				strcat(str_params, get_type(aux_node->filho->tipo));
			}
			else{
				if(DEBUG) printf("add str params plus\n");
				str_params = realloc(str_params, strlen(str_params)+strlen(aux_node->filho->tipo)+2 );
				strcat(str_params, ",");
				strcat(str_params, get_type(aux_node->filho->tipo));
			}
		}
		else
			printf("Line %d, column %d: Symbol %s already defined\n", aux_node->filho->irmao->info->line,aux_node->filho->irmao->info->col, aux_node->filho->irmao->info->val);
		
		aux_node = aux_node->irmao;
		
	}

	//atualizar a string de parametros do metodo
	method_node->params_list = str_params;
}

void get_method_vars(tab_element* method_node, no* no_ast){


	no* aux_node = no_ast->filho;
	tab_element* aux_body = method_node->body;
	tab_element* aux_new_var;

	//ir buscar o ultimo elemento do body do metodo
	while(aux_body->body != NULL)
		aux_body = aux_body->body;

	//correr o corpo do metodo
	while(aux_node != NULL){

			if( !strcmp(aux_node->tipo,"VarDecl") ){ //só queremos adicionar na tabela quando são variáveis, statements não interessam aqui

					//verificar se a variavel ainda nao está na tabela
				if( search_symbol(method_node->body,aux_node->filho->irmao->info->val,1) == NULL){
					aux_new_var = create_element(aux_node->filho->irmao->info->val, "", get_type(aux_node->filho->tipo),0);

					aux_body->body = aux_new_var; //adicionar a variável na tabela do metodo
					aux_body = aux_new_var;	//atualizar a variavel auxiliar que aponta para o ultimo elemento da tabela do metodo
				}
				else
					printf("Line %d, column %d: Symbol %s already defined\n", aux_node->filho->irmao->info->line,aux_node->filho->irmao->info->col, aux_node->filho->irmao->info->val);
			
			}



		aux_node = aux_node->irmao;
	}
}

void add_vars(tab_element* tail, no* no_ast){

	if(DEBUG) printf("add vars\n");

	no* aux_node = no_ast;
	tab_element* aux_new_var;

	//correr o corpo do metodo
	if( search_symbol(symtab,aux_node->filho->irmao->info->val,0) == NULL){
		aux_new_var = create_element(aux_node->filho->irmao->info->val, NULL, get_type(aux_node->filho->tipo),0);
		tail = insert_element(tail,aux_new_var);
	}
	else
		printf("Line %d, column %d: Symbol %s already defined\n", aux_node->filho->irmao->info->line, aux_node->filho->irmao->info->col, aux_node->filho->irmao->info->val);
}

char* get_type(char* original_type){

	char* fixed_type = (char*)malloc(sizeof(13));

	if( !strcmp(original_type,"StringArray") )
		fixed_type = "String[]";
	else{
		fixed_type = (char*)strdup(original_type);
		fixed_type[0] = fixed_type[0] + 32;

		if( !strcmp(fixed_type,"bool"))	
			strcat(fixed_type,"ean");
	}

	return fixed_type;
}

char* search_symbol(tab_element* func, char* name, int isVar){

	tab_element* aux = func;

	while(aux != NULL){

		if( !strcmp(aux->name,name) )
			return aux->type;

		if(isVar)
			aux = aux->body;
		else
			aux = aux->next;

	}


	return NULL;
}

void printSymbolTable(tab_element* elem) {
    tab_element* copy = elem;

    // Tabela Global
    printf("===== Class %s Symbol Table =====\n",elem->name);
	elem = elem->next;

    while (elem != NULL) {
		
		if( elem->params_list == NULL)
			printf("%s\t%s\n", elem->name, elem->type);
		else
			printf("%s\t(%s)\t%s\n", elem->name, elem->params_list, elem->type);
        elem = elem->next;
    }
    
    // Tabelas de funcoes
    while (copy != NULL) {
        if (copy->body != NULL) {

			printf("\n===== Method %s(%s) Symbol Table =====\n", copy->name, copy->params_list);
            
            tab_element* func = copy->body;
            while (func != NULL) {

                if (func->is_param == 1)
                        printf("%s\t\t%s\t%s\tparam\n", func->name, func->type, func->params_list);
                else
                    printf("%s\t\t%s\n", func->name, func->type);

                func = func->body;
            }
        }
        copy = copy->next;
    }
    printf("\n");
}


void print_AST_with_notation(no *no, int level)
{
    print_level(level);

    // if(no == NULL){
    //     //printf("null\n");
    //     return;
    // }

    if (strcmp(no->info->val,"") )
    {
        printf("%s(%s)\n", no->tipo, no->info->val);
    }
    else{
        printf("%s\n", no->tipo);
    }

    if (no->filho)
        print_AST(no->filho, level + 1);
    if (no->irmao)
        print_AST(no->irmao, level);

    // if printTree and hasError==False limpa a memória depois de printar!!
    free(no);
}