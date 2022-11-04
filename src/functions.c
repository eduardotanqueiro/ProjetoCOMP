#include "functions.h"


is_program* insert_program(char* id, is_methodfield_rep* imfr){
    
    printf("f: start prog\n");

    is_program* ip=(is_program*)malloc(sizeof(is_program));
    
    ip->id=(char*)strdup(id);
    ip->mfr = imfr;

    return ip;
}

is_methodfield_rep* insert_methoddecl_methodfield(is_methoddecl* imd, is_methodfield_rep* imfr){

    printf("f: methor decl rep\n");

    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    is_methodfield_rep* tmp;
    mfr->next = NULL;
    mfr->type = d_mdecl;

    is_methoddecl* md = (is_methoddecl*)malloc(sizeof(is_methoddecl));

    md->mh = imd->mh;
    md->mb = imd->mb;

    mfr->data_methodfield_rep.u_methoddecl = md;


    if(imfr == NULL)
        return mfr;

    for(tmp=imfr; tmp->next; tmp=tmp->next);
	tmp->next=mfr;

    return imfr;
}

is_methodfield_rep* insert_fielddecl_methodfield(is_fielddecl* imd, is_methodfield_rep* imfr){

    printf("f:field decl rep\n");

    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    is_methodfield_rep* tmp;
    mfr->next = NULL;
    mfr->type = d_fdecl;

    is_fielddecl* fd = (is_fielddecl*)malloc(sizeof(is_fielddecl));


    fd->type = imd->type;
    fd->cir = imd->cir;
    
    fd->id = (char*)strdup(imd->id);

    mfr->data_methodfield_rep.u_fielddecl = fd;

    if(imfr == NULL)
        return mfr;

    for(tmp=imfr; tmp->next; tmp=tmp->next);
	tmp->next=mfr;


    return imfr;
}

is_methodfield_rep* insert_semicolon_methodfield(is_methodfield_rep* imfr){
    
    printf("f:semicolon rep prog\n");

    is_methodfield_rep* mfr = (is_methodfield_rep*)malloc(sizeof(is_methodfield_rep));
    is_methodfield_rep* tmp;
    mfr->next = NULL;
    mfr->type = d_colon;
    
    if(imfr == NULL)
        return mfr;

    for(tmp=imfr; tmp->next; tmp=tmp->next);
	tmp->next=mfr;

    return imfr;
}

is_methoddecl* insert_methoddecl(is_methodheader* imd, is_methodbody* imb){

    printf("f: method decl \n");

    is_methoddecl* md = (is_methoddecl*)malloc(sizeof(is_methoddecl));

    md->mh = imd;
    md->mb = imb;

    return md;
}

is_fielddecl* insert_fielddecl(is_type* type, char* id,is_commaid_rep* icir){

    printf("f: field decl\n");

    is_fielddecl* fd = (is_fielddecl*)malloc(sizeof(is_fielddecl));

    fd->type = type;
    fd->cir = icir;
    fd->id = (char*)strdup(id);

    return fd;
}


is_commaid_rep* insert_comma_id_rep(char* id,is_commaid_rep* icir){

    printf("f: commamidrep \n");
    is_commaid_rep* cir = (is_commaid_rep*)malloc(sizeof(is_commaid_rep));
    is_commaid_rep* tmp;
    cir->next = NULL;

    cir->id = (char*)strdup(id);
    
    if(icir==NULL)
		return cir;

	for(tmp=icir; tmp->next; tmp=tmp->next);
	tmp->next=cir;

    return icir;
}


is_type* insert_type(char* type){
printf("f: type \n");
    is_type* tp = (is_type*)malloc(sizeof(is_type));

    if( !strcmp(type,"BOOL")){
        tp->disc_t = d_bool;
    }
    else if( !strcmp(type,"INT")){
        tp->disc_t = d_int;
    }
    else if( !strcmp(type,"DOUBLE")){
        tp->disc_t = d_double;
    }

    return tp;
}


