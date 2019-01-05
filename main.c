#include <stdio.h>
#include <stdlib.h>

/* Utilisation d'un algorithme glouton qui trie en evaluant
le rapport entre l'utilité et le poids */

void tri( int* , int* , int );

int main()
{
	int n, capacite_sac, *poids_obj, *utilite_obj;
	int i;

	printf("Entrez le nombre d'objets dont vous disposez: ");
	scanf("%d", &n);

	printf("\nEntrez la capacite de votre sac: ");
	scanf("%d", &capacite_sac);

    /*initialisation*/
	poids_obj = malloc(n*sizeof(int));
	utilite_obj = malloc(n*sizeof(int));

	printf("\nEntrez le poids de chaque objet:\n");
	for(i = 0; i < n; i++)
		scanf("%d", poids_obj+i);

	printf("\nEntrez l'utilite de chaque objet:\n");
	for(i = 0; i < n; i++)
		scanf("%d", utilite_obj+i);

	tri(poids_obj, utilite_obj, n);

	printf("\nEn tenant compte du tableau suivant:\n");

	printf("Numero  ");
	for(i = 0; i < n; i++)
	printf("%d   ",i+1);

	printf("\nPoids   ");
	for(i = 0; i < n; i++)
	printf("%d   ",poids_obj[i]);

	printf("\nUtilite ");
	for(i = 0; i < n; i++)
	printf("%d   ",utilite_obj[i]);

	int poids = 0;

	printf("\n\nLes objets a mettre dans votre sac sont: ");
    int j;
	for(i = 0; i < n; i++)
	{
	    j = i;
		poids += poids_obj[i];
		if(poids <= capacite_sac)
			printf("%d ", i+1);
		else
			break;
	}

	if(j==0)
        printf("les poids de tous vos objets surpassent  la capacite de votre sac");

	return 0;
}

//fait le tri par ordre décroissant en comparant le rapport utilite/poids
void tri( int *poids, int *utilite, int n)
{

	int i, j, temp, ind;
	float max;

	for( i = 0; i < n; i++ )
	{
		max = 0;
		for( j = i; j < n; j++ )
		{
			if( max < (float)utilite[j]/poids[j] )
				{
					max = (float)utilite[j]/poids[j];
					ind = j;
				}
		}
		temp = poids[ind];
		poids[ind] = poids[i];
		poids[i] = temp;

		temp = utilite[ind];
		utilite[ind] = utilite[i];
		utilite[i] = temp;

	}
}
