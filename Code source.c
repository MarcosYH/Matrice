#include<stdio.h>
#include<conio.h>
int main()
{
    int l,i,j,k,num;
    int taille=20;
    float A[taille][taille],L[taille][taille], U[taille][taille];
    float B[taille], X[taille],Y[taille];

debut:
    printf("\n\tResolution d_equation algebrique lineaire Ax = b par la methode de la factorisation LU.\n\n\n ");
    printf("1-Resoudre un systeme d_equation lineaire par decomposition LU. \n 2-Quitter\n\n\nVeuiller choisir une option entre 1 et 2 :");
    scanf("%d",&num);
    if(num==1)
    {
         system("cls");
//1) Lire les matrices A et b associées à (S).
        nbposi:
        printf("\nEntrez l'ordre de la matrice A associees au systeme: ");
        scanf("%d",&l);
        if(l<=0)
        {
            printf("\nEntrer un nombre positif svp ");
             goto nbposi;
        }

        printf("\nEntrez les elements de la matrice A.\n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
            {
                printf("lignes[%d] colonnes[%d] : ",i,j);
                scanf("%f",&A[i][j]);
            }
        }
        printf("\nEntrez les elements de la matrice B. \n");
        for(i=0; i<l; i++)
        {
            printf("lignes[%d] :",i);
            scanf("%f",&B[i]);
        }
        printf("\n");
//2) Affichons les matrices A et b associées à (S).
        printf("\n--Matrice A associees au systeme --\n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
            {
                printf("%9.2f",A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n--Matrice B associees au systeme --\n");
        for(i=0; i<l; i++)
        {
            printf("%9.2f",B[i]);
            printf("\n");
        }
//3) Affichons les matrices L et U de la factorisation de (A).

        for(int i = 1; i <=l ; i++)
        {
            if(A[i - 1][i - 1] == 0 && A[i][i - 1] > 0 )
            {
                float tmp;
                for(int e = 0; e <l; e++)
                {
                    tmp = A[i - 1][e];
                    A[i - 1][e] = A[i][e];
                    A[i][e] = tmp;
                }
                tmp = B[i - 1];
                B[i - 1] = B[i];
                B[i] = tmp;
            }

// Matrice L de la factorisation de (A)
            float pivot = A[i - 1][i - 1];

            if(i > 1)
            {
                for(int o = 0; o < i - 1; o++)
                {
                    L[o][i - 1] = 0;
                }
            }
            for(int o = i - 1; o < l; o++)
            {
                L[o][i - 1] = A[o][i - 1] / pivot ;

            }

            for(int e = i; e < l; e++)
            {
                float c = A[e][i - 1] / pivot;
                for(int p = 0; p < l; p++)
                   if(p == i - 1)
                        A[e][p] =  A[e][p] -  c * A[i - 1][p];
                    else
                        A[e][p] -= c * A[i - 1][p] ;

            }

        }
        printf("\n--Matrice U de la factorisation de (A)--\n");
        printf("Matrice U: \n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
                printf("%9.2f",A[i][j]);
            printf("\n");
        }
        printf("\n--Matrice L de la factorisation de (A)--\n");
        printf("Matrice L: \n");
        for(i=0; i<l; i++)
        {
            for(j=0; j<l; j++)
                printf("%9.2f",L[i][j]);
            printf("\n");
        }

        for(int i = 0; i < l; i++)
            Y[i] = B[i];

        for(int i = 1; i < l; i++)
        {
            for(int p = 0; p < i; p++)
                Y[i] -= L[i][p] *  Y[p];
        }

//afficher Y
/*printf("\n\n[Y]: \n");
    for(i=0; i<l; i++)
    {
        printf("%9.3f",Y[i]);
    }*/
//affficher X
        for(int i = 0; i < l; i++)
            X[i] = Y[i];

        for(int i = l - 1; i >= 0; i--)
        {
            for(int p = l - 1; p > i; p--)
                X[i] -= A[i][p] *  X[p];

            X[i] /= A[i][i];
        }


    //4) Affiche la solution [X] du système (S).
    printf("solution X du systeme  \n");
    printf("\n\nX: \n");
    for(i=0; i<l; i++)
    {
        printf("%9.2f",X[i]);
    }
    goto debut;
    }
    else if (num ==2) return 0;
    else
    {
        printf("Veuillez choisir entre 1 ou 2 svp");
        goto debut;
    }
    getch();

        return 0;
    }