is_methodheader* insert_methodheader(is_type* type,char* id, is_formalparams* ifp){
printf("f: methodheader\n");
    is_methodheader* mh = (is_methodheader*)malloc(sizeof(is_methodheader));


    if(type == NULL){
        mh->type = (is_type*)malloc(sizeof(is_type));
        mh->type->disc_t = d_void;
    }else{
        mh->type = type;
    }
    

    mh->id = (char*)strdup(id);
    
    mh->fp = ifp;

    return mh;
}

is_formalparams* insert_params(is_type* type,char* id, is_commatypeid_rep* ictir){
printf("f: params\n");
    is_formalparams* fp = (is_formalparams*)malloc(sizeof(is_formalparams));

    fp->id = (char*)strdup(id);
    fp->type = type;
    fp->ctir = ictir;

    return fp;
}

is_formalparams* insert_string(char* id){
printf("f: string\n");
    is_formalparams* fp = (is_formalparams*)malloc(sizeof(is_formalparams));

    fp->type = NULL;
    fp->id = (char*)strdup(id);

    return fp;
}

is_commatypeid_rep* insert_commatype_id_rep(is_type* type,char* id, is_commatypeid_rep* ictir){
printf("f: commatypeidrep \n");
    is_commatypeid_rep* ctir = (is_commatypeid_rep*)malloc(sizeof(is_commatypeid_rep));
    is_commatypeid_rep* tmp;
    ctir->next = NULL;

    ctir->type = type;
    ctir->id = (char*)strdup(id);
    
	if(ictir==NULL)
		return ctir;

	for(tmp=ictir; tmp->next; tmp=tmp->next);
	tmp->next=ctir;

	return ictir;
}

is_methodbody* insert_methodbody(is_statementvar_rep* isvr){
printf("f: methodbody\n");
    is_methodbody* mb = (is_methodbody*)malloc(sizeof(is_methodbody)); 
    
    mb->svr = isvr;

    return mb;
}

is_statementvar_rep* insert_statementvar_rep(is_statement* statement, is_statementvar_rep* isvr){
printf("f: statementvarrep \n");
    is_statementvar_rep* svr = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));
    is_statementvar_rep* tmp;
    svr->next = NULL;
    svr->type = d_statement;

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));
    st = statement;
    svr->data_statementvarrep.statement = st;

	if(isvr==NULL)
		return svr;

	for(tmp=isvr; tmp->next; tmp=tmp->next);
	tmp->next=svr;

	return isvr;
}

is_statementvar_rep* insert_vardecl_statement(is_vardecl* ivd, is_statementvar_rep* isvr){
printf("f: vardecl stat \n");
    is_statementvar_rep* svr = (is_statementvar_rep*)malloc(sizeof(is_statementvar_rep));
    is_statementvar_rep* tmp;
    svr->next = NULL;
    svr->type = d_vardecl;

    is_vardecl* vd = (is_vardecl*)malloc(sizeof(is_vardecl));
    vd = ivd;
    svr->data_statementvarrep.vardecl = vd;

	if(isvr==NULL)
		return svr;

	for(tmp=isvr; tmp->next; tmp=tmp->next);
	tmp->next=svr;

	return isvr;
}

is_vardecl* insert_vardecl(is_type* type, char* id, is_commaid_rep* icir){
printf("f: vardecl \n");
    is_vardecl* vd = (is_vardecl*)malloc(sizeof(is_vardecl));

    vd->type = type;
    vd->id = (char*)strdup(id);
    vd->cir = icir;


    return vd;
}


is_statement* insert_statement_brace(is_statement_rep* isr){
printf("f: stat brace\n");
    //TODO ?!?!?!?!?

    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_par;

    is_statement_rep* st_br = (is_statement_rep*)malloc(sizeof(is_statement_rep));
    is_statement_rep* tmp = (is_statement_rep*)malloc(sizeof(is_statement_rep));
    st_br->next = NULL;




    st->data_statement.u_statement_braces = isr;

    return st;
}

