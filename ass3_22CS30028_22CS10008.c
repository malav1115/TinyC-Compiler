
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lex.yy.c"


extern int yylex();
int totalTokens = 1;


//structure for Token
typedef struct {
    int entry_num;
    char token_type[255];
    char lexeme[255];
} Token;

//structure for symbol table node
typedef struct symbol_Table {
    Token *token;
    struct symbol_Table *next;
} symbol_Table;


// Function prototypes
Token *create_token(int token_type, const char *lexeme);
symbol_Table *addToken(symbol_Table *table, Token *token);
void Print_Table(symbol_Table *table);
void Print_Tokens(symbol_Table *table);
void freeTable(symbol_Table *table);




// Function to create a new token
Token *create_token(int token_type, const char *lexeme) {
    Token *token = (Token *)malloc(sizeof(Token));
    switch(token_type){
        case 1:
            strcpy(token->token_type, "KEYWORD       ");
            break;
        case 2:
            strcpy(token->token_type, "IDENTIFIER    ");
            break;
        case 3:
            strcpy(token->token_type, "CONSTANT      ");
            break;
        case 4:
            strcpy(token->token_type, "STRING_LITERAL");
            break;
        case 5:
            strcpy(token->token_type, "PUNCTUATOR    ");
            break;
        default:
            strcpy(token->token_type, "UNKNOWN");
            break;
    }
    strcpy(token->lexeme, lexeme);
    return token;
}

// Function to add a token to the symbol table. If the token is already present, return the table as it is.
symbol_Table *addToken(symbol_Table *table, Token *token) {
    // If the table is empty, create the first entry
    if (table == NULL) {
        table = (symbol_Table *)malloc(sizeof(symbol_Table));
        table->token = token;
        token->entry_num = totalTokens++;
        table->next = NULL;
        return table;
    }

    // Traverse the table to check if the token already exists
    symbol_Table *temp = table;
    while (temp != NULL) {
        if (strcmp(temp->token->lexeme, token->lexeme) == 0) {
            // Token already exists
            return table;
        }
        if (temp->next == NULL) break;  // Exit loop if at the last node
        temp = temp->next;
    }

    // Add a new token at the end of the table
    token->entry_num = totalTokens++;
    temp->next = (symbol_Table *)malloc(sizeof(symbol_Table));
    temp->next->token = token;
    temp->next->next = NULL;

    return table;
}

// Function to print the symbol table
void Print_Table(symbol_Table *table) {
    printf("-----------------------------------------------------------\n");
    printf("No. \t\t\t Token Type \t\t\t\t     Lexeme\n");
    printf("-----------------------------------------------------------\n");
    symbol_Table *temp = table;
    while (temp != NULL) {
        printf("%d \t\t\t\t %s \t\t\t\t %s\n",temp->token->entry_num, temp->token->token_type, temp->token->lexeme);
        temp = temp->next;
    }
}

void Print_Tokens(symbol_Table *table){
    printf("Total Token count: %d\n", totalTokens-1);
    symbol_Table *temp = table;
    while(temp!=NULL){
        printf("<%s,%s>\n", temp->token->token_type, temp->token->lexeme);
        temp = temp->next;
    }
    printf("\n\n\n\n");
}

// Function to free the allocated memory for the symbol table
void freeTable(symbol_Table *table) {
    symbol_Table *temp;
    while (table != NULL) {
        temp = table;
        table = table->next;
        free(temp->token);  // Free the token itself
        free(temp);         // Free the table node
    }
}

int main() {
    symbol_Table *table_head = NULL;  // Initialize table head to NULL

    Token *token;
    int token_code;
    while ((token_code = yylex()) != 0) {
        token = create_token(token_code, yytext);
        table_head = addToken(table_head, token);
    }
    Print_Tokens(table_head);
    Print_Table(table_head);
    freeTable(table_head);  // Free allocated memory

    return 0;
}