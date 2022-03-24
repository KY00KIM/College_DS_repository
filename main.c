#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackADT.h"


int main() {
  
    
    Stack* Stack1 = CreateStack();
    Stack* Stack2 = CreateStack();
    int input;

    printf("Input Stack1's element : -1 to break: ");
    while(1){
        scanf("%d", &input);
        if(input == -1)break;
        Push(Stack1, input);
    }
    PrintStack(Stack1);
    
    
    printf("Input Stack2's element : -1 to break: ");
    while(1){
        scanf("%d", &input);
        if(input == -1)break;
        Push(Stack2, input);
    }
    PrintStack(Stack2);

    
    printf("CAT STACK IS\n");
    Stack* catStack = CatStack(Stack1, Stack2);
    PrintStack(catStack);

    return 0;
}

