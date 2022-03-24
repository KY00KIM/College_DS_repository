#include <stdio.h>
#include <stdlib.h>

void findShortPath(int (*link)[10], int(*res)[10]);
void printMatrix(int(*input)[10]);
int searchKey(int(*input)[2], int key, int end);


int main() {
    
    int link[10][10] = {
    {0, 6, 3, 0, 9, 0, 0, 0, 0, 0},
    {6, 0, 4, 2, 0, 0, 0, 9, 0, 0},
    {3, 4, 0, 2, 9, 9, 0, 0, 0, 0},
    {0, 2, 2, 0, 0, 8, 0, 9, 0, 0},
    {9, 0, 9, 0, 0, 8, 0, 0, 0, 18},
    {0, 0, 9, 8, 8, 0, 9, 7, 0, 10},
    {0, 0, 0, 0, 0, 9, 0, 5, 1, 3},
    {0, 9, 0, 9, 0, 7, 5, 0, 4, 0},
    {0, 0, 0, 0, 0, 0, 1, 4, 0, 4},
    {0, 0, 0, 0, 18,10, 3, 0, 4, 0}
    };
    
    int result[10][10]={0};
    
    findShortPath(link, result);
    
    printf("RESULT(LINKS):\n");
    printMatrix(result);
    
    return 0;
}


void findShortPath(int (*link)[10], int(*res)[10]){
    int spt[10][2]={0};
    
    for(int i = 1 ; i<10 ; i++){
        int minLen = 99999;
        int minVer = 0;
        int preVer = 0;
        //EACH VERTEX IN SPT
        for(int j =0 ; j<=i ; j++)
            //SEARCH ALL VERTEICES
            for(int k=0; k <10 ; k++)
                //if ADJACENT
                if(link[spt[j][0]][k])
                    //PREVENT DUPLICATE
                    if(!searchKey(spt,k,i-1))
                        //if FOUND SHORTER
                        if(minLen>(link[spt[j][0]][k]+spt[j][1])){
                            //SWAP
                            minLen = link[spt[j][0]][k]+spt[j][1];
                            minVer = k;
                            preVer = spt[j][0];
                        }
        spt[i][0]=minVer;
        spt[i][1]=minLen;
        res[preVer][minVer]=1;
        res[minVer][preVer]=1;
    }
}

int searchKey(int(*input)[2], int key, int end){
    if(end<0)return 0;
    for(int i = 0 ; i<=end ; i++)
        if(key == input[i][0])
            return 1;
    return 0;
}


void printMatrix(int(*input)[10]){
    for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++)
            printf("%d ", input[i][j]);
        printf("\n");
    }
}
