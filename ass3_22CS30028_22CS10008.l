%{
    #define KW 1
    #define ID 2
    #define CONST 3
    #define SL 4
    #define PUNC 5
%}

/*Keyword Definition*/
KEYWORDS   "auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"

/*Identifier Definition*/
IDENT_START  [a-zA-Z_]
NUMBER   [0-9]
IDENT  {IDENT_START}({IDENT_START}|{NUMBER})*

/* Constant Definition*/
INTEGER_CONST   {NUMBER}+
NUMBER_SEQ     {NUMBER}+|\'{CHARACTER_SEQ}\'
FRACTIONAL_PART    {NUMBER_SEQ}?\.{NUMBER_SEQ}|{NUMBER_SEQ}\.
EXPONENT_PART    [eE][+-]?{NUMBER_SEQ}
FLOATING_CONST {FRACTIONAL_PART}{EXPONENT_PART}?|{NUMBER_SEQ}{EXPONENT_PART}
ESCAPE_CHAR  \'|\"|\?|\[abfnrtv]|\\
C_CHAR  [^'\\\n]|{ESCAPE_CHAR}
CHARACTER_SEQ  {C_CHAR}+ 
CHARACTER_CONST  \'{CHARACTER_SEQ}\'
CONSTANT   {INTEGER_CONST}|{FLOATING_CONST}|{CHARACTER_CONST}

/*String Literal*/
STRING_CHAR  [^"\\\n]|{ESCAPE_CHAR}
STRING_SEQ  {STRING_CHAR}+
STRING_LITERAL  \"{STRING_SEQ}?\"

/*Punctuators*/
PUNCTUATORS    "["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"

/*Comments*/
MULTILINE_SEQUENCE    [^*]|[*][^/]
MULTILINE_COMMENT  "/*"({MULTILINE_SEQUENCE})*"/"
SINGLELINE_COMMENT "//".*
COMMENTS {MULTILINE_COMMENT}|{SINGLELINE_COMMENT}

%%

{KEYWORDS}  {return KW;}
{IDENT}  {return ID;}
{CONSTANT} {return CONST;}
{STRING_LITERAL}    {return SL;}
{PUNCTUATORS}  {return PUNC;}
{COMMENTS}   {}
[ \t\n]+    {}
.           {}
%%

int yywrap(void){
    return 1;
}
