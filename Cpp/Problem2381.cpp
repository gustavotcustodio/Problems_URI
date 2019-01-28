#include <stdio.h>
#include <string.h>

#define MAX_SIZE 21

// Imprime todos os nomes
void printNames(char nomes[][MAX_SIZE], int N)
{
    int i;
    printf("===============================================================\n");
    for (i = 0; i < N; i++)
    {
        printf("%s\n",nomes[i]);
    }
    
}

// Verifica se o nome1 vem antes do nome2 e retorna 1 caso sim
int primMenorSeg(char nome1[MAX_SIZE], char nome2[MAX_SIZE])
{
    int i = 0;
    
    do
    {
        if (nome1[i] < nome2[i])
            return 1;
        else if (nome1[i] > nome2[i])
            return 0;
        i++;
      
    // Continua até  que chegue no fim da palavra.     
    } while (i < MAX_SIZE && (nome2[i] != '\0'));
    
    return 0;
}

// Partição do quicksort
int partition (char nomes[][MAX_SIZE], int p, int r)
{
    int j;
    char pivot[MAX_SIZE];
    char aux[MAX_SIZE];
    
    strcpy ( pivot, nomes[r] );
    int i = p - 1;
    for (j = p; j < r; j++)
    {
        if (primMenorSeg (nomes[j], pivot) )
        {
            i++;
            strcpy (aux, nomes[i]);
            strcpy (nomes[i], nomes[j]); 
            strcpy (nomes[j], aux);
        }
    }
    strcpy (aux, nomes[i+1]);
    strcpy (nomes[i+1], nomes[r]);
    strcpy (nomes[r], aux);

    return i + 1; 
}

// Quicksort recursivo
void quickSortName (char nomes[][MAX_SIZE], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(nomes, p, r);
        quickSortName(nomes, p, q - 1);
        quickSortName(nomes, q + 1, r);
    }
    
}

int main()
{
    int N, K;
    
    scanf("%d", &N);
    scanf("%d", &K);
    
    char nomes[N][MAX_SIZE];
    int i;
    
    for (i = 0; i < N; i++)
    {
        scanf("%20s", nomes[i]);
    }
    
    quickSortName (nomes, 0, N-1);
    
    printf("%s\n", nomes[K-1]);
    
    return 0;
}



