#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

union float_bits{
    float f;
    unsigned int bits;
};
typedef union float_bits float_bits;

struct float_decomposition{
    unsigned int sign;
    int exp;
    char mantissa[23];
};
typedef struct float_decomposition float_decomposition;

int get_exp(float_bits x){
    unsigned int ans = (x.bits >> 23) & 0xFF;
    return (ans == 0)? ans - 126 : ans - 127;
}

char* get_mantissa(float_bits x){
    char* ans = calloc(24, sizeof(char));
    ans[23] = '\0';
    for (int i=22; i>=0; i--){
        ans[i] = (x.bits & 1)? '1' : '0';
        x.bits >>= 1;
    }
    return ans;
}

unsigned int get_sign(float_bits x){
    return (x.bits >> 31);
}

void print_float_bits(float_bits x){
    char s[33]; s[32] = '\0';
    for (int i=31; i>=0; i--){
        s[i] = (x.bits & 1)? '1': '0';
        x.bits >>= 1;
    }
    printf("%s\n", s);
}

int print_float_bin_of_file(char* filepath){
    FILE* f = fopen(filepath, "r");
    if (f == NULL) return 1;
    char line[64] = "";
    while (fgets(line, 64,f)){
        float_bits x; x.f = (float) atof(line); 
        float_decomposition fd;
        fd.sign = get_sign(x);
        fd.exp = get_exp(x); 
        strcpy(fd.mantissa, get_mantissa(x));
        char ans[32] = "";
        if (fd.sign != 0) strcat(ans, "-");
        if (fd.exp == -126){
            char r[31];
            sprintf(r, "0.%s * 2^%d", fd.mantissa, fd.exp);
            strcat(ans, r);
        }
        else{
            char r[31];
            sprintf(r, "1.%s * 2^%d", fd.mantissa, fd.exp);
            strcat(ans, r);
        }
        printf("bin(%f) = %s\n", x.f, ans);
    }
    fclose(f);
}

int main(){
    print_float_bin_of_file("./floats/floating.1.in");
    return 0;
}

