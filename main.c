#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST 27

int frequency[]={5,9,12,13,16,45};
char characters[]={'a','b','c','d','e','f'};

struct node {
    char symbol;
    int probabylity;
    struct node *left;
    struct node *right;
};

void createHuffman();
int findSmallest(struct node *array[LIST],int num);

//Return smallest in array leaf index
int findSmallest(struct node *array[LIST],int num){
    int i; int smallest=array[0]; int sIndex;
    for(i=0; i<LIST; i++){
        if(array[i]->probabylity<smallest && array[i]->probabylity!=num){
            smallest=array[i]->probabylity;
            sIndex=i;
        }
    }
    return sIndex;
}

void createHuffman(){
    int i=0; int firstSmallest,sndSmallest; int n=6;
    struct node *array[LIST];
    //List creation
    for(i=0; i<LIST; i++){
        array[i]=(struct node *) malloc(sizeof(struct node));
        array[i]->left=array[i]->right=NULL;
        array[i]->probabylity=frequency[i];
        array[i]->symbol=characters[i];
    }
    while(n>1){
        firstSmallest=findSmallest(array,-1);
        sndSmallest=findSmallest(array,array[firstSmallest]->probabylity);
        struct node *tmp=array[firstSmallest];
        array[firstSmallest]=(struct node *) malloc(sizeof(struct node));
        array[firstSmallest]->probabylity=array[sndSmallest]->probabylity+tmp->probabylity;
        array[firstSmallest]->symbol='*';
        array[firstSmallest]->right=array[sndSmallest];
        array[firstSmallest]->left=tmp;
        array[sndSmallest]->probabylity=-1;
        n--;
        printf("%d\n",tmp->probabylity);
    }
    printf("%c\n",array[firstSmallest]->symbol);
}


int main()
{
    createHuffman();
//    struct node * smallest = find2smallest();
    //printf("Probability:%d Character:%c\n",array->probabylity,array->symbol);
    return 0;
}
