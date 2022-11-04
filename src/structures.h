#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {d_intlit, d_reallit, d_boollit} lit_type;
typedef enum {d_self_minus, d_self_not, d_self_plus} self_type;
typedef enum {d_plus, d_minus, d_star, d_div, d_mod} op_type;
typedef enum {d_and, d_or, d_xor} logical_bitwise_type;
typedef enum {d_lshift, d_rshift} shift_type;
typedef enum {d_eq, d_ge, d_gt, d_le, d_lt, d_ne} comparation_type;

typedef enum {d_par, d_if, d_while, d_return, d_print, d_method, d_assign, d_parse} statement_type;

typedef enum {d_bool,d_int,d_double,d_void,d_none} disc_type;

// Lists Types
typedef enum { d_mdecl, d_fdecl, d_colon} mrep_type; 
typedef enum { d_statement, d_vardecl} statvar_type;
typedef enum { d_string, d_expr} print_type;
typedef enum { d_brace, d_mi, d_agn, d_pa, d_lit, d_self, d_op, d_logic, d_shift, d_comp, d_id} expr_type;
//TODO MUDAR FUNCOES DO EXPR PARA ADICIIONAR O TIPO

typedef struct _s34 expr_comp;
typedef struct _s33 expr_shift;
typedef struct _s32 expr_logical;
typedef struct _s31 expr_op;
typedef struct _s30 expr_self;
typedef struct _s29 expr_lit;
typedef struct _s27 is_id;
typedef struct _s26 is_expr;
typedef struct _s25 is_parseargs;
typedef struct _s24 is_assign;
typedef struct _s23 is_commaexpr_rep;
typedef struct _s22 is_methodinvocation;
typedef struct _s21 parseargs_statement;
typedef struct _s20 assign_statement;
typedef struct _s19 method_statement;
typedef struct _s18 is_statement_rep;
typedef struct _s17 print_statement;
typedef struct _s16 return_statement;
typedef struct _s15 while_statement;
typedef struct _s14 if_statement;
typedef struct _s13 is_statement;
typedef struct _s12 is_vardecl;
typedef struct _s11 is_statementvar_rep;
typedef struct _s10 is_methodbody;
typedef struct _s9 is_commatypeid_rep;
typedef struct _s8 is_formalparams;
typedef struct _s7 is_methodheader;
typedef struct _s6 is_type;
typedef struct _s5 is_commaid_rep;
typedef struct _s4 is_fielddecl;
typedef struct _s3 is_methoddecl;
typedef struct _s2 is_methodfield_rep;
typedef struct _s1 is_program;


typedef struct _s34{
        is_expr* expr1;
        comparation_type type;
        is_expr* expr2;
} expr_comp;

typedef struct _s33{
        is_expr* expr1;
        shift_type type;
        is_expr* expr2;
} expr_shift;

typedef struct _s32{
        is_expr* expr1;
        logical_bitwise_type type;
        is_expr* expr2;
} expr_logical;

typedef struct _s31{
        is_expr* expr1;
        op_type type;
        is_expr* expr2;
} expr_op;

typedef struct _s30{
        is_expr* expr;
        self_type type;
} expr_self;

typedef struct _s29{
        lit_type type;
        char* val;
} expr_lit;


typedef struct _s27{
        char* id;
} is_id;

typedef struct _s26{
        expr_type type;
        union {
                struct _s26* expr_par;
                is_methodinvocation* mi;
                is_assign* assign;
                is_parseargs* pa;
                expr_lit* el;
                expr_self* es;
                expr_op* eop;
                expr_logical* elogic;
                expr_shift* eshift;
                expr_comp* ec;
                is_id* id;
        }data_expr;
} is_expr;

typedef struct _s25{
        is_expr* expr;
        char* id;
} is_parseargs;

typedef struct _s24{
        is_expr* expr;
        char* id;
} is_assign;

typedef struct _s23{
        is_expr* expr;
        is_commaexpr_rep* cer;
} is_commaexpr_rep;

typedef struct _s22{
        is_expr* expr;
        is_commaexpr_rep* cer;
        char* id;
} is_methodinvocation;

typedef struct _s21{
        is_parseargs* parse;
}parseargs_statement;

typedef struct _s20{
        is_assign* assign;
}assign_statement;

typedef struct _s19{
        is_methodinvocation* mi;
}method_statement;

typedef struct _s18{
        is_statement* statement;
        struct _s18* next;
} is_statement_rep;

typedef struct _s17{
        print_type type;
        union{
                is_expr *u_expr;
                char* u_str;
        }data_print;
} print_statement;

typedef struct _s16{
        is_expr* expr;
} return_statement;

typedef struct _s15{
        is_expr* expr;
        is_statement* statement;
} while_statement;

typedef struct _s14{
        is_expr* expr;
        is_statement* statement1;
        is_statement* statement2;
} if_statement;

typedef struct _s13{
        statement_type stat_type;
        union {
                is_statement_rep* u_statement_braces;
                if_statement* u_if;
                while_statement* u_while;
                return_statement* u_return;
                print_statement* u_print;
                method_statement* u_method_statement;
                assign_statement* u_assign_statement;
                parseargs_statement* u_parseargs_statement;
        }data_statement;

} is_statement;

typedef struct _s12{
        is_type* type;
        is_commaid_rep* cir;
        char* id;
} is_vardecl;

typedef struct _s11{
        statvar_type type;
        union {
                is_statement* statement;
                is_vardecl* vardecl;
        }data_statementvarrep;
        struct _s11* next;
} is_statementvar_rep;

typedef struct _s10{
        is_statementvar_rep* svr;
} is_methodbody;

typedef struct _s9{
        is_type* type;
        struct _s9* next;
        char* id;
} is_commatypeid_rep;

typedef struct _s8{
        is_type* type;
        is_commatypeid_rep* ctir;
        char* id;
} is_formalparams;

typedef struct _s7{
        is_type* type;
        is_formalparams* fp;
        char* id;
} is_methodheader;

typedef struct _s6{
        disc_type disc_t;
} is_type;

typedef struct _s5{
        struct _s5* next;
        char* id;
} is_commaid_rep;


typedef struct _s4{
        is_type* type;
        is_commaid_rep* cir;
        char* id;
} is_fielddecl;


typedef struct _s3{
        is_methodheader* mh;
        is_methodbody* mb;
} is_methoddecl;

typedef struct _s2{
        mrep_type type;
        union{
                is_methoddecl* u_methoddecl;
                is_fielddecl* u_fielddecl;
        }data_methodfield_rep;
        struct _s2* next;
} is_methodfield_rep;

typedef struct _s1{
        is_methodfield_rep* mfr;
        char* id;
} is_program;

#endif
