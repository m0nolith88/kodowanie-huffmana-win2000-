#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LIST 4

char symbols[LIST]={'A','B','C','D'};
int p[LIST]={1,2,3,4};

struct node{
    char symbol;
    int p;
    struct node *left;
    struct node *right;
};

struct heap{
    int p;
    struct node *left;
    struct node *right;
};

struct heap * buildHuffman();
int findSmallest(struct node *array[LIST],int num);
void list(struct node *array[LIST]);

struct heap * buildHuffman(){
    struct node *array[LIST]; int n=LIST; struct node *temp;
    int st,nd; struct node *temp2;
    for(int i=0; i<LIST; i++){
        array[i]=(struct node *) malloc(sizeof(struct node));
        array[i]->p=p[i];
        array[i]->symbol=symbols[i];
        array[i]->left=array[i]->right=NULL;
    }
    while(n>1){
        st=findSmallest(array,-1);
        temp=array[st];
        nd=findSmallest(array,st);
        temp2=array[nd];
        array[st]->p+=array[nd]->p;
        array[st]->symbol=127;
        array[st]->left=temp;
        array[st]->right=temp2;
        array[nd]->p=-1;
        --n;
    }

}

int findSmallest(struct node *array[LIST],int num){
    int smallest=INT_MAX; int sIndex;
    struct node * temp=(struct node *) malloc(sizeof(struct node));
    for(int i=0; i<LIST; i++){
        if(array[i]->p<smallest && array[i]->p!=-1 && i!=num){
            smallest=array[i]->p;
            sIndex=i;
        }
    }
    return sIndex;
};

void list(struct node *array[LIST]){
    for(int i=0; i<LIST; i++){
        if(array[i]!=NULL){
            printf("%c %d\n",array[i]->symbol,array[i]->p);
        }
    }
}

int main(int argc,char *argv[]){
    buildHuffman();
    return 0;
}
