#include <stdio.h>
#include <stdlib.h>

int rectangle();
int triangle();

int main(void){
  int option, active=1;

  while(active==1){
    printf("Enter 1(rectangle), 2(triangle), 3(other), 0(quit): ");
    scanf(" %d", &option);
    if(option==1){
      rectangle();
    }else if(option==2){
      triangle();
    }else if(option==0){
      active=0;
    }else{
      printf("Invalid choice.\n");
    }
  }
      printf("Bye Bye.\n");
      return 1;
}


int rectangle(){

    char symbol;
    int i,j,length,width; /*width=rows,length=columns*/

    printf("Enter character, width and length: ");
    scanf(" %c %d %d", &symbol, &width, &length);

    if(symbol!='*' && symbol!='#' && symbol!='%'){
      printf("Invalid data provided.\n");
      return 0;
    }else if(width<1 || length<1){
      printf("Invalid data provided.\n");
      return 0;
    }
    for(i=0;i<width;i++){
      for(j=0;j<length;j++){
        printf("%c", symbol);
      }
      printf("\n");
    }
    return 0;
}

int triangle(){
  char symbol,space=' ';
  int size, grid,row,col,counter=0;
  /*counters counts the # of sym next to middle col*/
  printf("Enter character and size: ");
  scanf(" %c %d", &symbol, &size);

  if(symbol!='*' && symbol!='#' && symbol!='%'){
    printf("Invalid data provided.\n");
    return 0;
  }else if(size<1){
    printf("Invalid data provided.\n");
      return 0;
  }else if(size>1){
    grid=(size*2)-1;
  }else if(size==1){
    printf("\n %c", symbol);
    return 1;
  }

  /*  printf("\n");*/

    for(row=0;row<size;row++){
      for(col=0;col<grid;col++){
        if(col==size-1){ /*if middle column*/
          printf("%c", symbol);
        }else if(row==size-1){ /*if last row*/
          printf("%c", symbol);
        }else if(col>size-1){ /*if right triangle*/
          if(col> (grid/2 +counter)){
            printf("%c",space);
          }else{
            printf("%c",symbol);
          }
        }else if(col<size-1){ /*if left triangle*/
          if(col<((size-1)-counter)){
            printf("%c", space);
          }else{
            printf("%c", symbol);
          }
        }
      }
      counter++;
      printf("\n");
    }
    return 1;
}
