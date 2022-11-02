#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef enum {d_intlit, d_reallit, d_boollit} lit_type;
typedef enum {d_self_minus, d_self_not, d_self_plus} self_type;
typedef enum {d_plus, d_minus, d_star, d_div, d_mod} op_type;
typedef enum {d_and, d_or, d_xor} logical_bitwise_type;
typedef enum {d_lshift, d_rshift} shift_type;
typedef enum {d_eq, d_ge, d_gt, d_le, d_lt, d_ne} comparation_type;

typedef enum {d_par, d_if, d_while, d_return, d_print} statement_type;

typedef struct _s{
        is_expr* expr1;
        comparation_type type;
        is_expr* expr2;
} expr_comp;

typedef struct _s{
        is_expr* expr1;
        shift_type type;
        is_expr* expr2;
} expr_shift;

typedef struct _s{
        is_expr* expr1;
        logical_bitwise_type type;
        is_expr* expr2;
} expr_logical;

typedef struct _s{
        is_expr* expr1;
        op_type type;
        is_expr* expr2;
} expr_op;

typedef struct _s{
        is_expr* expr1;
        self_type type;
        is_expr* expr2;
} expr_self;

typedef struct _s{
        is_expr* expr1;
        lit_type type;
        is_expr* expr2;
} expr_lit;


typedef struct _s{
        
        union {
                struct _s* expr_par;
                is_methodinvocation* mi;
                is_assign* assign;
                is_parseargs* pa;
                expr_lit* el;
                expr_self* es;
                expr_op* eop;
                expr_logical* elogic;
                expr_shift* eshift;
                char* id;
        }data_expr;
} is_expr;

typedef struct _s{
        is_expr* expr;
        char* id;
} is_parseargs;

typedef struct _s{
        is_expr* expr;
        char* id;
} is_assign;

typedef struct _s{
        is_expr* expr;
        is_commaexpr_rep* cer;
} is_commaexpr_rep;

typedef struct _s{
        is_expr* expr;
        is_commaexpr_rep* cmr;
        char* id;
} is_methodinvocation;

typedef struct _s{
        is_parseargs* parse;
}parseargs_statement;

typedef struct _s{
        is_assign* assign;
}assign_statement;

typedef struct _s{
        is_methodinvocation* mi;
}method_statement;

typedef struct _s{
        is_statement* statement;
        struct _s* next;
} is_statement_rep;

typedef struct _s17{
        is_expr *expr;
        
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
                if_statement* u_if;
                while_statement* u_while;
                return_statement* u_return;
                print_statement* u_print;
                is_statement_rep* u_statement_rep;
                method_statement* u_method_statement;
                assign_statement* u_assign_statement;
                parseargs_statement* u_parseargs_statement;
        }data_statement;

} is_statement;

typedef struct _s12{
        is_type* type;
        is_commaid_rep* cir;
} is_vardecl;

typedef struct _s11{
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
        char* id; //TODO STRING?!?!?!?!?
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

typedef enum {d_bool,d_int,d_double,d_void} disc_type;

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
