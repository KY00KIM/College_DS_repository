#include <stdio.h>
#include <stdlib.h>

int checkDone(int* mst);
int findMin(int * val);
int minLink(int (*link)[10], int* mst);
int emptyIdx(int (*res)[2]);

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
        {0, 0, 0, 0, 18, 10, 3, 0, 4, 0}};
    int mst[10]={0}; //if 0 mst
    int res[9][2]={0}; //result LINKS
    int resMat[9][9] = {0}; // result in Matrix
    
    for(int i =1 ; i<10 ; i++){
        mst[i] = 1;
    }
        
    while(!checkDone(mst)){
        int LINK = minLink(link, mst);
        int idx = emptyIdx(res);
        res[idx][1] = LINK%10;
        res[idx][0] = LINK/10;
        mst[res[idx][0]] = 0;
    }
    
    for(int i = 0 ; i< 9 ; i++){
        resMat[res[i][0]][res[i][1]]=1;
        resMat[res[i][1]][res[i][0]]=1;
    }
    printf("RESULT(LINKS) IN MATRIX: \n");
    for(int i =0 ; i< 9 ;i++){
        for(int j = 0 ; j<9 ; j++)
            printf("%d ", resMat[i][j]);
        printf("\n");
    }
    /*
    for(int i = 0 ; i< 9 ; i++){
        printf("LINK %d : ", i+1);
            printf("%d - %d", res[i][0]+1, res[i][1]+1);
            printf("\n");
    }
    */
    return 0;
}

int checkDone(int* mst){
    for(int i = 0 ; i< 10 ; i++)
        if(mst[i] == 1) return 0;
    
    return 1; //DONE
}


int findMin(int * val){
    int min = val[0];
    for(int i = 0 ; i< 10 ; i++){
        if(val>0)
            if(min>val[i])
                min = val[i];
    }
    return min;
}

int minLink(int (*link)[10], int* mst){
    int minlink = 0;
    int weight = 30;
    
    for(int i = 0 ; i<10 ; i++){ //i MST
        if(mst[i] == 1) continue;
        for(int j =0 ; j<10 ; j++){ //j newLink
            if(link[j][i] && mst[j] != 0) //link exists + NOT MST
                if(weight > link[j][i]){
                    minlink = j*10 +i;
                    weight = link[j][i];
                }
        }
    }
    return minlink;
}


int emptyIdx(int (*res)[2]){
    for(int i = 0 ; i< 9 ; i++)
        if(res[i][0] == 0 &&  res[i][1] == 0)
            return i;
    return -1;
}
