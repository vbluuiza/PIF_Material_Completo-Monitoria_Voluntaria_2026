#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

/*
Tipos: (ME) múltipla escolha, (CS) análise de código/saída, (VF) verdadeiro ou falso (assinale V ou F e justifique quando F), ou implementação de código.
*/

// 1) Qual caraectere marca o fim de uma string em C? -> "\0"

// 2) Qual biblioteca padrão contém as funções strlen, strcpy e strcat? -> <string.h>

// 3) O vetor char nome[5] = "João"; está corretamente dimensionado para armazenar a string e o caractere nulo. -> Verdade (OBS: Em UTF-8, 'ã' usa 2 bytes → nome[5] pode não ser suficiente.)

// 4) Dado char s[] = "CESAR";, qual é o valor retornado por strlen(s)? -> 5

// 5) Qual a saída? -> "Oi!"

// 6) A função gets() é recomendada por ser segura contra estouro de buffer. -> Falso (Ao contrário de funções seguras como fgets(), gets() não possui um parâmetro para limitar a quantidade de caracteres lidos, o que permite sobrescrever áreas de memória adjacentes se a entrada for maior que o buffer alocado.)

// 7) Para ler uma linha inteira (até a quebra de linha) usando scanf, o formato correto é: -> "%[^\n]"

// 8) Saída do código: -> 0

// 9)  tolower('A') retorna 'a'. -> Verdade

// 10) Qual função copia no máximo N caracteres de uma string origem para o destino? -> strncpy

// 11) Saída: -> 10

// 12)  O código ASCII do caractere '0' é menor que o código de 'A'. -> Verdadeiro ('0' = 48 / 'A' = 65)

// 13) Função que converte todos os caracteres de uma string para maiúsculo: -> strupr

// 14) Saída: -> 'nao'

// 15)  isspace('\t') devolve verdadeiro. -> Verdadeiro

// 16) Qual destas não é função da ctype.h? -> <ctype.h> contém funções que testam ou convertem caracteres individuais, strcasecmp() não pertence.

// 17) Saída: -> 'CES' 

// 18) (VF) strcmp("ABC", "abc") devolve 0 em sistemas sem distinção de maiúsculas/minúsculas. -> Falso

// 19) A expressão 'a' - 'A' vale: -> 32

// 20) Saída: -> 5

// 21) (VF) Uma string declarada como constante (entre aspas) já inclui automaticamente o '\0'. -> Verdadeiro

// 22) Para copiar exatamente 5 caracteres, incluindo o nulo, de orig para dest, usa‑se: -> strncpy(dest, orig, 5)

// 23) Saída: -> 1 (\n' é um caractere de espaço em branco (nova linha), e isspace() retorna 1 (verdadeiro) para espaços, tabs, quebras de linha...)

// 24)  A função puts adiciona automaticamente uma quebra de linha após imprimir a string. -> Verdadeiro

// 25) Qual código imprime o tamanho de "PIF" seguido de uma quebra de linha? -> printf("%d\n", strlen("PIF"));

// 26) Saída: -> é um array de caracteres. *(p + 1) → pega o valor armazenado nesse endereço, ou seja, 'b'.

// 27) sizeof("abc") devolve 3. -> Falso, devolve 4

// 28) (ME) Em char nome[100];, quantos bytes são reservados? -> 100

// 29) Saída: -> Problema: %s faz o printf imprimir até encontrar um '\0' (nulo). Mas o array não tem '\0' no final. O printf vai começar em arr[0] e continuar lendo além do fim do array, até achar acidentalmente um byte 0 na memória.

// 30) (VF) strcat não verifica se há espaço suficiente no destino.) -> Verdadeiro (Se não houver espaço suficiente: Pode sobrescrever memória vizinha / Gerar comportamento indefinido, travar o programa ou corromper dados.)

// 31) Qual função localiza a primeira ocorrência de um caractere em uma string? -> strchr (strchr(str, ch): Localiza a primeira ocorrência do caractere ch em str.)

