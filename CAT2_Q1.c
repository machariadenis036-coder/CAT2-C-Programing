/*
Name:Denis Macharia
Reg No:CT100/G/26250/25
Scores
*/

#include <stdio.h>

int main() {
    int scores[2][2] = {
        {65, 92},
        {84, 72}
    };

    printf("Elements of the array:\n");
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", scores[i][j]);
        }
        printf("\n");  // move to next row
    }
}