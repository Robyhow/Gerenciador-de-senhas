#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SITES 100
#define MAX_LEN 50

// Estrutura para armazenar informações de senha
typedef struct {
    char site[MAX_LEN];
    char usuario[MAX_LEN];
    char senha[MAX_LEN];
} Senha;

// Função para adicionar uma senha
void adicionar_senha(Senha senhas[], int *quantidade) {
    if (*quantidade >= MAX_SITES) {
        printf("Limite de senhas atingido.\n");
        return;
    }

    Senha novaSenha;
    printf("Digite o site: ");
    scanf("%s", novaSenha.site);
    printf("Digite o usuário: ");
    scanf("%s", novaSenha.usuario);
    printf("Digite a senha: ");
    scanf("%s", novaSenha.senha);

    senhas[*quantidade] = novaSenha;
    (*quantidade)++;

    printf("Senha adicionada com sucesso.\n");
}

// Função para obter uma senha
void obter_senha(Senha senhas[], int quantidade, char *site) {
    int i;
    for (i = 0; i < quantidade; i++) {
        if (strcmp(senhas[i].site, site) == 0) {
            printf("Usuário: %s\n", senhas[i].usuario);
            printf("Senha: %s\n", senhas[i].senha);
            return;
        }
    }
    printf("Site não cadastrado.\n");
}

// Função principal
int main() {
    Senha senhas[MAX_SITES];
    int quantidade = 0;
    int opcao;
    char site[MAX_LEN];

    printf("Bem-vindo ao seu gerenciador de senhas!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Adicionar senha\n");
        printf("2. Obter senha\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_senha(senhas, &quantidade);
                break;
            case 2:
                printf("Digite o site: ");
                scanf("%s", site);
                obter_senha(senhas, quantidade, site);
                break;
            case 3:
                printf("Obrigado por usar o gerenciador de senhas. Até mais!\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