// 32) Saída: -> 'nana' // ptr → o endereço do 'n' *ptr → o caractere 'n'

// 33) (VF) strtok modifica a string original ao tokenizar. -> Verdadeiro

// 34) (ME) A tabela ASCII define quantos caracteres básicos? -> 128

// 35) Saída: -> A

// 36) Qual palavra‑chave indica que uma função não retorna valor? -> void

// 37) (VF) Funções em C devem ser declaradas dentro da função main. -> Falso

// 38) Saída: -> 7

// 39) ME) O tipo de sqrt definido em math.h é: -> double

// 40) (VF) Variáveis declaradas fora de qualquer função têm escopo global. -> Verdadeiro

// 41) (ME) Qual é a forma correta de prototipar uma função que recebe um char* e devolve int? -> a) int f(char*);

// 42) (CS) Saída: -> 6

// 43) (VF) É possível declarar duas funções com o mesmo nome e parâmetros em C (overload). -> Falso (C não tem function overloading)

// 44) (ME) Em C, argumentos são passados: -> c) Por valor, mas ponteiros permitem efeito de referência

// 45) Saída: ->  1 2

// 46) Uma função pode ser chamada antes de sua declaração se houver protótipo. -> Verdadeiro

// 47) Qual modificador armazena uma variável local na memória estática preservando seu valor? -> Static (faz com que uma variável local (dentro de uma função) seja armazenada na memória estática, ou seja, mantém seu valor entre várias chamadas da função.)

// 48) Saída: -> comportamento indefinido, mas visualmente parece “3” seguido de lixo.

// 49) Um procedimento é simplesmente uma função que retorna void. -> Verdadeiro

// 50) (ME) Qual opção representa corretamente uma chamada de função embutida (nested call)? -> b) printf("%f", sqrt(16));

// 51) Saída: -> 13

// 52) (VF) Variáveis globais podem ser redeclaradas dentro de uma função sem erro. -> Falso, causaria sombreamento (esconde (sombreia) a global dentro desse escopo (função))

// 53) (ME) Qual diretiva inclui a biblioteca com scanf? -> #include <stdio.h>

// 54) (CS) Saída: -> "ok"

// 55) (VF) O return em main comunica ao sistema operacional o status de execução. -> Verdadeiro

// 56) (ME) Assinale a afirmativa correta. -> c) O compilador aceita múltiplos return dentro da mesma função.

// 57) (CS) Saída: -> 24

// 58) (VF) Uma função recursiva deve sempre ter um caso base. -> Verdadeiro

// 59) (ME) Qual palavra-chave impede que uma variável global seja visível em outros arquivos. -> static, quando usada em uma variável global, limita sua visibilidade apenas ao arquivo em que foi declarada.
/*
| Palavra-chave | Função                                                         |
| ------------- | -------------------------------------------------------------- |
| `static`      | restringe o **escopo ao arquivo**                              |
| `extern`      | permite **usar uma variável global definida em outro arquivo** |
| `auto`        | define variáveis locais (padrão implícito)                     |
| `const`       | impede modificação do valor, mas **não** afeta visibilidade    |
*/

// 60) (CS) Saída: -> 7

// 61) (VF) A instrução scanf("%d", x); está correta para ler um int. -> Falso, está faltando do endereço da varíavel (&)

// 62) (ME) Em int (*pf)(int,int);, pf é. -> pf é um ponteiro para função que recebe dois inteiros e retorna um inteiro.        

// 63) (CS) Saída: -> 3

// 64) (VF) O escopo de uma variável register é sempre global. -> Falso, Variáveis declaradas com o modificador register têm escopo local, nunca global.

// 65) (ME) Qual é o valor de retorno padrão de main quando omitido. -> No padrão C99 (e posteriores), se você não usar return dentro de main(), o compilador assume automaticamente return 0;

// 66) (ME) Qual palavra-chave define uma estrutura em C. -> struct, exemplo 
/*
struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};
*/

