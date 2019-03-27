#define WORD 257
#define APPEND 258
#define OPEN 259
#define WRITE 260
#define SELECT 261
#define CLOSE 262
#define LOOPEX 263
#define USING 264
#define FORMAT 265
#define DO 266
#define SHIFT 267
#define PUSH 268
#define POP 269
#define LVALFUN 270
#define WHILE 271
#define UNTIL 272
#define IF 273
#define UNLESS 274
#define ELSE 275
#define ELSIF 276
#define CONTINUE 277
#define SPLIT 278
#define SPRINTF 279
#define FOR 280
#define FEOF 281
#define TELL 282
#define SEEK 283
#define STAT 284
#define FUNC0 285
#define FUNC1 286
#define FUNC2 287
#define FUNC3 288
#define STABFUN 289
#define JOIN 290
#define SUB 291
#define FILETEST 292
#define LOCAL 293
#define DELETE 294
#define FORMLIST 295
#define REG 296
#define ARYLEN 297
#define ARY 298
#define SUBST 299
#define PATTERN 300
#define RSTRING 301
#define TRANS 302
#define LISTOP 303
#define DOTDOT 304
#define OROR 305
#define ANDAND 306
#define EQ 307
#define NE 308
#define SEQ 309
#define SNE 310
#define LE 311
#define GE 312
#define SLT 313
#define SGT 314
#define SLE 315
#define SGE 316
#define UNIOP 317
#define LS 318
#define RS 319
#define MATCH 320
#define NMATCH 321
#define UMINUS 322
#define INC 323
#define DEC 324
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int	ival;
    char *cval;
    ARG *arg;
    CMD *cmdval;
    struct compcmd compval;
    STAB *stabval;
    FCMD *formval;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
