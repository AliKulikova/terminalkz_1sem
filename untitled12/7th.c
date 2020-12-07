#include <stdio.h>
#include <math.h>

double step (double x, int s){
    double result = 1;
    while (s){
        result *= x;
        s--;
    }
    return result;
}

int main() {
    int n;
    double a, b, a_1, b_1, r, cs, sn, fi;

    printf("a = ");
    scanf("%lf", &a);
    printf("\nb = ");
    scanf("%lf", &b);
    printf("\nn = ");
    scanf("%d", &n);

    r = a*a + b*b;
    a_1 = a / r;
    b_1 = - (b / r);

    printf("\n z^(-1) = %0.5f + %0.5f i\n", a_1, b_1);

    r = sqrt(r);
    cs = a / r;
    fi = acos(cs);

    cs = cos(fi * n);
    sn = sin(fi * n);

    r = step(r, n);

    a_1 = r * cs;
    b_1 = r * sn;

    printf("\n z^n = %0.5f + %0.5f i\n", a_1, b_1);

    int k = n - 1;

    while (k + 1){
        cs = cos((fi + 6,28 * k)/n );
        sn = sin (fi / n);
        r = sqrt(r);
        r = pow(r, 1/n);
        a_1 = cs * r;
        b_1 = sn * r;
        printf("\n z_%d = %0.5f + %0.5f i\n", n-k, a_1, b_1);
        k--;
    }


    return 0;
}
