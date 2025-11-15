#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// ============================================
// EXEMPLO 1: STRUCT BÁSICA
// ============================================
// Uma struct é um tipo de dado composto que agrupa variáveis de diferentes tipos
struct Pessoa {
    char nome[50];      // Campo de texto (array de char)
    int idade;          // Campo inteiro
    float altura;       // Campo com decimais
};

// ============================================
// EXEMPLO 2: STRUCT COM TYPEDEF
// ============================================
// typedef permite criar um alias para o tipo, facilitando o uso
typedef struct {
    int x;              // Coordenada X
    int y;              // Coordenada Y
} Ponto;

// ============================================
// EXEMPLO 3: STRUCT ANINHADA (Struct dentro de Struct)
// ============================================
typedef struct {
    char rua[100];
    char cidade[50];
    int numero;
} Endereco;

typedef struct {
    char nome[50];
    Endereco endereco;  // Struct dentro de struct
    int idade;
} Funcionario;

// ============================================
// EXEMPLO 4: STRUCT COM PONTEIROS
// ============================================
typedef struct {
    char *nome;         // Ponteiro para string (alocação dinâmica)
    int *notas;         // Ponteiro para array de inteiros
    int quantidade_notas;
} Aluno;

// ============================================
// EXEMPLO 5: STRUCT AUTO-REFERENCIADA (para Listas Ligadas)
// ============================================
typedef struct Node {
    int dado;
    struct Node *next;  // Ponteiro para o próximo node
} Node;

// ============================================
// FUNÇÃO: Demonstrar struct básica
// ============================================
void exemplo1_struct_basica(void) {
    printf("\n=== EXEMPLO 1: STRUCT BÁSICA ===\n");
    
    // Criar uma variável do tipo struct Pessoa
    struct Pessoa p1;
    
    // Atribuir valores usando o operador ponto (.)
    strcpy(p1.nome, "João Silva");
    p1.idade = 30;
    p1.altura = 1.75;
    
    // Acessar e imprimir os valores
    printf("Nome: %s\n", p1.nome);
    printf("Idade: %d\n", p1.idade);
    printf("Altura: %.2f\n", p1.altura);
    printf("Tamanho da struct: %lu bytes\n", sizeof(struct Pessoa));
}

// ============================================
// FUNÇÃO: Demonstrar typedef
// ============================================
void exemplo2_typedef(void) {
    printf("\n=== EXEMPLO 2: TYPEDEF ===\n");
    
    // Com typedef, não precisa escrever "struct" toda vez
    Ponto p1;
    p1.x = 10;
    p1.y = 20;
    
    printf("Ponto: (%d)\n", p1.x + p1.y);
    printf("Tamanho do Ponto: %lu bytes\n", sizeof(Ponto));
}

// ============================================
// FUNÇÃO: Demonstrar struct aninhada
// ============================================
void exemplo3_struct_aninhada(void) {
    printf("\n=== EXEMPLO 3: STRUCT ANINHADA ===\n");
    
    Funcionario f1;
    
    // Atribuir valores à struct principal
    strcpy(f1.nome, "Maria Santos");
    f1.idade = 28;
    
    // Atribuir valores à struct aninhada (endereco)
    strcpy(f1.endereco.rua, "Rua Principal");
    strcpy(f1.endereco.cidade, "São Paulo");
    f1.endereco.numero = 123;
    
    // Acessar valores usando múltiplos pontos
    printf("Funcionário: %s\n", f1.nome);
    printf("Idade: %d\n", f1.idade);
    printf("Endereço: %s, %d - %s\n", 
        f1.endereco.rua, 
        f1.endereco.numero, 
        f1.endereco.cidade);
}

// ============================================
// FUNÇÃO: Demonstrar ponteiro para struct
// ============================================
void exemplo4_ponteiro_struct(void) {
    printf("\n=== EXEMPLO 4: PONTEIRO PARA STRUCT ===\n");
    
    struct Pessoa p1;
    strcpy(p1.nome, "Carlos");
    p1.idade = 45;
    p1.altura = 1.80;
    
    // Criar um ponteiro para a struct
    struct Pessoa *ptr = &p1;
    
    // Acessar campos via ponteiro usando ->
    printf("Nome via ponteiro: %s\n", ptr->nome);
    printf("Idade via ponteiro: %d\n", ptr->idade);
    
    // Também pode usar (*ptr).campo
    printf("Altura via (*ptr): %.2f\n", (*ptr).altura);
    printf("Endereço de memória: %p\n", (void *)ptr);
}

// ============================================
// FUNÇÃO: Demonstrar struct com alocação dinâmica
// ============================================
void exemplo5_alocacao_dinamica(void) {
    printf("\n=== EXEMPLO 5: ALOCAÇÃO DINÂMICA ===\n");
    
    // Alocar memória dinamicamente para um Ponto
    Ponto *p_dinamico = (Ponto *)malloc(sizeof(Ponto));
    
    if (p_dinamico == NULL) {
        printf("Erro na alocação!\n");
        return;
    }
    
    // Atribuir valores usando ponteiro
    p_dinamico->x = 50;
    p_dinamico->y = 100;
    
    printf("Ponto dinâmico: (%d, %d)\n", p_dinamico->x, p_dinamico->y);
    printf("Endereço: %p\n", (void *)p_dinamico);
    
    // Liberar a memória alocada
    free(p_dinamico);
    p_dinamico = NULL;  // Boa prática: apontar para NULL após liberar
    printf("Memória liberada!\n");
}

