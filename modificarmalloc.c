#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Aluno
{
    float nota1;
    float nota2;
    char nome[40];
    float media;
    int ativo;
};

int menu(void)
{
    int opcmenu;
    printf("\n1. Ver alunos cadastrados");
    printf("\n2. Aplicar bonus");
    printf("\n3. Excluir Aluno");
    printf("\n0. Sair");

    scanf("%d", &opcmenu);

    return opcmenu;
}

void consultar(struct Aluno *alunos, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (alunos[i].ativo == 1)
        {
            printf("\nNome: %s\n", alunos[i].nome);
            printf("\nMï¿½dia: %.2f\n", alunos[i].media);
        }
    }

    system("pause");
}

void bonus (struct Aluno *alunos, int n)
{
    int i, bonus, flag = 0, encontrado, qual;
    system("cls");

    for (i = 0; i < n; i++)
    {
        if (alunos[i].ativo == 1)
        {
            printf("\nAluno %d", i + 1);
            printf("\nNome: %s\n", alunos[i].nome);
            printf("\nNota 1: %.2f", alunos[i].nota1);
            printf("\nNota 2: %.2f", alunos[i].nota2);
            printf("\nMï¿½dia: %.2f\n", alunos[i].media);
        }
    }
    
    printf("Digite o número do aluno para aplicar o bônus:\n");
    scanf("%d", &bonus);

    encontrado = bonus - 1;


    for (i = 0; i < n; i++)
    {
        if (i == encontrado)
        {
            printf("\nAluno %d", i + 1);
            printf("\nNome: %s\n", alunos[i].nome);
            printf("\nNota 1: %.2f", alunos[i].nota1);
            printf("\nNota 2: %.2f", alunos[i].nota2);
            printf("\nMï¿½dia: %.2f\n", alunos[i].media);

            flag = 1;
        }
    }

    if (!flag)
    {
        printf("Aluno não encontrado. saindo...");
        return;
    }

    printf("Digite qual nota aplicar o bonus");
    scanf("%d", &qual);

    if (qual != 1 && qual != 2)
    {
        printf("\nOpção inválida!\n");
        system("pause");
        return;
    }

    if (qual == 1)
    {
        alunos[encontrado].nota1 += 2;
    }

    if (qual == 2)
    {
        alunos[encontrado].nota2 += 2;
    }

    alunos[encontrado].media = (alunos[encontrado].nota1 + alunos[encontrado].nota2)/2;
    printf("Bonus aplicado");

    system("pause");

}

void inativar(struct Aluno *alunos, int n)
{
    system("cls");
    int i, qual, excluir, flag;
    for (i = 0; i < n; i++)
    {
        if (alunos[i].ativo == 1)
        {
            printf("\nAluno %d", i + 1);
            printf("\nNome: %s\n", alunos[i].nome);
            printf("\nMï¿½dia: %.2f\n", alunos[i].media);
        }
    }

    printf("Qual aluno deseja excluir?");
    scanf("%d", &qual);
    excluir = qual - 1;

    if (excluir < 0 || excluir >= n || alunos[excluir].ativo == 0)
    {
        printf("Aluno invï¿½lido!\n");
        system("pause");
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (i == excluir)
        {
            alunos[i].ativo = 0;
        }
    }
    
    printf("Aluno inativado");
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i, n, flag = 0, opc;
    float busca;
    char nome[40];
    struct Aluno *alunos;

    printf("\nQuantos alunos quer armazenar?\n");
    scanf("%i", &n);

    alunos = (struct Aluno *) malloc(n * sizeof(struct Aluno));

    if (alunos == NULL) 
    {
        printf("Erro ao alocar memï¿½ria\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nDigite o nome do Aluno %d: \n", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        printf("\nDigite a n1 do Aluno %d: \n", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("\nDigite a n2 do Aluno %d: \n", i + 1);
        scanf("%f", &alunos[i].nota2);
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2)/2;
        alunos[i].ativo = 1;

    }

    do
    {
        opc = menu();

        switch(opc)
        {
            case 1:
            {
                consultar(alunos, n);
                break;
            }

            case 2:
            {
                bonus(alunos, n);
                break;
            }

            case 3:
            {
                inativar(alunos, n);
                break;
            }
        }
    } while(opc != 0);

    free(alunos);
    return 0;
}