// 67) (VF) Todos os membros de uma struct ocupam o mesmo endereço de memória. -> cada membro ocupa seu próprio espaço na memória, um após o outro (podendo haver padding ( Padding é o espaço extra na memória que o compilador adiciona dentro de uma struct para alinhar os dados e melhorar o desempenho do processador. )entre eles).

// 68) (CS) Saída: -> 2

// 69) (ME) Para criar um alias Pessoa para uma struct, usa-se. -> typedef struc {...} Pessoa;

// 70) (VF) Podemos declarar um vetor de structs. -> Verdadeiro

// 71) (ME) Dada Cachorro dog;, o acesso ao campo raca é. -> dog.raca

// 72) (CS) Saída: -> 01: 02

// 73) (VF) É possível ter um membro de struct que seja outra struct. -> Verdadeiro (nested structs)
/*
#include <stdio.h>

struct Data {
    int dia, mes, ano;
};

struct Pessoa {
    char nome[50];
    struct Data nascimento; // struct dentro de outra struct
};

int main() {
    struct Pessoa p = {"Luiza", {10, 10, 2000}};
    printf("%s nasceu em %d/%d/%d\n",
           p.nome, p.nascimento.dia, p.nascimento.mes, p.nascimento.ano);
}
*/

// 74) (ME) Uma union difere de uma struct porque. -> c) Compartilha a mesma área de memória

// 75) (CS) Saída: -> Como a e c ocupam a mesma área de memória, atribuir 65 a 'a' faz com que 'a' contenha 'A'.

// 76) (VF) Atribuir a um membro de uma union sobrescreve os demais. -> Verdadeiro, todos os membros compartilham a mesma área de memória

// 77) (ME) Qual diretiva imprime o deslocamento de bytes de um campo dentro da struct. -> A macro offsetof, definida em <stddef.h>, retorna o deslocamento (em bytes) de um campo dentro de uma struct.

// 78) (CS) Saída: -> 25.5

// 79) (VF) typedef pode ser usado para rotular tanto structs quanto enums. -> Verdadeiro

// 80) (ME) Enumerações em C atribuem por padrão valores inteiros começando em. -> 0

// 81) (CS) Saída: ->> 3

// 82) (VF) É permitido ter dois membros enum com o mesmo valor numérico. -> Verdadeiro, apenas os nomes precisam ser únicos.

// 83) (ME) Para imprimir o valor 2 de um enum cores {VERM,AZUL,VERDE};, usa-se. ->> b) printf("%d", VERDE);

// 84) (CS) Saída: ->> (uma tabulação horizontal)

// 85) (VF) Uma variável enum pode receber um valor inteiro fora da lista, mas é má prática. ->> Verdadeiro, é permitido atribuir manualmente qualquer valor inteiro a uma variável do tipo enum, mesmo que o valor não esteja definido na lista da enumeração.

// 86) (ME) Qual declaração cria um vetor de 10 structs Aluno. ->> Aluno alunos[10]; cria um vetor de 10 elementos, cada um sendo uma struct Aluno.

// 87) (CS) Saída: ->> 5

// 88) (VF) Podemos inicializar parcialmente uma struct usando designadores. ->> Verdadeiro
/*
struct Ponto {
    int x, y, z;
};

int main() {
    struct Ponto p = { .x = 10, .z = 5 }; // inicializa apenas x e z
    printf("%d %d %d\n", p.x, p.y, p.z);
}
*/

// 89) (ME) Qual operador seleciona um membro via ponteiro para struct. ->> '->' (Acesso direito '.' /. acesso via ponteiro '-> ')

// 90) (CS) Saída: ->> O código declara um ponteiro pp para uma struct, define ele como NULL, e imprime o valor desse ponteiro (0x0) — indicando que ele não aponta pra nada.
 
// 91) (VF) sizeof(struct vazio{}) é 0 em C. ->> Falso, o resultado de sizeof(struct vazio) nunca é 0 — geralmente é 1 byte.

