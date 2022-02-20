#include <stdio.h>
#include <stdlib.h>

typedef struct heap_matrix{
    size_t R, C;
    int** index;
} matrix;

matrix* alloc_matrix(int R, int C){
    matrix* A = (matrix*) malloc(sizeof(matrix));
    A->R = (size_t) R; A->C = (size_t) C;
    A->index = (int**) calloc(R, sizeof(int*));
    for (int i=0; i<R; i++){
        A->index[i] = calloc(C, sizeof(int));
    }
    return A;
}

void free_matrix(matrix* A){
    for(int i=0; i< (int) A->R; i++){
        free(A->index[i]);
    }
    free(A->index);
    free(A);
}


void product(matrix* A, matrix* B, matrix* C){
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
    matrix* A = alloc_matrix(ra, ca);
    for (int i=0; i<ra; i++){
        for (int j=0; j<ca; j++){
            scanf("%d", &A->index[i][j]);
        }
    }
    int rb, cb;
    scanf("%d %d", &rb, &cb);
    matrix* B = alloc_matrix(rb, cb);
    for (int i=0; i<rb; i++){
        for (int j=0; j<cb; j++){
            scanf("%d", &B->index[i][j]);
        }
    }
    matrix* C = (A->C == B->R)? alloc_matrix(A->R, B->C): alloc_matrix(0, 0) ;
    product(A, B, C);
    printf("%d %d\n", (int) C->R, (int) C->C);
    for (int i=0;i<C->R; i++){
        for (int j=0; j<C->C-1; j++){
            printf("%d ", C->index[i][j]);
        }
        printf("%d\n", C->index[i][C->C-1]);
    }
    free_matrix(A), 
    free_matrix(B), 
    free_matrix(C);
    return 0;
}
