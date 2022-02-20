#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_SIZE 10000


size_t get_text(char* filepath, char* array){
    FILE* f = fopen(filepath, "r");
    size_t length = 0;
    while (fread(array + length, 1, 1, f)) length++;
    array[length+1] = '\0';
    return length;
}

void cipher(char* array, int l, int r){
    if (r-l <=2) return;
    int m = (r-l)/2;
    int swapl = m/2, swapr = (r-l-m)/2;
    for (int i=0; i<swapl; i++){
        char x = array[l+m-1-i];
        array[l+m-1-i] = array[l+i];
        array[l+i] = x;
    }

    for (int i=0; i<swapr; i++){
        char x = array[r-1-i];
        array[r-1-i] = array[l+m+i];
        array[l+m+i] = x;
    }
    printf("l=%d,r=%d,m=%d,m/2=%d\n%s\n\n",l, r, m, m/2, array);
    cipher(array, l, l+m);
    cipher(array, l+m, r);
}


void write_cipher(int n, char* filepath, char* array){
    FILE* f = fopen(filepath, "w");
    fwrite(array, sizeof(char), n-2, f);
    fclose(f);
}


int main(int argc, char* argv[]){
    char inpath[64] = "./inout/";
    strcat(inpath, argv[1]);
    strcat(inpath, ".txt");

    char* array = (char*) malloc(MAX_TEXT_SIZE);
    size_t n = get_text(inpath, array);

    printf("%s\n\n", array);
    cipher(array, 0, (int) n);
    printf("%s\n\n", array);

    char outpath[64] = "./inout/";
    strcat(outpath, argv[1]);
    strcat(outpath, "_cipher.txt");
    
    write_cipher(n, outpath, array);

    free(array);
    return 0;
}

