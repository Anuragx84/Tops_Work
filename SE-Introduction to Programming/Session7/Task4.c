/*4.Write code using nested loops to print a pattern of alternating 0s and 1s in a grid,
like the checkered background seen in some Spotify playlist covers (e.g., for a 4x4 grid, alternate 0 and 1 in each cell).*/
#include<stdio.h>
int main(){
    int i, j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if((i+j)%2==0)
                printf("0");
            else
                printf("1");
        }
        printf("\n");
    }
    return 0;
}