is_statement* insert_if_statement(is_expr* expr, is_statement* statement1, is_statement* statement2){
printf("f: if stat\n");
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
printf("f: while stat \n");
    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_while;

    while_statement* wh_st = (while_statement*)malloc(sizeof(while_statement));
    wh_st->expr = expr;
    wh_st->statement = statement;

    st->data_statement.u_while = wh_st;

    return st;
}

is_statement* insert_return_statement(is_expr* expr){
printf("f: return stat\n");
    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_return;

    return_statement* rt_st = (return_statement*)malloc(sizeof(return_statement));
    rt_st->expr = expr;

    st->data_statement.u_return = rt_st;

    return st;
}

is_statement* insert_print_expr_statement(is_expr* expr){
printf("f: print expr stat\n");
    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_print;

    print_statement* pt_st = (print_statement*)malloc(sizeof(print_statement));
    pt_st->data_print.u_expr = expr;
    pt_st->type = d_expr;

    st->data_statement.u_print = pt_st;
    
    return st;
}

is_statement* insert_print_string_statement(char* id){
printf("f: prt str stat\n");
    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_print;

    print_statement* pt_st = (print_statement*)malloc(sizeof(print_statement));
    pt_st->data_print.u_str = (char*)strdup(id);
    pt_st->type = d_string;

    st->data_statement.u_print = pt_st;
    
    return st;
}

is_statement* insert_method_statement(is_methodinvocation* imi){
	printf("f: method stat\n");
    is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_method;
	
	method_statement* mt_st = (method_statement*)malloc(sizeof(method_statement));
	mt_st->mi = imi;

	st->data_statement.u_method_statement = mt_st;

	return st;
}

is_statement* insert_assign_statement(is_assign* assign){
printf("f: assign stat\n");

	is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_assign;

	assign_statement* agn_st = (assign_statement*)malloc(sizeof(assign_statement));
	agn_st->assign = assign;

	st->data_statement.u_assign_statement = agn_st;

	return st;
}

is_statement* insert_parseargs_statement(is_parseargs* parseargs){
printf("f: parse stat\n");
	is_statement* st = (is_statement*)malloc(sizeof(is_statement));

    st->stat_type = d_parse;

	parseargs_statement* prs_st = (parseargs_statement*)malloc(sizeof(parseargs_statement));
	prs_st->parse->expr = parseargs->expr;
	prs_st->parse->id = (char*)strdup(parseargs->id);

	st->data_statement.u_parseargs_statement = prs_st;

	return st;
}

is_statement_rep* insert_statement_rep(is_statement* statement, is_statement_rep* statement_rep){
printf("f: stat rep \n");
	is_statement_rep* stat_rep = (is_statement_rep*)malloc(sizeof(is_statement_rep));
    is_statement_rep* tmp = (is_statement_rep*)malloc(sizeof(is_statement_rep));
    stat_rep->next = NULL;

	stat_rep->statement = statement;

    if(statement_rep==NULL)
    return stat_rep;;

	for(tmp=statement_rep; tmp->next; tmp=tmp->next);
	tmp->next=stat_rep;

	return statement_rep;
}

is_methodinvocation* insert_methodinvocation(char* id, is_expr* expr, is_commaexpr_rep* icer){
printf("f: method invoc \n");
	is_methodinvocation* mi = (is_methodinvocation*)malloc(sizeof(is_methodinvocation));

	mi->expr = expr;
	mi->cer = icer;
	mi->id = (char*)strdup(id);

	return mi;
}

is_commaexpr_rep* insert_comma_expr_rep(is_expr* expr, is_commaexpr_rep* cmr){
printf("f: comma expr rep\n");
	is_commaexpr_rep* cep = (is_commaexpr_rep*)malloc(sizeof(is_commaexpr_rep));

	cep->expr = expr;
	cep->cer = cmr;

	return cep;
}

is_assign* insert_assign(char* id, is_expr* expr){
printf("f: assign\n");
	is_assign* assgn = (is_assign*)malloc(sizeof(is_assign));

	assgn->expr = expr;
	assgn->id = (char*)strdup(id);

	return assgn;
}

