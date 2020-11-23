/*
 * Nome, numero de aluno, e turno pratico dos elementos do grupo:
 * Aluno 1: Cláudio Redondo, a45856 , PL-4
 * Aluno 2: Tiago Pinto, z584, PL-4
 */

#include <stdio.h>
#define N 3

void inicializaGrelha(char grid[N][N])
{
    int x, y;

    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
        {
            grid[x][y] = ' ';
        }
    }
}

void imprimeGrelha(char grid[N][N])
{
    int x, y;

    for (x = 0; x < N; x++)
    {
        for (y = 0; y < N; y++)
        {
            if (y != (N - 1))
            {
                printf(" %c ", grid[x][y]); //  Substitui por "0" ou "X"
            }
            else
            {
                printf(" %c ", grid[x][y]); //  Substitui por "0" ou "X"
            }
            if (y != (N - 1))
            {
                printf("|"); //  Divisões verticais da grelha
            }
        }
        printf("\n");
        if (x != (N - 1))
        {
            printf("--- --- --- \n"); //  Divisões horizontais da grelha
        }
    }
}

int jogada(char grid[N][N], int x, int y, int jogador)
{

    if (x >= 0 && x <= 2 && y >= 0 && y <= 2) //  Coordenadas da posição possivéis
    {
        if (grid[x][y] == 'X' && grid[x][y] == '0') //  Posição preenchida com X ou 0
        {
            //  Valor de incompatibilidade de relizar a jogada por estar a posição preenchida
            return 2;
        }
        else
        {
            //  Valor de compatibilidade de realizar a jogada por a posição estar vazia
            return 0;   
        }
    }
    else
    {
        return 1; //  Valor de incompatibilidade de relizar a jogada por esta posição não existir
    }
}

int tresEmLinha(char grid[N][N], int x, int y)
{
    int jogador = 0;

    //  Formas possiveis de vitória, seja para jogador0 (0) ou jogador1 (X)
    if (jogada(grid, x, y, jogador) == 0)
    {
        //  Posição vazia
        if (grid[x][y] != '0' && grid[x][y] != 'X')
        {
            return -1;
        }
        //  Verificação de linhas
        for (int x = 0; x < N; x++)
        {
            if ((grid[x][0] == '0' && grid[x][1] == '0' && grid[x][2] == '0') || (grid[x][0] == 'X' && grid[x][1] == 'X' && grid[x][2] == 'X'))
            {
                return 1;
            }
        }
        //  Verificação de colunas
        for (int y = 0; y < N; y++)
        {
            if ((grid[0][y] == '0' && grid[1][y] == '0' && grid[2][y] == '0') || (grid[0][y] == 'X' && grid[1][y] == 'X' && grid[2][y] == 'X'))
            {
                return 1;
            }
        }
        //  Verificação de diagonal da esquerda para a direita
        if ((grid[0][0] == '0' && grid[1][1] == '0' && grid[2][2] == '0') || (grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X'))
        {
            return 1;
        }
        //  Verificação de diagonal da direita para a esquerda
        if ((grid[2][0] == '0' && grid[1][1] == '0' && grid[0][2] == '0') || (grid[2][0] == 'X' && grid[1][1] == 'X' && grid[0][2] == 'X'))
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }

    return 0;
}

int main(void)
{
    int x, y, jogador = 0, ronda = 1;
    char grid[N][N], nome0[50], nome1[50];

    printf("\tJOGO DO GALO\n");
    printf("Bem vindos jogadores!\n");
    printf("Jogador 0 insira o seu nome --> ");
    scanf("%s", nome0); //  Input do nome do jogador0

    printf("Jogador 1 insira o seu nome --> ");
    scanf("%s", nome1); // Input do nome do jogador1

    printf("\nEntão vamos começar o jogo!\n");

    inicializaGrelha(grid);
    imprimeGrelha(grid);

    while (tresEmLinha(grid, x, y) != 1 && ronda <= 9) //  Loop para a função só parar quando resultdo obter um valor diferente de 1 e/ou ronda = 9
    {

        printf("\n\tRonda %d\n", ronda);

        if (ronda % 2 != 0)
        {
            printf("\nJogador 0, %s é a sua vez de realizar a jogada.\n", nome0);
        }
        else
        {
            printf("\nJogador 1, %s é a sua vez de realizar a jogada.\n", nome1);
        }

        printf("Indique a linha em que quer realizar a sua jogada --> ");
        scanf("%d", &x); //  Input da linha que pretende realizar a jogada

        printf("Indique a coluna em que quer realizar a sua jogada --> ");
        scanf("%d", &y); //  Input da coluna que pretende realizar a jogada

        if (jogada(grid, x, y, jogador) == 0)
        {
            printf("\nA sua jogada foi registada.\n\n");

            if (ronda % 2 != 0)
            {
                grid[x][y] = '0'; //  Simbolo de jogador0
            }
            else
            {
                grid[x][y] = 'X'; // Simbolo de jogador1
            }

            ronda++;
            imprimeGrelha(grid);
        }
        else
        {
            if (jogada(grid, x, y, jogador) == 2)
            {
                printf("\nCoordenadas de posição já ocupada.\n\n");
                imprimeGrelha(grid);
            }
            if (jogada(grid, x, y, jogador) == 1)
            {
                printf("\nCoordenadas de posição inválida.\n\n");
                imprimeGrelha(grid);
            }
        }
    }

    if (tresEmLinha(grid, x, y) == 1) //  Análise do resultado obtida na função tresEmLinha no caso de vitória de algum jogador
    {
        if (ronda % 2 != 0)
        {

            printf("\n\tFIM DO JOGO\n");
            imprimeGrelha(grid);
            printf("\nParabéns jogador 1, %s ganhaste o jogo!\n", nome1);
            return 0;
        }
        else
        {
            printf("\n\tFIM DO JOGO\n");
            imprimeGrelha(grid);
            printf("\nParabéns jogador 0, %s ganhaste o jogo!\n", nome0);
            return 0;
        }
    }
    if (tresEmLinha(grid, x, y) == 0 && ronda > 9) //  Análise da variável "resultado" obtida na função tresEmLinha no caso de empate
    {
        printf("\n\tFIM DO JOGO\n");
        imprimeGrelha(grid);
        printf("\nO jogo ficou empatado!\n");
        return 0;
    }

    return 0;
}
//  Compilar o código com gcc -o a45856_z584 a45856_z584.c -Wall -std=c99
//  ./a45856_z584