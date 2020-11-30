#include <stdio.h>
#include <malloc.h>



int** GetMinorMatr(int **Mat, int l, int N) {
    int** MinorMat=malloc((N - 1) * sizeof(int*));
    for (int i = 0; i < N - 1; i++)
        MinorMat[i] = malloc((N - 1) * sizeof(int));
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1; j++)
            if(j<l)
                MinorMat[i][j] = Mat[i+1][j];
            else
                MinorMat[i][j] = Mat[i+1][j+1];
    return(MinorMat);
}

double Determinant(int** Mat, int N){
    int det = 0, k = 1;
    if (N == 1)
        return Mat[0][0];
    else
    {
        for (int i = 0; i < N; i++) {
            int** Minor = GetMinorMatr(Mat, i, N);
            det = det +  k * Mat[0][i] * Determinant(Minor, N-1);
            k = -k;
        }
        return(det);
    }
}

int** delit(int** Mat, int str, int stl, int N){
    int** NewMat=malloc((N - 1) * sizeof(int*));
    for (int i = 0; i < N - 1; i++)
        NewMat[i] = malloc((N - 1) * sizeof(int));
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-1; j++){
            if (i < str){
                if (j < stl)
                    NewMat[i][j] = Mat[i][j];
                else
                    NewMat[i][j] = Mat[i][j+1];
            }
            else{
                if (j < stl)
                    NewMat[i][j] = Mat[i+1][j];
                else
                    NewMat[i][j] = Mat[i+1][j+1];
            }

        }
    }
    return (NewMat);
}

void GetObratMatr(int **Mat, int N, double opred) {
    double x;
    int k = 1;
    int** TranspMat=malloc((N) * sizeof(int*));
    for (int i = 0; i < N; i++)
        TranspMat[i] = malloc((N) * sizeof(int));

    int** AlgMat=malloc((N) * sizeof(int*));
    for (int i = 0; i < N; i++)
        AlgMat[i] = malloc((N) * sizeof(int));


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            TranspMat[i][j] = Mat[j][i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            AlgMat[i][j] = Determinant(delit(TranspMat, i, j, N), N-1);
            if( (i+j) % 2)
                AlgMat[i][j] = (-1) * AlgMat[i][j];
        }

    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            x = AlgMat[i][j] / opred;
            printf("%f ", x);
        }

        printf("\n");
    }
}



int main() {
    int N;
    scanf("%d", &N);
    int **Matrix = malloc(N * sizeof(int *));

    for (int i = 0; i < N; i++) {
        Matrix[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            scanf("%d", &Matrix[i][j]);
    }

    double Opred = Determinant(Matrix, N);
    if (!Opred)
        printf("Обратной матрицы не существует");

    else
        GetObratMatr(Matrix, N, Opred);

    return 0;
}