// ============================================
// FUNÇÃO: Demonstrar array de structs
// ============================================
void exemplo6_array_de_structs(void) {
    printf("\n=== EXEMPLO 6: ARRAY DE STRUCTS ===\n");
    
    // Criar um array de 3 Pontos
    Ponto pontos[3];
    
    // Inicializar os pontos
    pontos[0].x = 1;
    pontos[0].y = 2;
    
    pontos[1].x = 3;
    pontos[1].y = 4;
    
    pontos[2].x = 5;
    pontos[2].y = 6;
    
    // Percorrer e imprimir
    printf("Pontos:\n");
    for (int i = 0; i < 3; i++) {
        printf("  Ponto %d: (%d, %d)\n", i + 1, pontos[i].x, pontos[i].y);
    }
}

// ============================================
// FUNÇÃO: Demonstrar ponteiro para array de structs
// ============================================
void exemplo7_ponteiro_array_structs(void) {
    printf("\n=== EXEMPLO 7: PONTEIRO PARA ARRAY DE STRUCTS ===\n");
    
    Ponto pontos[2] = {{10, 20}, {30, 40}};
    
    // Ponteiro para o primeiro elemento do array
    Ponto *ptr = pontos;
    
    // Acessar elementos via ponteiro e aritmética de ponteiros
    printf("Primeiro ponto via ponteiro: (%d, %d)\n", 
        ptr[0].x, ptr[0].y);
    
    printf("Segundo ponto via ponteiro: (%d, %d)\n", 
        ptr[1].x, ptr[1].y);
    
    // Incrementar ponteiro para acessar próximo elemento
    ptr++;
    printf("Ponto após incremento: (%d, %d)\n", ptr->x, ptr->y);
}

// ============================================
// FUNÇÃO: Passar struct como parâmetro (por valor)
// ============================================
void mover_ponto(Ponto p, int dx, int dy) {
    printf("Ponto original: (%d, %d)\n", p.x, p.y);
    p.x += dx;
    p.y += dy;
    printf("Ponto após mover: (%d, %d)\n", p.x, p.y);
    // Nota: Mudanças aqui NÃO afetam o original
}

// ============================================
// FUNÇÃO: Passar ponteiro para struct (por referência)
// ============================================
void mover_ponto_ptr(Ponto *p, int dx, int dy) {
    printf("Ponto original: (%d, %d)\n", p->x, p->y);
    p->x += dx;
    p->y += dy;
    printf("Ponto após mover: (%d, %d)\n", p->x, p->y);
    // Nota: Mudanças aqui AFETAM o original
}

// ============================================
// FUNÇÃO: Demonstrar passagem de structs em funções
// ============================================
void exemplo8_funcoes_com_structs(void) {
    printf("\n=== EXEMPLO 8: STRUCTS EM FUNÇÕES ===\n");
    
    Ponto p1 = {5, 10};
    
    printf("--- Passagem por VALOR ---\n");
    mover_ponto(p1, 2, 3);
    printf("Ponto original em main: (%d, %d)\n\n", p1.x, p1.y);
    
    printf("--- Passagem por REFERÊNCIA (ponteiro) ---\n");
    mover_ponto_ptr(&p1, 2, 3);
    printf("Ponto original em main: (%d, %d)\n", p1.x, p1.y);
}

// ============================================
// FUNÇÃO: Demonstrar lista ligada
// ============================================
void exemplo9_lista_ligada(void) {
    printf("\n=== EXEMPLO 9: LISTA LIGADA ===\n");
    
    // Criar 3 nodes
    Node n1, n2, n3;
    
    // Inicializar dados
    n1.dado = 10;
    n2.dado = 20;
    n3.dado = 30;
    
    // Conectar os nodes
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;  // Último node aponta para NULL
    
    // Percorrer a lista
    printf("Lista ligada:\n");
    Node *atual = &n1;
    while (atual != NULL) {
        printf("  Dado: %d\n", atual->dado);
        atual = atual->next;
    }
}

// ============================================
// FUNÇÃO PRINCIPAL
// ============================================
int main(void) {
    printf("========================================\n");
    printf("EXEMPLOS DE STRUCTS EM C\n");
    printf("========================================\n");
    
    exemplo1_struct_basica();
    exemplo2_typedef();
    exemplo3_struct_aninhada();
    exemplo4_ponteiro_struct();
    exemplo5_alocacao_dinamica();
    exemplo6_array_de_structs();
    exemplo7_ponteiro_array_structs();
    exemplo8_funcoes_com_structs();
    exemplo9_lista_ligada();
    
    printf("\n========================================\n");
    printf("FIM DOS EXEMPLOS\n");
    printf("========================================\n");
    
    return 0;
}