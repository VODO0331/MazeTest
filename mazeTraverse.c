#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 13

void print(char **, int , int );
int start_exploring(char **, int , int);
void back(int **, int *, int *, int *); 
void MazeMaker(char **);



int main(void){
    char maze[SIZE][SIZE]={'\0'};

    for(int i=0;i<SIZE;i++)
   {
       maze[0][i] = '#';
       maze[SIZE-1][i] = '#';
       maze[i][0] = '#';
       maze[i][SIZE-1]='#';
   }//end for

   char *p[SIZE];

   for(int i=0; i<SIZE; i++){
        p[i] = maze[i];
  }//end for
    srand(time(NULL));
    MazeMaker(p); //make maze


    int l;
    int m=0, n=0;
    //set end 
    for(l=0; l<SIZE; l++){
        
        if(maze[l][SIZE-1] == '.'){
            maze[l][SIZE-1] = 'E';
            
        }//end if
    }//end for
    //set Starting point
    for(l=0; l<SIZE; l++){
        if(maze[m + l][n] == '.'){
            maze[m + l][n] = 'S';
            m += l;
            start_exploring(p, m, n);
            break;
        }//end if

    }//end for

    print(p, SIZE, SIZE);//printf maze



return 0;
}//end main

void print(char **ar, int y, int x){
    
    int i, j;
    for(i=0; i<x ;i++){
        for(j=0;j<y ;j++){
            printf("%c ",ar[i][j]);
        }//end for
        printf("\n");
    }//end for

}//end function print

int start_exploring(char **ar2, int y, int x){
    
    int ba_ar[60][2]={0}; //array for record path
     
    int *q[60]={0};

    for(int i=0; i<60; i++){
        q[i] = ba_ar[i];
    }//end for

    int h=0;
    
    do{
        if(ar2[y][x + 1] == '.'){//right

            ar2[y][x + 1] = 'x';
            x +=1; 

            h++;
            ba_ar[h][1] = -1;
            
            
            
        }else if(ar2[y][x + 1] == 'E'){// out
            printf("\nEscape successfully!!!!!!!\n\n");
            return 0;


        }else if(ar2[y + 1][x] == '.'){//down

            ar2[y + 1][x] = 'x';
            y +=1;

            h++;
            ba_ar[h][0] = -1;
            
            
        }else if(ar2[y][x - 1] == '.'){// left

            ar2[y][x - 1] = 'x';
            x -=1;

            h++;
            ba_ar[h][1] = 1;
            
            
        }else if(ar2[y][x - 1] == 'S'){

            printf("This maze can not reach the end!!!!\n\n");
            return 0;

        }else if (ar2[y - 1][x] == '.'){// up

            ar2[y - 1][x] = 'x';
            y -=1;

            h++;
            ba_ar[h][0] = 1;
            

        }else{

            back(q, &y, &x, &h);
            h--;

        }//end if
        
    }while(h != 0);
    

} //end function start_exploring

void back(int **ar3, int * a, int * b, int * c){
    *a += ar3[*c][0];
    *b += ar3[*c][1];
    
    ar3[*c][0] = 0;
    ar3[*c][1] = 0;
    
    
    
           
}//end function back
 
void MazeMaker(char ** mz){
  int xx, yy;
  int ra, wall;
  int r;
// make wall
  for(int i=0; i<60; i++){

    xx = (rand()% 6 + 1) * 2;
    yy = (rand()% 6 + 1) * 2;
    
    ra = rand() % 4 + 1;
    wall = rand() % 4 + 1;
    
    switch (ra)
    {
    case 1: //build right
      for(r=0; r<wall; r++){
        if(mz[yy][xx + r] != '#'){

          mz[yy][xx + r] = '#';
        }else{

          break;

        }//end if

      }//end for

      break;
    case 2: //build left
      for(r=0; r<wall; r++){
        if(mz[yy][xx - r] != '#'){

          mz[yy][xx - r] = '#';
        }else{

          break;

        }//end if

      }//end for
          break;

    case 3: //build down
      for(r=0; r<wall; r++){
        if(mz[yy + r][xx] != '#'){

          mz[yy + r][xx] = '#';
        }else{

          break;

        }//end if

      }//end for
      
      break;
      
    case 4: //build up
      for(r=0; r<wall; r++){
        if(mz[yy - r][xx] != '#'){

          mz[yy - r][xx] = '#';
        }else{

          break;

        }//end if

      }//end for
      
      break;

    default:
      break;

    }// end switch

    
  }//end for
  

  int m, n;
//fill up the road
  for(m=0; m<SIZE; m++){
    for(n=0; n<SIZE; n++){
      if(mz[m][n]=='\0'){
        mz[m][n] = '.';
      }//end if

    }//end for

   }//end for

//set set starting point 
  for(int p=0; p<SIZE; p++){
    yy = (rand()% 6 + 1) * 2;
    
    if(mz[yy][1] == '.' ){

      mz[yy][0] = '.';
      
      break;

    }//end if 

  }//end for

//set  end point
  for(int p=0; p<SIZE; p++){

    yy = (rand()% 6 + 1) * 2;
    
    if(mz[yy][11] == '.'){

      mz[yy][12] = '.';
      
      break;

    }//end if 

  }//end for

}