is_parseargs* insert_parse_args(char* id, is_expr* expr){
printf("f: parse args \n");
	is_parseargs* prs = (is_parseargs*)malloc(sizeof(is_parseargs));

	prs->expr = expr;
	prs->id = (char*)strdup(id);

	return prs;
}

is_expr* insert_expr_brace(is_expr* expr){
printf("f: expr brace\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    
    //TODO ?loop?
    exp->type = d_brace;
    exp->data_expr.expr_par = expr;

    return exp;
}

is_expr* insert_expr_methodinvocation(is_methodinvocation* mi){
printf("f: expr method invoc\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_mi;

    is_methodinvocation* mv = (is_methodinvocation*)malloc(sizeof(is_methodinvocation));
    mv->cer = mi->cer;
    mv->expr = mi->expr;
    mv->id = (char*)strdup(mi->id);

    exp->data_expr.mi = mv;

    return exp;
}

is_expr* insert_expr_assign(is_assign* assign){
    printf("f: expr assign \n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_agn;

    is_assign* agn = (is_assign*)malloc(sizeof(is_assign));
    agn->expr = assign->expr;
    agn->id = (char*)strdup(assign->id);

    exp->data_expr.assign = agn;

    return exp;
}

is_expr* insert_expr_parseargs(is_parseargs* parseargs){
printf("f: expr parse\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_pa;

    is_parseargs* prs = (is_parseargs*)malloc(sizeof(is_parseargs));
    prs->expr = parseargs->expr;
    prs->id = (char*)strdup(parseargs->id);

    exp->data_expr.pa = prs;

    return exp;
}

is_expr* insert_expr_id(char* id){
printf("f: expr id\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_id;

    is_id* iid = (is_id*)malloc(sizeof(is_id));

    iid->id = (char*)strdup(id);

    exp->data_expr.id = iid;

    return exp;
}

is_expr* insert_expr_dotlenght(char* id){
printf("f: expr dotlenght\n");
//TODO
}

is_expr* insert_expr_intlit(char* id){
printf("f: expr intlit\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_lit;
    expr_lit* iel = (expr_lit*)malloc(sizeof(expr_lit));

    iel->type = d_intlit;
    iel->val = (char*)strdup(id);

    exp->data_expr.el = iel;

    return exp;
}

is_expr* insert_expr_reallit(char* id){
printf("f: expr reallit\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_lit;
    expr_lit* iel = (expr_lit*)malloc(sizeof(expr_lit));

    iel->type = d_reallit;
    iel->val = (char*)strdup(id);

    exp->data_expr.el = iel;

    return exp;
}

is_expr* insert_expr_boollit(char* id){
printf("f: expr boollit\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_lit;
    expr_lit* iel = (expr_lit*)malloc(sizeof(expr_lit));

    iel->type = d_boollit;
    iel->val = (char*)strdup(id);

    exp->data_expr.el = iel;

    return exp;
}

is_expr* insert_expr_minus_expr(is_expr* expr){
printf("f: expr minus expr\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_self;

    exp->data_expr.es->expr = expr;
    exp->data_expr.es->type = d_self_minus;

    return exp;
}

is_expr* insert_expr_not_expr(is_expr* expr){
printf("f: expr not expr\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_self;

    exp->data_expr.es->expr = expr;
    exp->data_expr.es->type = d_self_not;

    return exp;
}

is_expr* insert_expr_plus_expr(is_expr* expr){
printf("f: expr plus expr\n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));
    exp->type = d_self;

    exp->data_expr.es->expr = expr;
    exp->data_expr.es->type = d_self_plus;

    return exp;

}


is_expr* insert_expr_op(is_expr* expr1, char* type, is_expr* expr2){
    printf("f: expr op \n");
    is_expr* exp = (is_expr*)malloc(sizeof(is_expr));


    if( !strcmp(type,"PLUS") ){
        exp->type = d_op;
        exp->data_expr.eop = (expr_op*)malloc(sizeof(expr_op));
        exp->data_expr.eop->type = d_plus;
        exp->data_expr.eop->expr1 = expr1;
        exp->data_expr.eop->expr2 = expr2;
    }
    else if( !strcmp(type,"MINUS") ){
        exp->type = d_op;
        exp->data_expr.eop = (expr_op*)malloc(sizeof(expr_op));
        exp->data_expr.eop->type = d_minus;
        exp->data_expr.eop->expr1 = expr1;
        exp->data_expr.eop->expr2 = expr2;
    }
    else if( !strcmp(type,"STAR") ){
        exp->type = d_op;
        exp->data_expr.eop = (expr_op*)malloc(sizeof(expr_op));
        exp->data_expr.eop->type = d_star;
        exp->data_expr.eop->expr1 = expr1;
        exp->data_expr.eop->expr2 = expr2;
    }
    else if( !strcmp(type,"DIV") ){   
        exp->type = d_op;
        exp->data_expr.eop = (expr_op*)malloc(sizeof(expr_op));     
        exp->data_expr.eop->type = d_div;
        exp->data_expr.eop->expr1 = expr1;
        exp->data_expr.eop->expr2 = expr2;
    }
    else if( !strcmp(type,"MOD") ){
        exp->type = d_op;
        exp->data_expr.eop = (expr_op*)malloc(sizeof(expr_op));
        exp->data_expr.eop->type = d_mod;
        exp->data_expr.eop->expr1 = expr1;
        exp->data_expr.eop->expr2 = expr2;    
    }
    else if( !strcmp(type,"AND") ){
        exp->type = d_logic;
        exp->data_expr.elogic = (expr_logical*)malloc(sizeof(expr_logical));
        exp->data_expr.elogic->type = d_and;
        exp->data_expr.elogic->expr1 = expr1;
        exp->data_expr.elogic->expr2 = expr2;    
    }
    else if( !strcmp(type,"OR") ){
        exp->type = d_logic;
        exp->data_expr.elogic = (expr_logical*)malloc(sizeof(expr_logical));
        exp->data_expr.elogic->type = d_or;
        exp->data_expr.elogic->expr1 = expr1;
        exp->data_expr.elogic->expr2 = expr2; 
    }
    else if( !strcmp(type,"XOR") ){
        exp->type = d_logic;
        exp->data_expr.elogic = (expr_logical*)malloc(sizeof(expr_logical));
        exp->data_expr.elogic->type = d_xor;
        exp->data_expr.elogic->expr1 = expr1;
        exp->data_expr.elogic->expr2 = expr2; 
    }
    else if( !strcmp(type,"LSHIFT") ){
        exp->type = d_shift;
        exp->data_expr.eshift = (expr_shift*)malloc(sizeof(expr_shift));
        exp->data_expr.eshift->type = d_rshift;
        exp->data_expr.eshift->expr1 = expr1;
        exp->data_expr.eshift->expr2 = expr2; 
    }
    else if( !strcmp(type,"RSHIFT") ){
        exp->type = d_shift;
        exp->data_expr.eshift = (expr_shift*)malloc(sizeof(expr_shift));
        exp->data_expr.eshift->type = d_lshift;
        exp->data_expr.eshift->expr1 = expr1;
        exp->data_expr.eshift->expr2 = expr2; 
    }
    else if( !strcmp(type,"EQ") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_eq;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }
    else if( !strcmp(type,"GE") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_ge;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }
    else if( !strcmp(type,"GT") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_gt;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }
    else if( !strcmp(type,"LE") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_le;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }
    else if( !strcmp(type,"LT") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_lt;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }
    else if( !strcmp(type,"NE") ){
        exp->type = d_comp;
        exp->data_expr.ec = (expr_comp*)malloc(sizeof(expr_comp));
        exp->data_expr.ec->type = d_ne;
        exp->data_expr.ec->expr1 = expr1;
        exp->data_expr.ec->expr2 = expr2; 
    }

    return exp;
}














