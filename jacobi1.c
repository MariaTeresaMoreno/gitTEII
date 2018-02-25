#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define N 400
#define TOL 0.005

typedef float Configuracion[5];         /* Valores de temperatura por defecto */

float **A,**B;              /* Matrices */

void show (void)            /* Vuelca el contenido de la matriz por pantalla */
{
    int i,j;
    
    for (i = 0; i < N + 2; ++i)
    {
        for (j = 0; j < N + 2; ++j)
        {
            printf ("%4.2f ", A[i][j]);
        }
        printf ("\n");
    }
}

void initialize (Configuracion confAct)     /* inicializa las estructura del programa */
{
    int i,j;

    A = (float**) malloc (sizeof(float*)*(N+2));
    for (i=0;i<N+2;i++)
        A[i] = (float*) malloc(sizeof(float)*(N+2));
    B = (float**) malloc (sizeof(float*)*(N+2));
    for (i=0;i<N+2;i++)
        B[i] = (float*) malloc(sizeof(float)*(N+2));
    
    /* Anotamos la temperatura del cuerpo */
    for (i=0;i<=N+1;i++)
        for (j=0;j<=N+1;j++) {
            A[i][j] = confAct[4];
            B[i][j] = confAct[4];
        }

    /* Anotamos la temperatura de los bordes */
    for (j=1;j<=N;j++) {
        A[0][j] = confAct[0];
        B[0][j] = confAct[0];
    }

    for (j=1;j<=N;j++) {
        A[N+1][j] = confAct[2];
        B[N+1][j] = confAct[2];
    }


    for (i=0;i<N+2;i++) {
        A[i][0] = confAct[1];
        A[i][N+1] = confAct[3];
        B[i][0] = confAct[1];
        B[i][N+1] = confAct[3];
    }
}

void solve (void)           /* Procedimiento de resolución */
{
    int i,j;
    int numIterations;      /* Numero de iteraciones */
    float diff;         /* Diferencia actual */
    char convergencia = 0;

    numIterations = 0;

    while (!convergencia) {
        numIterations++;
        /* Actualizamos los valores de temperatura */
        for (j = 1; j <= N; j++) {
            for (i = 1; i <= N; i++) {
                B[i][j] = 0.2*(A[i][j]+A[i-1][j]+A[i+1][j]+A[i][j-1]+A[i][j+1]);
            }
        }

        /* Implementación del test de convergencia */
        diff = 0.0;
        for (j = 1; j <= N; j++) {
            for (i = 1; i <= N; i++) {
                if ( (fabs(B[i][j] - A[i][j])) > diff )
                    diff = fabs(B[i][j] - A[i][j]);
            }
        }
        convergencia = (diff <= TOL);
        if (!convergencia) {
            /* Copiamos lo calculado en B en la matriz A para la siguiente iteración */
            for (j = 1; j <= N; j++) {
                for (i = 1; i <= N; i++) {
                    A[i][j] = B[i][j];
                }
            }
        }
    }
    printf("Número de iteraciones en el procedimiento Solve: %d -- Diferencia: %4.4f\n",numIterations, diff);
}

int main(int argc, char** argv)
{
    int i;
    Configuracion confActual;

    confActual[0] = 150.0;
    confActual[1] = 70.0;
    confActual[2] = 150.0;
    confActual[3] = 70.0;
    confActual[4] = 10.0;

    initialize(confActual);

    solve();

    show();

    for (i=0;i<(N+2);i++)
        free(A[i]);
    free(A);

    for (i=0;i<(N+2);i++)
        free(B[i]);
    free(B);

    return 0;
}