// 92) (ME) Para criar um tipo union chamado Numero contendo int i e float f. ->> a) union Numero{int i;float f;}; e c) typedef union{int i;float f;} Numero;

// 93) (CS) Saída: ->> 2 

// 94) (VF) O tamanho de uma union é igual ao tamanho de seu maior membro. ->> Verdadeiro, O tamanho de uma union é determinado pelo maior membro, já que todos compartilham o mesmo espaço de memória.

// 95) (ME) Qual das alternativas define corretamente uma enum para dias úteis com alias diaUtil. -> Todas acima

// 96) (CS) Saída: ->> 8

// 97) (VF) O preenchimento (padding) pode aumentar o tamanho real de uma struct além da soma de seus membros. ->> O padding pode sim aumentar o tamanho real da struct, para garantir alinhamento e acesso eficiente à memória.

// 98) (ME) Qual expressão acessa o segundo elemento do vetor canil de tipo Cachorro. ->> canil[1]

// 99) (ME) Qual operador é usado para obter o endereço de uma variável. ->> '&'

// 100) (ME) Dado int x = 10; int *p = &x;, o valor de *p é. ->> O valor armazenado em x

// 101) (VF) O operador * serve tanto para declarar quanto para acessar o valor apontado por um ponteiro. ->> Verdadeiro, usado para delcarar o ponteiro e desreferenciar (acessar o valor apontado)    

// 102) (CS) Saída: ->> 15

// 103) (ME) Se int *p; foi declarado mas não inicializado, então. ->> Contém um valor indeterminado

// 104) (VF) Um ponteiro void* pode apontar para qualquer tipo de dado, mas não pode ser dereferenciado sem conversão. ->> void* é um ponteiro genérico — ele pode armazenar o endereço de qualquer tipo de dado, mas não pode ser desreferenciado diretamente, porque o compilador não sabe o tipo e o tamanho do dado apontado.

// 105) (CS) Saída: --> 4

// 106) (ME) Qual é a forma correta de declarar um ponteiro para ponteiro para inteiro. ->> int **p

// 107) (VF) p++ em um ponteiro incrementa o endereço armazenado em uma unidade de byte. ->> Falso, ele não soma 1 byte e sim 1 unidade do tipo para o qual ele aponta.

// 108) (ME) O que ocorre ao tentar acessar um ponteiro não inicializado. ->> Comportamento indefinido

// 109) (VF) A expressão &*p é equivalente a p. ->> Verdadeiro, &*p é equivalente a p, pois pegar o endereço de algo que você acabou de desreferenciar retorna o mesmo ponteiro.

// 110) (ME) Qual opção imprime corretamente o endereço de uma variável x. ->>  b) printf("%p", &x);

// 111) (CS) Saída: ->> 0x16f702514 10

// 112) (VF) O tipo char *p = "texto"; cria uma string constante armazenada em área somente leitura. ->> Verdaedeiro, char *p = "texto"; → string constante em memória somente leitura. Para modificar a string, declare como vetor (char p[]).

// 113) (ME) O que acontece ao executar free(p) sobre um ponteiro não obtido por malloc. ->> Gera comportamento indefinido

// 114) (CS) Saída: --> 7 7

// 115) (VF) Um array e um ponteiro para seu primeiro elemento são equivalentes em expressões aritméticas. ->> o nome de um array (como v) é convertido automaticamente em um ponteiro para o seu primeiro elemento (&v[0]) quando usado em expressões.
/*
int v[3] = {10, 20, 30};
int *p = v;           // v → &v[0]
printf("%d\n", *(p+1));   // imprime 20
printf("%d\n", *(v+1));   // também imprime 20
*/

// 116) (ME) Qual expressão equivale a v[i] se v é um ponteiro. ->> *(v + 1)

// 117) (CS) Saída: ->> 'F'

