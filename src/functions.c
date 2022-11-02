#include "functions.h"


is_program* insert_program(char* id, is_methodfield_rep* imfr){
    
    is_program* ip=(is_program*)malloc(sizeof(is_program));

    ip->id=(char*)strdup(id);
    
    ip->mfr=(is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    ip->mfr = imfr;

    return ip;
}

is_methodfield_rep* insert_methoddecl_methodfield(is_methoddecl* imd, is_methodfield_rep* imfr){

    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));

    mfr->data_methodfield_rep.u_methoddecl = (is_methoddecl*)malloc(sizeof(is_methoddecl));
    mfr->data_methodfield_rep.u_methoddecl = imd;

    mfr->next = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    mfr->next = imfr;

    return mfr;
}

is_methodfield_rep* insert_fielddecl_methodfield(is_fielddecl* imd, is_methodfield_rep* imfr){

    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));

    mfr->data_methodfield_rep.u_fielddecl = (is_fielddecl*)malloc(sizeof(is_fielddecl));
    mfr->data_methodfield_rep.u_fielddecl = imd;

    mfr->next = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    mfr->next = imfr;

    return mfr;
}

is_methodfield_rep* insert_semicolon_methodfield(is_methodfield_rep* imfr){
    //TODO ?!?!?!?
    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));

    mfr->next = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    mfr->next = imfr;

    return mfr;
}

is_methoddecl* insert_methoddecl(is_methodheader* imd, is_methodbody* imb){

    is_methoddecl* md = (is_methoddecl*)malloc(sizeof(is_methoddecl));

    md->mh = imd;
    md->mb = imb;

    return md;
}

is_fielddecl* insert_fielddecl(is_type* type, char* id,is_commaid_rep* icir){

    is_fielddecl* fd = (is_fielddecl*)malloc(sizeof(is_fielddecl));

    fd->type = type;
    fd->cir = icir;
    fd->id = (char*)strdup(id);

    return fd;
}


is_commaid_rep* insert_comma_id_rep(char* id,is_commaid_rep* icir){

    is_commaid_rep* cir = (is_commaid_rep*)malloc(sizeof(is_commaid_rep));

    cir->id = (char*)strdup(id);
    
    cir->next = (is_commaid_rep*)malloc(sizeof(is_commaid_rep));
    cir->next = icir; 

    return cir;
}

//TODO TYPE

is_methodheader* insert_methodheader(is_type* type,char* id, is_formalparams* ifp){

    is_methodheader* mh = (is_methodheader*)malloc(sizeof(is_methodheader));

    mh->type = type;
    mh->id = (char*)strdup(id);
    
    mh->fp = ifp;

    return mh;
}

is_formalparams* insert_params(is_type* type,char* id, is_commatypeid_rep* ictir){

    is_formalparams* fp = (is_formalparams*)malloc(sizeof(is_formalparams));

    fp->id = (char*)strdup(id);
    fp->type = type;
    fp->ctir = ictir;

    return fp;
}

is_formalparams* insert_string(char* id){

    is_formalparams* fp = (is_formalparams*)malloc(sizeof(is_formalparams));

    fp->type = NULL;
    fp->id = (char*)strdup(id);

    return fp;
}

is_commatypeid_rep* insert_commatype_id_rep(is_type* type,char* id, is_commatypeid_rep* ictir){

    is_commatypeid_rep* ctir = (is_commatypeid_rep*)malloc(sizeof(is_commatypeid_rep));

    ctir->type = type;
    ctir->id = (char*)strdup(id);
    
    ctir->next = (is_commatypeid_rep*)malloc(sizeof(is_commatypeid_rep));
    ctir->next = ictir;

    return ctir;
}

is_methodbody* insert_methodbody(is_statementvar_rep* isvr){

    is_methodbody* mb = (is_methodbody*)malloc(sizeof(is_methodbody)); 
    
    mb->svr = isvr;

    return mb;
}

is_statementvar_rep* insert_statementvar_rep(is_statement* statement, is_statementvar_rep* isvr){

    is_statementvar_rep* svr = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));

    svr->data_statementvarrep.statement = statement;

    svr->next = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));
    svr->next = isvr;

    return svr;
}

is_statementvar_rep* insert_vardecl_statement(is_vardecl* ivd, is_statementvar_rep* isvr){

    is_statementvar_rep* svr = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));

    svr->data_statementvarrep.vardecl = ivd;

    svr->next = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));
    svr->next = isvr;

    return svr;
}

is_vardecl* insert_vardecl(is_type* type, char* id, is_commaid_rep* icir){

    is_vardecl* vd = (is_vardecl*)malloc(sizeof(is_vardecl));

    vd->type = type;
    vd->id = (char*)strdup(id);
    vd->cir = icir;


    return vd;
}


is_statement* insert_statement_brace(is_statement_rep* isr){

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_par;
    st->data_statement.u_statement_braces = isr;

    return st;
}

is_statement* insert_if_statement(is_expr* expr, is_statement* statement1, is_statement* statement2){

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_if;

    if_statement* if_st = (if_statement*)malloc(sizeof(if_statement));
    if_st->expr = expr;
    if_st->statement1 = statement1;
    if_st->statement2 = statement2;
    
    st->data_statement.u_if = if_st;

    return st;
}

is_statement* insert_while_statement(is_expr* expr, is_statement* statement){

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_while;

    while_statement* wh_st = (while_statement*)malloc(sizeof(while_statement));
    wh_st->expr = expr;
    wh_st->statement = statement;

    st->data_statement.u_while = wh_st;

    return st;
}

is_statement* insert_return_statement(is_expr* expr){

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_return;

    return_statement* rt_st = (return_statement*)malloc(sizeof(return_statement));
    
    if(expr == d_none){
        rt_st->expr = NULL;
    }else{
        rt_st->expr = expr;
    }

    st->data_statement.u_return = rt_st;

    return st;
}

is_statement* insert_print_expr_statement(is_expr* expr){

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_print;

    print_statement* pt_st = (print_statement*)malloc(sizeof(print_statement));
    pt_st->data_print.u_expr = expr;

    st->data_statement.u_print = pt_st;
    
    return st;
}

is_statement* insert_method_statement(is_methodinvocation* imi){
    
}

