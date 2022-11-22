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
    tab_element* aux = elem;

    // Tabela Global/Classe
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
    while (aux != NULL) {
        if (aux->body != NULL) {

			printf("\n===== Method %s(%s) Symbol Table =====\n", aux->name, aux->params_list);
            
            tab_element* method = aux->body;
            while (method != NULL) { //iterar sobre o body do metodo

                if (method->is_param == 1) //se for parametro do metodo
                        printf("%s\t\t%s\t%s\tparam\n", method->name, method->type, method->params_list);
                else
                    printf("%s\t\t%s\n", method->name, method->type);

                method = method->body;
            }
        }
        aux = aux->next;
    }
    printf("\n");
}


void make_notations_ast(no* node, tab_element* tab, char* func){

	if(node == NULL) 
		printf("NULL EXCEPTION\n");
	else
		printf("%s\n",node->tipo);

	if( !strcmp(node->tipo,"MethodDecl")){ //se o nó é declaracao de metodo, temos de verificar se está na tabela global

		char* func_name  = (char*)strdup(node->filho->filho->irmao->info->val);

		//verificar se existe
		if( search_symbol(tab, func_name, 0) != NULL ){

			//se existe, vamos iterar dentro do metodo
			if(node->filho != NULL)
				make_notations_ast(node->filho, tab, func_name); //agora estamos a iterar dentro deste metodo
			

		}
		
		//metodo nao declarado ou entao seguir para o proximo metodo
		if(node->irmao != NULL)
			make_notations_ast(node->irmao, tab, NULL);

	}
	else{
		//contínuamos a correr a árvore para baixo, estamos dentro de uma funcao
		if(node->filho != NULL)
			make_notations_ast(node->filho, tab, func);

		if(node->irmao != NULL)
			make_notations_ast(node->irmao, tab, func);

	}

	int logical = 0;

	if(isIntDoubleBool(node)){
		//done in the function before
	}
	else if( (logical = two_part_op(node->tipo)) ){
		check_two_part_op(node,func,logical);
	}
	else if ( logical = one_part_op(node->tipo) ){
		check_one_part_op(node,func,logical);
	}
	else if( !strcmp(node->tipo,"Call")){
		
	}



}

int two_part_op(char* tipo){

    if( !strcmp(tipo, "ParseArgs") ||
		!strcmp(tipo, "Add") ||
		!strcmp(tipo, "Sub") ||
		!strcmp(tipo, "Mul") ||
		!strcmp(tipo, "Div") ||
		!strcmp(tipo, "Mod") ||
		!strcmp(tipo, "Assign")
		)
        return 2;

	if( !strcmp(tipo, "And") ||
		!strcmp(tipo, "Or") ||
		!strcmp(tipo, "Eq") ||
		!strcmp(tipo, "Ge") ||
		!strcmp(tipo, "Gt") ||
		!strcmp(tipo, "Le") ||
		!strcmp(tipo, "Lt") ||
		!strcmp(tipo, "Ne")
	)
		return 1;
    else 
        return false;
}

int one_part_op(char* tipo){

	if( !strcmp(tipo,"Minus") ||
		!strcmp(tipo,"Plus") ||
		!strcmp(tipo,"Return") ||
		!strcmp(tipo,"Print")
	)
		return 2;

	if( !strcmp(tipo, "Not") ||
		!strcmp(tipo,"If") ||
		!strcmp(tipo,"While")
	)
		return 1;

	return 0;
}

char* get_var_type(char* var_name,char* func_name){

	//search for the function in the global table
	tab_element* aux_tab = symtab;
	char* type = "undef"; //TODO

	while(aux_tab != NULL){ //TODO: e se houverem várias funcoes com o mesmo nome?!?!?
		
		if( !strcmp(aux_tab->name, func_name) )
			break;

		aux_tab = aux_tab->next;
	}

	//search for the variable
	while(aux_tab != NULL){
		
		if( !strcmp(aux_tab->name, var_name) ){
			type = (char*)strdup(aux_tab->type);
			break;
		}

		aux_tab = aux_tab->body;
	}

	printf("get var type %s\n", type);
	return type;
}


