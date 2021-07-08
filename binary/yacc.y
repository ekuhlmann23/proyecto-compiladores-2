%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int yylex();
void yyerror(char* s);
const char* decimalABinario(int n);
void procesarInstruccionDe3Parametros(char* instruccionRecibida, const char* param1, const char* param2, const char* param3);
const char* literalANumeroBinario(char* literalrecibido);
const char* registroANumeroBinario(char* registroRecibido);
void procesarInstruccionDe2Parametros(char* instruccionRecibida, const char* param1, const char* param2);
void procesarInstruccionDe1Parametro(char* instruccionRecibida, const char* param1);
//Buffer en donde se almacena la forma binaria final
char formaFinal[500];
// Instrucciones en ASM. Se setean en el main. 
const char* instrucciones[15] = {
    "LOAD",
    "STORE",
    "LOADI",
    "STOREI",
    "JMP",
    "BB",
    "BEQ",
    "AND",
    "OR",
    "XOR",
    "NOT",
    "ADD",
    "SUB",
    "MOV",
    "CMP",
};
%}

%union
{
    char *stringValue;
    const char* constString;
}

%token<stringValue> instruccion
%token<stringValue> registro 
%token<stringValue> numero
//El parámetro es un número literal o un registro en forma binaria
%type<constString> parametro
%%

/* 
    Inicio -> Comando
    Comando -> instruccion parametro | instruccion parametro parametro 
                    | instruccion parametro parametro parametro
    parametro -> registro | numero
*/

Inicio: Inicio Comando '\n' {
    FILE* file = fopen("binary.txt", "a");
    fprintf(file, "%s\n", formaFinal);
    fclose(file);
}
|
;

Comando: 
instruccion parametro {procesarInstruccionDe1Parametro($1, $2);}
| instruccion parametro parametro {procesarInstruccionDe2Parametros($1, $2, $3);}
| instruccion parametro parametro parametro {procesarInstruccionDe3Parametros($1, $2, $3, $4);}
;

parametro: 
registro    {$$ = registroANumeroBinario($1);}
| numero    {$$ = literalANumeroBinario($1);}    
;

%%

const char* decimalABinario(int n)
{
    switch (n) 
    {
        case 0:
            return "0000";
            break;
        case 1:
            return "0001";
            break;
        case 2:
            return "0010";
            break;
        case 3:
            return "0011";
            break;
        case 4:
            return "0100";
            break;
        case 5:
            return "0101";
            break;
        case 6:
            return "0110";
            break;
        case 7:
            return "0111";
            break;
        case 8:
            return "1000";
            break;
        case 9:
            return "1001";
            break;
        case 10:
            return "1010";
            break;
        case 11:
            return "1011";
            break;
        case 12:
            return "1100";
            break;
        case 13:
            return "1101";
            break;
        case 14:
            return "1110";
            break;
        case 15:
            return "1111";
            break;
    }
}

const char* literalANumeroBinario(char* literalrecibido)
{
    int literal;
    literal = atoi(literalrecibido);
    return decimalABinario(literal);    
}

const char* registroANumeroBinario(char* registroRecibido)
{
    char* stringsinR = registroRecibido + 1;
    return literalANumeroBinario(stringsinR);
}

void procesarInstruccionDe3Parametros(char* instruccionRecibida, const char* param1, const char* param2, const char* param3)
{
    formaFinal[0] = '\0';
    // Partes usadas para formar la hilera binaria
    char* espacio = " ";
    char* espacioBinario = "0000";
    // Se crea el buffer para guardar el binario final. 
    // Se busca la instrucción leída. 
    int i;
    for(i = 0; i < 15; i++)
    {
        //Se itera el arreglo de instrucciones hasta encontrar el match. 
        if(!(strcmp(instruccionRecibida, instrucciones[i])))
        {
            //Se añade el opcode a la instrucción
            int opcode = i + 1;
            const char* opcodeEnBinario = decimalABinario(opcode);
            strcat(formaFinal, opcodeEnBinario);
            strcat(formaFinal, espacio);

            //Se añade el resto del cuerpo a la instrucción.
            switch (i) 
            {
                //LOAD -> registro 0000 posición memoria
                //LOAD -> p1 0000 p2
                case 0:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    break;
                //STORE -> registro 0000 posición memoria
                //LOAD -> p1 0000 p2
                case 1:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    break;
                //LOADI -> registro inmediato 0000
                //LOADI -> p1 p2 0000
                case 2:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    break;
                //STOREI -> 0000 inmediato posición memoria
                //STOREI -> 0000 p1 p2
                case 3:
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    break;
                //JMP -> 0000 0000 posición memoria
                //JMP -> 0000 0000 p1
                case 4:
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param1);
                    break;
                //BB -> 0000 0000 posición memoria
                //BB -> 0000 0000 p1
                case 5:
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param1);
                    break;
                //BEQ ->  0000 0000 0000
                //BEQ ->  0000 0000 0000
                case 6:
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    break;
                //AND -> registro registro registro
                //AND -> p1 p2 p3
                case 7:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param3);
                    break;
                //OR -> registro registro registro
                //OR -> p1 p2 p3
                case 8:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param3);
                    break;
                //XOR -> registro registro registro
                //XOR -> p1 p2 p3
                case 9:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param3);
                    break;
                //NOT -> registro 0000 registro
                //NOT -> p1 0000 p2                
                case 10:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    break;
                //ADD -> registro registro registro
                //ADD -> p1 p2 p3
                case 11:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param3);
                    break;
                //SUB -> registro registro registro
                //SUB -> p1 p2 p3
                case 12:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param3);
                    break;
                //MOV -> registro registro 0000
                //MOV -> p1 p2 0000
                case 13:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    break;
                //CMP -> registro registro 0000
                //CMP -> p1 p2 0000
                case 14:
                    strcat(formaFinal, param1);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, param2);
                    strcat(formaFinal, espacio);
                    strcat(formaFinal, espacioBinario);
                    break;
            }
        }

    }
}

void procesarInstruccionDe2Parametros(char* instruccionRecibida, const char* param1, const char* param2)
{
    const char* nullParameter3 = "null";
    procesarInstruccionDe3Parametros(instruccionRecibida, param1, param2, nullParameter3);
}

void procesarInstruccionDe1Parametro(char* instruccionRecibida, const char* param1)
{
    const char* nullParameter2 = "null";
    procesarInstruccionDe2Parametros(instruccionRecibida, param1, nullParameter2);
}

void yyerror(char* s) {
    if (s == "syntax error")
        fprintf(stderr, "%s\n", "Error de sintaxis.");
    else
        fprintf(stderr, "%s\n", s);
    fprintf(stderr, "%s\n", "Hilera rechazada.");
}
