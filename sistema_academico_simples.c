/*Código que cadastra alunos em um sistema, junto de suas notas e media.*/

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"

typedef struct notas
{
	double n1;
	double n2;
	double n3;
} Notas;

typedef struct aluno
{
	char nome[20];
	char cidade[20];
	Notas notas;
	double media;
} Aluno;

Aluno alunos[5];

int cadastrar()
{
	Aluno aluno;
	int indice;

	printf("Em qual indice desea adicionar o novo(a) aluno(a)? [0-4] ");
	scanf("%d", &indice);
	if (indice < 0 || indice > 4)
	{
		printf("Indice invalido\n");
		return 1;
	}

	printf("Qual o nome do aluno? ");
	getchar();
	fgets(aluno.nome, 20, stdin);

	printf("Qual a cidade de residencia do aluno(a)? ");
	fgets(aluno.cidade, 20, stdin);

	printf("Quais sao as tres notas do aluno(a)? ");
	scanf("%lf %lf %lf", &aluno.notas.n1, &aluno.notas.n2, &aluno.notas.n3);

	aluno.media = cbrt(aluno.notas.n1 * aluno.notas.n2 * aluno.notas.n3);

	alunos[indice] = aluno;
	return 0;
}

void visualizar()
{
	int indice;

	for (indice = 0; indice < 5; indice++)
	{
		printf("+---------------------------------+\n");
		printf("| Aluno %d                        |\n", indice);
		printf("+---------------------------------+\n");
		printf("Nome: %s\n", alunos[indice].nome);
		printf("Cidade: %s\n", alunos[indice].cidade);
		printf("N1: %.2lf \t N2: %.2lf \t N3: %.2lf  \n", alunos[indice].notas.n1, alunos[indice].notas.n2, alunos[indice].notas.n3);
		printf("Media: %.2lf\n\n", alunos[indice].media);
	}
}

int atualizar()
{
	Aluno aluno;

	int indice;
	printf("Em qual indice deseja alterar as notas do(a) aluno(a)? [0-4] ");
	scanf("%d", &indice);
	if (indice < 0 || indice > 4)
	{
		printf("Indice invalido\n");
		return 1;
	}

	if (strcmp(alunos[indice].nome, "") != 0)
	{
		// Aluno não nulo
		printf("Quais sao as tres novas notas do(a) aluno(a) %s?", alunos[indice].nome);
		scanf("%lf %lf %lf", &aluno.notas.n1, &aluno.notas.n2, &aluno.notas.n3);
		strcpy(aluno.nome, alunos[indice].nome);
		strcpy(aluno.cidade, alunos[indice].cidade);
		aluno.media = cbrt(aluno.notas.n1 * aluno.notas.n2 * aluno.notas.n3);

		alunos[indice] = aluno;
		return 0;
	}
	else
	{
		// Aluno nulo
		printf("Aluno vazio. Nao ha como alterar notas\n");
		return 1;
	}
}

void aprovados()
{
	int indice;

	printf("+------------------------+\n");
	printf("| Aprovados              |\n");
	printf("+------------------------+\n");

	for (indice = 0; indice < 5; indice++)
	{
		if (alunos[indice].media >= 6)
		{
			printf("Indice: %d\n", indice);
			printf("Nome: %s", alunos[indice].nome);
			printf("N1: %.2lf \t N2: %.2lf \t N3: %.2lf\n", alunos[indice].notas.n1, alunos[indice].notas.n2, alunos[indice].notas.n3);
			printf("Media: %.2lf\n", alunos[indice].media);
			printf("+------------------------+\n");
		}
	}
}

void reprovados()
{
	int indice;

	printf("+-------------------------+\n");
	printf("| Reprovados              |\n");
	printf("+-------------------------+\n");

	for (indice = 0; indice < 5; indice++)
	{
		if (strcmp(alunos[indice].nome, "") != 0)
		{
			if (alunos[indice].media < 6)
			{
				printf("Indice: %d\n", indice);
				printf("Nome: %s", alunos[indice].nome);
				printf("N1: %.2lf \t N2: %.2lf \t N3: %.2lf\n", alunos[indice].notas.n1, alunos[indice].notas.n2, alunos[indice].notas.n3);
				printf("Media: %.2lf\n", alunos[indice].media);
				printf("+------------------------+\n");
			}
		}
	}
}

int main()
{
	unsigned short int opcao = -1;

	while (opcao != 0)
	{
		printf("+------------------------------+\n");
		printf("|            ESCOLAR           |\n");
		printf("+------------------------------+\n");
		printf("| %-28s |\n", "1 - Cadastrar aluno");
		printf("| %-28s |\n", "2 - Visualizar geral");
		printf("| %-28s |\n", "3 - Atualizar notas de aluno");
		printf("| %-28s |\n", "4 - Listar aprovados");
		printf("| %-28s |\n", "5 - Listar reprovados");
		printf("| %-28s |\n", "0 - Sair");
		printf("+------------------------------+\n");
		printf("O que deseja fazer? ");
		scanf_s("%hu", &opcao);

		switch (opcao)
		{
		case 1:
		{
			/* Implementa o cadastro de aluno */
			cadastrar();
			break;
		}
		case 2:
		{
			visualizar();
			break;
		}
		case 3:
		{
			atualizar();
			break;
		}
		case 4:
		{
			aprovados();
			break;
		}
		case 5:
		{
			reprovados();
			break;
		}
		case 0:
		{
			/* Sair */
			break;
		}
		default:
			break;
		}
	}
}
