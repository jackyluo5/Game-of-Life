#include "game.h"
#include <iostream>
#include <iomanip>

using namespace std;

game::game()
{
}
void game::init(int grid[][MAX]){
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            grid[i][j] = DEAD;
        }
    }
}
void game::print (int grid[][MAX]){
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            cout<<setw(2)<<grid[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void game::setAlive(int grid[][MAX], int i, int j){
    grid[i][j] = ALIVE;
}
void game::kill(int grid[][MAX], int i, int j){
    grid[i][j] = 0;
}
bool game::isAlive(int grid[][MAX], int i, int j){
    if(grid[i][j] == ALIVE){
        return true;
    }
    else{
        return false;
    }
}
int game::countNeighbors(int grid[][MAX], int i, int j){
    int neighbors = 0;
    for(int x=i-1; x<=i+1; x++){
        for(int y=j-1; y<=j+1; y++){
            neighbors += grid[x][y];
        }
    }
    neighbors -= grid[i][j];
    //    if(grid[i][j] == ALIVE){
    //        neighbors--;
    //    }
    return neighbors;
}
void game::step(int grid[][MAX]){
    int neighbors;
    int hold[MAX][MAX]; //a temporary array that stores values
    //runs through the array
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            //checks the surrounding for the
            neighbors = countNeighbors(grid, i, j);
            if((grid[i][j] == ALIVE) && (neighbors<2)){   //cell is lonely and dies
                kill(hold, i, j);
            }
            else if((grid[i][j] == ALIVE) && (neighbors>3)){  //cell dies from overpopulation
                kill(hold, i, j);
            }
            else if((grid[i][j] == DEAD) && (neighbors==3)){ //new cell is born
                hold[i][j] = ALIVE;
            }
            else{   //remains the same
                hold[i][j] = grid[i][j];
            }
        }
    }
    cout<<"next gen"<<endl;
    for (int i=0; i<MAX; i++){
        for (int j=0; j<MAX; j++){
            if(hold[i][j]==0){
                kill(hold, i, j);
            }
            else{
                isAlive(hold, i, j);
            }
            grid[i][j] = hold[i][j];
        }
    }
}
int game::living(int grid[][MAX], int i, int j){
    int living=0;
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            if(isAlive(grid,i,j)){
                living ++;
            }
        }
    }
    return living;
}

int game::random(int high, int low){
    int r = rand()%(high-low+1)+low;
    return r;
}


