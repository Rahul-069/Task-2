#include<stdio.h>

#define MR 10
#define MC 10

void trans(int arr[MR][MC],int rows,int cols){
  int i,j;
  int trans[10][10];
  for(i=0;i<rows;++i){
    for(j=0;j<cols;++j){
      trans[j][i]=arr[i][j];
    }
  }

  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      printf("%d ",trans[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int arr[MR][MC];

  FILE* fp = fopen("mat.txt", "r");
  int rows=3;
  int cols=3;
  int i,j;

  for(i=0;i<rows;i++){
    for(j=0;j<cols;j++){
      fscanf(fp, "%d", &arr[i][j]);
    }
  }

printf("Original Matrix : \n");
for(i=0;i<rows;i++){
  for(j=0;j<cols;j++){
    printf("%d ",arr[i][j]);
  }
  printf("\n");
}

printf("\n");

printf("Transpose Matrix : \n");
trans(arr,rows,cols);

  return 0;
}