void check_two_part_op(no* node,char* func_name, int isLogical){

	char* op_type1, *op_type2;

	// printf("two part %s\n",node->tipo);
	// printf("%s\n",node->filho->tipo);

	//verificar se o primeiro filho é uma variável
	if( !strcmp(node->filho->tipo,"Id") ){


		//is buscar o tipo da variável
		op_type1 = get_var_type(node->filho->info->val,func_name);
		node->filho->notation = (char*)strdup(op_type1);

		//TODO raise error se for undef

	}
	else
		op_type1 = node->filho->notation;

	//verificar se o segunda filho é uma variável
	if( !strcmp(node->filho->irmao->tipo,"Id") ){

		//is buscar o tipo da variável
		op_type2 = get_var_type(node->filho->irmao->info->val,func_name);
		node->filho->irmao->notation = (char*)strdup(op_type2);

		//TODO raise error se for undef

	}	
	else
		op_type2 = node->filho->irmao->notation;

	printf("types %s %s\n",op_type1,op_type2);


	if( op_type1 != NULL && op_type2 != NULL && !strcmp(op_type1,op_type2) ){ //se ambos os operandos têm o mesmo tipo

		if(0){ //TODO error: se os tipos forem undef, raise error

		}
		else{
			//

			if(isLogical == 1){
				//se for uma operação lógica

				if( !strcmp(node->tipo,"Or") || !strcmp(node->tipo,"And")){ //se for or ou and, tem de ter expressao bolean em cada filho

					if( strcmp(op_type1,"boolean") || strcmp(op_type2,"boolean") ){
						//erro
					}

				}
				else if(!strcmp(node->tipo, "Eq") ||
						!strcmp(node->tipo, "Ge") ||
						!strcmp(node->tipo, "Gt") ||
						!strcmp(node->tipo, "Le") ||
						!strcmp(node->tipo, "Lt") ||
						!strcmp(node->tipo, "Ne")
				){	//se é um tipo de comparação, nenhum dos operandos pode ser bool

					if( !strcmp(op_type1,"boolean") || !strcmp(op_type2,"boolean") ){
						//erro
					}

				}
				
				node->notation = "boolean";

			}
			else{
				//se não for operação lógica

				if( !strcmp(node->tipo,"ParseArgs") ){
					//se for parseargs, os argumentos têm de ser inteiros

					//error	
					if( strcmp(op_type1,"int") && strcmp(op_type2,"int")){}

				}
				else if( !strcmp(node->tipo,"Assign"))
					node->notation = op_type1;
				else{

					if( !strcmp(op_type1,"boolean") || !strcmp(op_type2,"boolean"))
						node->notation = "undef";
					else
						node->notation = op_type1;

				}
			}
		}
	}
	else if( op_type1 != NULL && op_type2 != NULL && 
			( ( !strcmp(op_type1,"int") && !strcmp(op_type2,"double")) ||
			  ( !strcmp(op_type1,"double") && !strcmp(op_type2,"int") ) ) ) {
			//operação entre int e double

			if(0){ //TODO error: se os tipos forem undef, raise error

			}
			else{
				//

				if(isLogical == 1){
					//se for uma operação lógica

					if( !strcmp(node->tipo,"Or") || !strcmp(node->tipo,"And")){ //se for or ou and, tem de ter expressao bolean em cada filho

						//TODO erro, pois sabemos que nenhum dos operandos é do tipo boolean

					}
					else if(!strcmp(node->tipo, "Eq") ||
							!strcmp(node->tipo, "Ge") ||
							!strcmp(node->tipo, "Gt") ||
							!strcmp(node->tipo, "Le") ||
							!strcmp(node->tipo, "Lt") ||
							!strcmp(node->tipo, "Ne")
					){	//se é um tipo de comparação, com são dois filhos númericos, não acontece nada TODO: retirar no futuro. Deixar agora para facilitar perceber o código

					}
					
					node->notation = "boolean";

				}
				else{
					//se não for operação lógica

					if( !strcmp(node->tipo,"ParseArgs") ){
						//se for parseargs, os argumentos têm de ser inteiros

						//error	
						if( strcmp(op_type1,"int") && strcmp(op_type2,"int")){}

					}
					else if( !strcmp(node->tipo,"Assign"))

						//TODO CHECKAR SE ESTAMOS A DAR ASSIGN DE UM INT A UM DOUBLE, ERRO!!!
						node->notation = op_type1;
					else{

						node->notation = "double";

					}
				}
			}



	}
	else if( op_type1 != NULL && op_type2 != NULL && !strcmp(node->tipo,"Assign")){
		
		if( !strcmp(op_type1,"boolean")){
			//se chegarmos aqui, signifca que os dois operandos não têm o mesmo tipo.
			// se o tipo da variável é bool, o outro tipo tem de ser obrigatoriamente bool, como não é o caso, temos erro
			node->notation = "undef";
		}
		else{
			//tipo da var é int ou double, entao podem ser bool
			node->notation = op_type1;
		}


	}
	else{

		if (op_type1 == NULL)
            op_type1 = "none";
        
		if (op_type2 == NULL)
            op_type2 = "none";

		//TODO print error

		if(isLogical == 1)
			node->notation = "boolean";
		else
			node->notation = "undef";

	}
}

