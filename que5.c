#include<stdio.h>

#define MR 5
#define MC 5

typedef struct{
  int rows;
  int cols;
  int workspace[MR][MC];
  int robot_pos_row;
  int robot_pos_col;
} RobotWorkspace;

void initializeWorkspace(RobotWorkspace* workspace){
  int row,col;
  for(row=0; row < workspace->rows;row++){
    for(col=0;col < workspace->cols; col++){
      workspace->workspace[row][col] = 1;
    }
  }
  workspace->robot_pos_row = 0;
  workspace->robot_pos_col = 0;
}

void insertObstacle(RobotWorkspace *workspace, int row, int col){
  if(row>=0 && row < workspace->rows && col >= 0 && col < workspace->cols){
     workspace->workspace[row][col]=0;
  }
  else{
    printf("Invalid obstacle coordinates\n");
  }
}

void moveRobot(RobotWorkspace* workspace, char direction){
  int new_row = workspace->robot_pos_row;
  int new_col = workspace->robot_pos_col;

  if(direction == 'u' || direction == 'U'){
    new_row--;
  }else if(direction == 'd' || direction == 'D'){
    new_row++;
  }else if(direction == 'l' || direction == 'L'){
    new_col--;
  }else if(direction == 'r' || direction == 'R'){
    new_col++;
  }else{
    printf("Invalid direction\n");

    return ;
  }

  if(new_row >=0 && new_row < workspace->rows && new_col >=0 && new_col < workspace->cols && workspace->workspace[new_row][new_col] != 0){
    workspace->robot_pos_row = new_row;
    workspace->robot_pos_col = new_col;
  }
}

void displayWorkspace(RobotWorkspace* workspace){
  int row,col;
  for(row = 0;row < workspace->rows; row++){
    for(col = 0;col < workspace->cols; col++){
      if(row == workspace->robot_pos_row && col == workspace->robot_pos_col){
        printf("R ");
      }else if(workspace->workspace[row][col] == 0){
        printf("0 ");
      }else{
        printf("1 ");
      }
    }
    printf("\n");
  }
}

int main(){
  RobotWorkspace workspace;
  workspace.rows = 5;
  workspace.cols = 5;

  initializeWorkspace(&workspace);

  insertObstacle(&workspace,2,2);
  insertObstacle(&workspace,4,3);
  insertObstacle(&workspace,1,2);
  insertObstacle(&workspace,3,0);
  insertObstacle(&workspace,0,4);

  displayWorkspace(&workspace);
  printf("\n");

  moveRobot(&workspace, 'd');
  moveRobot(&workspace, 'r');

  displayWorkspace(&workspace);
  printf("\n");

  moveRobot(&workspace, 'r');
  displayWorkspace(&workspace);
}
