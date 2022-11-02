#include "structures.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

is_program* insert_program(is_methodfield_rep* imfr);

is_methodfield_rep* insert_methoddecl_methodfield(is_methoddecl* imd, is_methodfield_rep* imfr);
is_methodfield_rep* insert_fielddecl_methodfield(is_fielddecl* imd, is_methodfield_rep* imfr);
is_methodfield_rep* insert_semicolon_methodfield(is_methodfield_rep* imfr);

is_methoddecl* insert_methoddecl(is_methodheader* imd, is_methodbody* imb);

is_fielddecl* insert_fielddecl(is_type* type, is_commaid_rep* icir);

is_commaid_rep* insert_comma_id_rep(is_commaid_rep* icir);

//TODO TYPE

is_methodheader* insert_methodheader(is_type* type,char* id, is_formalparams* ifp);

is_formalparams* insert_params(is_type* type,char* id, is_commatypeid_rep* ictir);
is_formalparams* insert_string(char* id);

is_commatypeid_rep* insert_commatype_id_rep(is_type* type,char* id, is_commatypeid_rep* ictir);

is_methodbody* insert_methodbody(is_statementvar_rep* isvr);

is_statementvar_rep* insert_statementvar_rep(is_statement* statement, is_statementvar_rep* isvr);
is_statementvar_rep* insert_vardecl_statement(is_vardecl* ivd, is_statementvar_rep* isvr);

is_vardecl* insert_vardecl(is_type* type, char* id, is_commaid_rep* icir);

is_statement* insert_statement_brace(is_statement_rep* isr);
is_statement* insert_if_statement(is_expr* expr, is_statement* statement1, is_statement* statement2);
is_statement* insert_while_statement(is_expr* expr, is_statement* statement);
is_statement* insert_return_statement(is_expr* expr);
is_statement* insert_print_expr_statement(is_expr* expr);
is_statement* insert_print_string_statement(); //TODO QQ RECEBE AQUI???
is_statement* insert_method_statement(is_methodinvocation* imi);
is_statement* insert_assign_statement(is_assign* assign);
is_statement* insert_parseargs_statement(is_parseargs* parseargs);

is_statement_rep* insert_statement_rep(is_statement* statement, is_statement_rep* statement_rep);

is_methodinvocation* insert_methodinvocation(is_expr* expr, is_commaexpr_rep* cer);

is_commaexpr_rep* insert_comma_expr_rep(is_expr* expr, is_commaexpr_rep* cmr);

is_assign* insert_assign(char* id, is_expr* expr);

is_parseargs* insert_parse_args(char* id, is_expr* expr);

is_expr* insert_expr_brace(is_expr* expr);
is_expr* insert_expr_methodinvocation(is_methodinvocation* mi);
is_expr* insert_expr_assign(is_assign* assign);
is_expr* insert_expr_parseargs(is_parseargs* parseargs);
is_expr* insert_expr_id(char* id); //TODO ?!?!?!?!?!?
is_expr* insert_expr_intlit(); //TODO ?!?!?!?!?!?
is_expr* insert_expr_realit(); //TODO ?!?!?!?!?!?
is_expr* insert_expr_boollit(); //TODO ?!?!?!?!?!?
is_expr* insert_expr_minus_expr(is_expr* expr);
is_expr* insert_expr_not_expr(is_expr* expr);
is_expr* insert_expr_plus_expr(is_expr* expr);
is_expr* insert_expr_op(is_expr* expr1, ,is_expr* expr2); ////TODO QQ FALTA NO MEIO?!?!?!?