// 118) (VF) Ponteiros podem ser usados para percorrer vetores e strings sem índice. ->> Verdadeiro, Em C, ponteiros podem ser usados para percorrer vetores ou strings sem usar colchetes ([]), aproveitando a aritmética de ponteiros.
/*
int v[] = {10, 20, 30};
int *p = v;

while (p < v + 3) {
    printf("%d ", *p); // acessa o valor atual
    p++;                // avança para o próximo elemento
}
Saída: 10 20 30

Exemplo com string:
char s[] = "Oi";
char *p = s;

while (*p != '\0') {
    putchar(*p); // imprime caractere atual
    p++;          // avança para o próximo
}
Saída: Oi
*/

// 119) (ME) Dado int x=5, *p=&x;, o que imprime printf("%d", ++*p);. ->> 6

// 120) (VF) Ponteiros para funções permitem armazenar endereços de funções e chamá-las dinamicamente. ->> Verdadeiro. útil para callbacks, menus, ou funções genéricas.


int soma(int a, int b); // 46) protótipo (declaração)

int soma(int a, int b) { // 39)
    return a + b;
}


void inc(int *p){ // 42)
    (*p)++;
} 


void show(int n){ // 48)
    printf("%d",n);
}


int num5 = 10; // 51)
int soma2(int a){
    return a+num5;
} 


void altera(int *p) { // 44)
    *p = 10;  // modifica o valor original
}


int f() { // 45
    static int c = 0;  // variável estática -> criada só uma vez
    return ++c;  // incrementa e retorna o novo valor
}

int foo2 () { // 54
    int x = 1;
}

int f2(int n) { // 57)
    if (n == 0) return 1;
    return n*f2(n-1);
}

int g2(int a, int b) { // 60)
    return a > b ? a : b;
}

int add (int a, int b) { // 63
    return a + b;}


struct P{  // 68)
    int x, y;
} pessoa = { 1 , 2  };


typedef struct { // 71
    int h, m, s;
} Hora;

union U { // 75)
    int a;
    char c;
};

typedef union { // 78)
    float t;
    char st;
} Sensor;


enum dia{ // 81)
    SEG=1,TER,QUA
};


enum escape { // 84)
    TAB='\t',
    NL='\n'
};


struct S { // 87)
    int a;
};


struct K { // 90) Define um tipo de estrutura chamada P, com um único campo x.
    int x;
};

enum mes { // 93)
    JAN=1, FEV
};

struct A {
    char c;
    int i;
};

