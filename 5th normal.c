#include <stdio.h>
#include <malloc.h>

//метод Гаусса

void diag_not_null(double** Mat, int N){
    double max = 0, tmp = 0;
    int k = 0;
    for (int i = 0; i < N; i++){
        k = i;
        max = Mat[i][i];
        for (int j = i + 1; j < N; j++)
            if (Mat[i][j] > max){
                max=Mat[i][j];
                k = j;
            }
        if(k!=i)
            for (int j = 0; j < N; j++){
                tmp = Mat[j][i];
                Mat[j][i] = Mat[j][k];
                Mat[j][k] = tmp;
            }
    }

}

void make_triangle(double** Mat, int N, double* b){
    double koeff = 0;
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++)
            if(Mat[j][i] != 0){
                koeff = Mat[j][i]/Mat[i][i];
                for (int k = 0; k < N; k++)
                    Mat[j][k] = Mat[j][k] - Mat[i][k]*koeff;
                b[j]=b[j]-b[i]*koeff;
            }
    }
}

void rezult(double** Mat, int N, double* b, double* x){
    for(int i = N-1; i>=0; i--){
        x[i] = b[i];
        for(int k = N-1; k > i; k--)
            x[i] -= Mat[i][k]*x[k];
        x[i] = x[i]/Mat[i][i];
    }
}

int main(){
    int N;
    scanf("%d", &N);
    double** Matrix = malloc(N * sizeof(double*));
    for (int i = 0; i < N; i++){
        Matrix[i] = malloc(N * sizeof(double));
        for (int j = 0; j < N; j++)
            scanf("%lf", &Matrix[i][j]);
    }
    double* b = malloc(N * sizeof(double));
    for (int i = 0; i < N; i++)
        scanf("%lf", &b[i]);
    //проверка на определитель
    diag_not_null(Matrix, N);
    make_triangle(Matrix, N, b);
    double* x = malloc(N * sizeof(double));
    rezult(Matrix, N, b, x);
    //for (int i = 0; i < N; i++){
    //    for (int j = 0; j < N; j++)
    //        printf("%lf ", Matrix[i][j]);
    //    printf("\n");
    //}
    for (int i = 0; i < N; i++){
        printf("%lf ", x[i]);
        printf("\n");
    }
    return(0);
}