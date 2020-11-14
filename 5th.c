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


int Determinant(int** Mat, int N){
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

int main(){
    int N;
    int** Matrix=malloc(N * sizeof(int*));
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        Matrix[i] = malloc(N * sizeof(int));
        for (int j = 0; j < N; j++)
            scanf("%d", &Matrix[i][j]);
    }

    printf("%d", Determinant(Matrix, N));

    return 0;
}