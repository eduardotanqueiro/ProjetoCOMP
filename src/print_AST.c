#include "structures.h"

void print_pontos(int level){

    for(int i = 0;i < level;i++){
        printf("..");
    }

}

void print_AST(is_program* top){

    if(top == NULL)
        return;

    printf("Program\n");
    

}

void print_methodfield_rep(is_methodfield_rep* mfr, int level){

    is_methodfield_rep* tmp = mfr;

    while(tmp != NULL){

        switch(tmp->type){
            case d_mdecl:

                printf("MethodDecl\n");
                print_methoddecl(mfr->data_methodfield_rep.u_methoddecl,level+1);
                break;

            case d_fdecl:

                printf("FieldDecl\n");
                print_fielddecl(mfr->data_methodfield_rep.u_methoddecl,level);
                break;
            default:
                printf("erro methodfield rep\n");
        }

        tmp = tmp->next;
    }
    
}

void print_type(is_type* tp, int level){

    print_pontos(level);

    switch(tp->disc_t){
        case d_bool:
            printf("Bool\n");
            break;
        case d_int:
            printf("Int\n");
            break;
        case d_double:
            printf("Double\n");
            break;
        case d_void:
            printf("Void\n");
            break;
        case d_none:
            printf("None\n");
            break;
        default:
            printf("erro print type\n");
    }

}

void print_cir(is_commaid_rep* cir, int level){

    is_commaid_rep* tmp = cir;

    while(tmp!=NULL){

        print_id(tmp->id,level);

        tmp = tmp->next;
    }
}

void print_id(char* id, int level){

    print_pontos(level);
    printf("%s\n",id);

}

void print_fielddecl(is_fielddecl *fd, int level){

    print_type(fd->type,level);
    print_cir(fd->cir,level);
    print_id(fd->id,level);

}

void print_methoddecl(is_methoddecl* md, int level){

    print_methodheader(md->mh,level+1);
    print_methodbody(md->mb,level+1);

}

void print_methodheader(is_methodheader* mh, int level){

    print_pontos(level);
    printf("MethodHeader\n");

    print_type(mh->type,level+1);
    print_id(mh->id,level+1);
    print_formalparams(mh->fp,level+1);

}

void print_formalparams(is_formalparams* fp, int level){

    print_type(fp->type,level);
    print_id(fp->id,level);
    print_ctir(fp->ctir,level); //TODO aumenta level?!

}

void print_ctir(is_commatypeid_rep* ctir, int level){

    is_commatypeid_rep* tmp = ctir;

    while(tmp != NULL){

        print_type(tmp->type,level);
        print_id(tmp->id,level);

        tmp = tmp->next;
    }


}

void print_methodbody(is_methodbody* mb, int level){

    print_pontos(level);
    printf("MethodBody\n");

    print_svr(mb->svr,level+1);

}

void print_svr(is_statementvar_rep* svr, int level){

    is_statementvar_rep* tmp = svr;


    while(tmp != NULL){

        switch(tmp->type){
            case d_statement:
                print_statement_tree(tmp->data_statementvarrep.statement, level+1);
                break;
            case d_vardecl:
                print_pontos(level);
                printf("VarDecl\n");

                print_vardecl(tmp->data_statementvarrep.vardecl, level+1);
                break;

            default:
                printf("svr error\n");
                break;
        }

        tmp = tmp->next;        
    }


}

void print_vardecl(is_vardecl* vd, int level){

    print_type(vd->type,level);
    print_id(vd->id,level);
    print_cir(vd->cir,level);

}

void print_statement_tree(is_statement* stat, int level){

    switch(stat->stat_type){
        case d_par:
            print_stat_par(stat->data_statement.u_statement_braces, level);
            break;
        case d_if:
            print_stat_if(stat->data_statement.u_if,level);
            break;
        case d_while:
            print_stat_while(stat->data_statement.u_while,level);
            break;
        case d_return:
            print_stat_return(stat->data_statement.u_return,level);
            break;
        case d_print:
            print_stat_print(stat->data_statement.u_print,level);
            break;
        case d_method:
            print_stat_method(stat->data_statement.u_method_statement,level);
            break;
        case d_assign:
            print_stat_assign(stat->data_statement.u_assign_statement,level);
            break;
        case d_parse:
            print_stat_parseargs(stat->data_statement.u_parseargs_statement,level);
            break;
        default:
            print("statement error\n");
            break;


    }

}


void print_stat_par(is_statement_rep* sr, int level){

    is_statement_rep* tmp = sr;

    while(tmp != NULL){
        print_statement_tree(tmp->statement,level);

        tmp = tmp->next;
    }

}

void print_stat_if(if_statement* ifs, int level){

    print_pontos(level);
    printf("If\n");
    print_expr(ifs->expr,level+1);
    print_statement_tree(ifs->statement1,level+1);
    print_statement_tree(ifs->statement2,level+1);


}

void print_stat_while(while_statement* whl, int level){

    print_pontos(level);
    printf("While\n");

    print_expr(whl->expr,level+1);
    print_statement_tree(whl->statement,level+1);

}