void check_one_part_op(no* node, char* func_name, int isLogical){

	char* op_type;

	printf("one part %s %s \n",node->tipo,node->filho->tipo);

	//verificar se tem filhos
    if (node->filho == NULL)
        op_type = "none";

	//verificar se o filho é uma variável
	else if( !strcmp(node->filho->tipo,"Id") ){

		//is buscar o tipo da variável
		op_type = get_var_type(node->filho->info->val,func_name);
		node->filho->notation = (char*)strdup(op_type);
		printf("one part node notation %s\n",node->notation);

		//TODO raise error se for undef

	}
	else{
		//se for int ou double
		op_type = node->filho->notation;
	}


	if( op_type != NULL && strcmp(op_type, "undef") ){
		//não é null nem undef

		if(isLogical){
			
			if( !strcmp(node->tipo,"If") || !strcmp(node->tipo,"While")){ //se é um if ou um while, o filho tem de ser bool, isto é, a expressao entre parenteses

				if( !strcmp(op_type,"boolean"))
					node->notation = op_type;
				
				else{
					//TODO raise error tipo incompativel
				}


			}
			else{ //Sobra a operação logica Not

				//TODO erros?!?!?!?
				node->notation = "boolean";

			}
		}
		else if ( !strcmp(node->tipo,"Minus") || !strcmp(node->tipo,"Plus")){
			//temos de verificar se o operando é numérico, isto é, int ou double

			if( !strcmp(op_type,"int") || !strcmp(op_type,"double"))
				node->notation = op_type;
			else{
				//TODO raise error
			}

		}
		else if( !strcmp(node->tipo,"Return")){
			
			//temos de ir verificar se o tipo de return coincide com a declaracao do metodo
			tab_element* aux = symtab;

			while(aux != NULL){

				if( !strcmp(aux->name,func_name)){  //encontrámos a funcao

					if( strcmp(aux->type,op_type)) //isto é, os tipos não coincidem
					{
						//TODO raise error tipo incompativel
					}
				
				}


				aux = aux->next;
			}

		}
		else //sobra o print
			node->notation = op_type;
	}
	else{
		//TODO raise errors
	}


}

bool isIntDoubleBool(no* node){

	if( !strcmp(node->tipo,"DecLit")){
		node->notation = "int";
		return true;
	}
	else if( !strcmp(node->tipo,"RealLit")){
		node->notation = "double";
		return true;
	}
	else if( !strcmp(node->tipo,"BoolLit")){
		node->notation = "boolean";
		return true;
	}

	return false;
}