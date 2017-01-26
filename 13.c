/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parseFileIntoStringArray(char *str, char delimiter);
const char* addTwoNumbers(char *num1, char *num2);

char s[100][51] = {'\0'};

int main()
{
    FILE *fp;
    char *sum = (char*)malloc(sizeof(char)*55);
    int k;
    for (k = 0 ; k < 55 ; k++){
        sum[k] = '0';
    }
    sum[54] = '\0';

    char filename[] = "C:\\Problem.txt";
    parseFileIntoStringArray(filename, '\n');
    //strcpy(sum, addTwoNumbers(s[0], s[1]));
    //printf("length of sum: %d\n", strlen(sum));
    int i;

    for (i = 0; i < 100; i++){
        strcpy(sum, addTwoNumbers(sum, s[i]));
    }
    printf("%s\n", sum);

    return 0;
}

const char* addTwoNumbers(char *num1, char *num2){
    char sum[55];
    int k;
    for (k = 0 ; k < 55 ; k++){
        sum[k] = '0';
    }
    sum[54] = '\0';

    int i = strlen(num1) - 2, j = strlen(num2) - 1;
    int carry = 0, digitSum, counter = 54;
    const int offset = '0';

    for (i;i>=0;i--,j--,counter--){
        digitSum = carry + num1[i] - '0';
        if (j >= 0)
            digitSum += num2[j]-'0';
        carry = digitSum / 10;
        digitSum %= 10;
        sum[counter] = digitSum + '0';
    }

    return sum;
}

int parseFileIntoStringArray(char *str, char delimiter){
    FILE *fp;
    char c;
    int i = 0, j = 0;

    fp = fopen(str, "r");
    if (fp == NULL)
        return 0;

    while ((c = fgetc(fp)) != EOF){
        if (c == delimiter){
            i++;
            j = 0;
            continue;
        }
        s[i][j++] = (char) c;
    }

    fclose(fp);
    return 1;
}