int main() {

    // 3)
    char nome[5] = "João";
    printf("%s\n", nome); 

    // 4)
    char s[] = "CESAR";
    printf("%lu\n", strlen(s)); // 5

    // 5)
    char txt[20] = "Oi";
    strcat(txt, "!");
    printf("%s\n", txt); // Oi!

    // 8)
    char a[] = "abc";
    char b[] = "abc";
    int r = strcmp(a, b);
    printf("%d\n", r); // 0

    // 9)
    char u = 'A'; 
    char l = tolower(u);
    printf("%c in lowercase is %c\n", u, l); 

    // 11)
    char t[10] = "abc";
    printf("%lu\n", sizeof(t)); // 10

    // 14)
    char x = 'a';
    if (isdigit(x)) printf("digito\n");
    else printf("nao\n"); // nao

    // 15)
    if (isspace('\t'))
        printf("Verdadeiro\n"); // Verdadeiro
    else
        printf("Falso\n");

    // 17)
    char p[10] = "C";
    strncat(p, "ESAR", 2);
    printf("%s\n", p); //C ES

    // 18)
    printf("%d\n", strcmp("ABC", "abc")); // -1

    // 19) 
    printf("%d\n", ('a' - 'A')); // 32

    // 20)
    char k[] = "12345";
    printf("%c\n", k[ strlen(k) - 1 ]); // 5

    // 23)
    char c = '\n';
    printf("%d\n", isspace(c)); // 1

    // 25)
    printf("%zu\n", strlen("PIF")); // 3

    // 26)
    char word[] = "abc";
    printf("%c\n", *(word+1)); // b

    // 27)
    printf("%lu\n", sizeof("abc")); // 4

    // 29)
    char arr[4] = {'c','o','d','e'};
    printf("%s\n", arr); // comportamento indefinido (pode imprimir "code" + lixo)

    // 32)
    char *ptr = strchr("banana", 'n');
    printf("%s\n", ptr); // nana

    // 33)
    char texto[] = "um,dois,tres";
    char *token = strtok(texto, ",");

    while (token) {
        printf("%s\n", token); // um dois tres
        token = strtok(NULL, ","); 
    }

    // 35)
    printf("%c\n", "ABC"[0]); // A

    // 38)
    printf("%d\n", soma(3,4)); // 7

    // 42)
    int num = 5;
    inc(&num);
    printf("%d\n", num); // 6

    // 44) 
    int num2 = 5;
    altera(&num2);
    printf("%d\n", num2); // 10

    // 45)
    printf("%d %d\n",f(),f()); // 1 2

    // 48)
    // printf("%d", show(3));
                            /* -> O primeiro printf dentro de show imprime 
                            O segundo printf tenta imprimir o “retorno” de show, que é indefinido.
                            Isso causa comportamento indefinido → pode mostrar um número aleatório ou nada. */


    // 51)
    printf("%d\n",soma2(3));

    // 54)
    foo2();            // chama foo(), mas ela não imprime nada
    printf("ok\n");    // "ok"

    // 57)
    printf("%d\n", f2(4)); // 24

    // 60)
    printf("%d\n", g2(2, 7)); // 7

    // 63)
    int (*p2)(int, int) = add; /*
                                Aqui estamos declarando uma variável especial chamada p. Ela não é um número nem um texto, 
                                ela é um ponteiro para uma função. Pense nela como uma etiqueta ou um atalho que 
                                pode apontar para qualquer função que receba dois inteiros e retorne um inteiro.
                                */ 
    printf("%d\n",(*p2)(1, 2)); // 3
    
    // 68)
    printf("%d\n", pessoa.y); // 2

    // 71)
    Hora hora1 = {1, 2, 3};
    printf("%02d:%02d\n", hora1.h, hora1.m); // 01:02

    // 75)
    union U unionzinho;
    unionzinho.a = 65;
    printf("%c\n", unionzinho.c);

   // 78) 
   Sensor sen;
   sen.t = 25.5;
   printf("%.1f\n", sen.t); // 25.5

   // 81)
   printf("%d\n",QUA); // 3

   // 84)
   printf("%c\n", TAB);

   // 87)
   struct S struc = {5};
   printf("%d\n", struc.a); // 5

   // 90)
   struct K *pp=NULL; // Cria um ponteiro para struct P, chamado pp, e o inicializa com NULL
   printf("%p\n", (void*)pp); // 0x0

   // 93)
   printf("%d\n",FEV); // 2

   // 96)
   printf("%zu\n", sizeof(struct A)); // 8

   // 100)
    int x1 = 10;
    int *ptr1 = &x1;
    printf("%d\n", *ptr1);

    // 101)
    int a1 = 5, b1 = 10;
    int *p1  = &a1;
    *p1 = *p1 + b1;
    printf("%d\n",  a1); // 15

    // 105)
    int v[3] = {2, 4, 6};
    int *pointer = v;
    printf("%d\n", *(pointer + 1)); // 4

    // 111)
    int xx = 10;
    int *ppp = &xx;
    printf("%p %d\n", ppp, *ppp); // 0x16f702514 10

    // 114)
    int y = 4, h = 7;
    int *ponteiro = &y, *q = &h;
    *ponteiro = *q;
    printf("%d %d\n", y, h); // 7 7

    // 117) 
    char palavra[] = "PIF";
    char *pon = palavra;
    printf("%c\n", *(pon + 2)); // F

    // 119
    int xxx = 5, *poin = &xxx;
    printf("%d\n", ++*poin); // 6
}