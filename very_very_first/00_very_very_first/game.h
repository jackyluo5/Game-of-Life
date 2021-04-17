#ifndef GAME_H
#define GAME_H
const int MAX = 10;
const int ALIVE = 1;
const int DEAD = 0;
const int SCREEN_WIDTH = 100;
const int SCREEN_HEIGHT = 100;
const int SIZE_ARRAY = 10;
const int CELL_LENGTH = 8;

class game
{
public:
    game();
    void init(int grid[][MAX]);     //clears the array and sets everything to 0
    void print (int grid[][MAX]);   //prints the array out
    void setAlive(int grid[][MAX], int i, int j);   //sets an individual point to come alive
    void kill(int grid[][MAX], int i, int j);   //kills and individual point, becomes 0
    bool isAlive(int grid[][MAX], int i, int j);    //checks which point in the array is alive
    int countNeighbors(int grid[][MAX], int i, int j);  //counts all the neighbors around the point
    void step(int grid[][MAX]);     //goes through the rules of the array of neighbors
    int living(int grid[][MAX], int i, int j);  //shows how many living cells there are

    int random(int high, int low);  //creates a random number of live cells


    void update();
    void render();


private:
    int rows = 10;
    int columns = 10;

};

#endif // GAME_H
