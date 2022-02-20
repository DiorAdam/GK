#include <stdio.h>

#define MAXN 300

typedef struct matrix {
    size_t R, C;
    int index[MAXN][MAXN];
} matrix;



void product(matrix* A, matrix* B, matrix* C){
    if (A->C != B->R){
        C->C = 0; C->R = 0;
        return;
    }
    C->R = A->R; C->C = B->C;
    for (int i=0; i< C->R; i++){
        for (int j=0; j<C->C; j++){
            for (int k=0; k<A->C; k++){
                C->index[i][j] += A->index[i][k]*B->index[k][j];
            }
        }
    }
}


int main(){
    int ra, ca;
    scanf("%d %d", &ra, &ca);
    matrix A;
    A.R = ra, A.C = ca;
    for (int i=0; i<ra; i++){
        for (int j=0; j<ca; j++){
            scanf("%d", &A.index[i][j]);
        }
    }
    int rb, cb;
    scanf("%d %d", &rb, &cb);
    matrix B;
    B.R = rb, B.C = cb;
    for (int i=0; i<rb; i++){
        for (int j=0; j<cb; j++){
            scanf("%d", &B.index[i][j]);
        }
    }
    matrix C;
    product(&A, &B, &C);
    printf("%d %d\n", (int) C.R, (int) C.C);
    for (int i=0;i<C.R; i++){
        for (int j=0; j<C.C-1; j++){
            printf("%d ", C.index[i][j]);
        }
        printf("%d\n", C.index[i][C.C-1]);
    }
    return 0;
}
