
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    NUM = 259,
    TKN_PTOCOMA = 260,
    OR = 261,
    AND = 262,
    NOT = 263,
    COMPARISON = 264,
    UMINUS = 265,
    AMMSC = 266,
    AS = 267,
    BETWEEN = 268,
    CREATE = 269,
    DELETE = 270,
    FROM = 271,
    INSERT = 272,
    INTO = 273,
    LIKE = 274,
    SELECT = 275,
    SET = 276,
    TABLE = 277,
    UPDATE = 278,
    VALUES = 279,
    WHERE = 280,
    NULLX = 281
  };
#endif
/* Tokens.  */
#define NAME 258
#define NUM 259
#define TKN_PTOCOMA 260
#define OR 261
#define AND 262
#define NOT 263
#define COMPARISON 264
#define UMINUS 265
#define AMMSC 266
#define AS 267
#define BETWEEN 268
#define CREATE 269
#define DELETE 270
#define FROM 271
#define INSERT 272
#define INTO 273
#define LIKE 274
#define SELECT 275
#define SET 276
#define TABLE 277
#define UPDATE 278
#define VALUES 279
#define WHERE 280
#define NULLX 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 10 "sintactico.y" /* yacc.c:1909  */

	int intval;
	char  cad;
	int subtok;

#line 112 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
