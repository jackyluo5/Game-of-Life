#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include "../../../Desktop/CS2/!include/game_of_life/game.h"

/*==================================================
 * RULES:   For a space that is 'populated':
            -We define each cell to have eight neighbor cells.
             -The neighbors of a cell are the cells directly above, below, to the right, 
              to the left, diagonally above to the right and left, and diagonally 
              below to the right and left.
            -Each cell with one or no neighbors dies, as if by solitude.
            -Each cell with four or more neighbors dies, as if by overpopulation.
            -Each cell with two or three neighbors survives.
            -For a space that is 'empty' or 'unpopulated'
            -Each cell with three neighbors becomes populated.
            
            -Births and deaths are instantaneous and occur at the changes of generation.
             A cell dying for whatever reason may help cause birth, but a
             newborn cell cannot resurrect a cell that is dying, nor will a cell’s death
             prevent the death of another, say, by reducing the local population.

 * CONTROLS: [NUM1]: SAVE, [NUM2]: LOAD, [S]: iterate one, [G]: run continuously, [C]: clear, [R]: randomize, [ESC]: close
 * BOXES ON RIGHT:  FIRST BOX = [G], SECOND BOX = [R], THIRD BOX = [C], FOURTH BOX: [NUM1], FIFTH BOX: [NUM2],  [ESC]: close
 *
 * FUNCTIONS: init, print, setAlive, kill, isAlive, countNeighbors, step, random, randomize, save, load,
 * CLASS: game. Private variables = real[MAX][MAX], load[MAX][MAX]
 * SFML: ProccessEvents, FillShapes, ShowShapes, Boxes
 * =================================================
 *
 * Process:
 * I started with the basic knowledge of classes and creating the code necessary for the neighbors function.
 * I started with a basic set alive, is alive, and kill function
 * Then with that, I could make my functions of the neighbors and the step function.
 * I drew everything out to understand it more in depth and helped me write the main functions
 * Once I had all my functions, I made a class and moved my arguments that contained arrays into a global variable
 * I also set constants and the variables needed for sfml
 * Once I've tested all my functions and everything works fine, I slowly moved everything onto sfml
 * I got the windows and the grid and the setup all working and it's based on coordinates
 * I put everything together and it works exactly how the game of life should.
 */

using namespace std;

int main()
{
    //initializes the array to 0
    game x; //caller variable for class game/grid
    bool repeat = false;  //bool for the events function that calls a continuous from processevents

    //********************SFML CODE****************************

    ////----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
    //
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.
    //
    //or...
    // you could do this:
    //sf::RenderWindow window;
    //window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game of Life");
    //
    window.setFramerateLimit(30);

    //this is where we keep all the shapes.
    sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];

    window.setVerticalSyncEnabled(true); // call it once, after creating the window
    //Application runs at the same freq as monitor

    //. . . . . . . SHAPES ............
    //this is how you would declare and manipulate shapes:
    //sf::CircleShape shape(250.f);
    //shape.setFillColor(sf::Color::Green);
    //// set a 10-pixel wide orange outline
    //shape.setOutlineThickness(1);
    //shape.setOutlineColor(sf::Color(250, 150, 100));


    //// define a 120x50 rectangle
    //sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    //// change the size to 100x100
    ////rectangle.setSize(sf::Vector2f(10, 10));
    //. . . . . . . . . . . . . . . . . . . . . . . . . . .


    // run the program as long as the window is open
    while (window.isOpen())
    {
        //checks by reference
        if(repeat == true){ //where cont in class is set to true
            x.step();   //runs if it is true, switch cases will turn on or off
        }

        //Process mouse and keyboard events:
        x.ProcessEvents(window, repeat);

        //necessary: get read for the next frame:
        window.clear(sf::Color(255, 165,0));

        //necessary to create boxes on the side bar(text is broken for me)
        x.Boxes(window);

        //set up the next frame:
        x.FillShapes(shapeArray);

        //draw the shapes on the window object:
        x.ShowShapes(window, shapeArray);

        //display the window and all its shapes:
        window.display();

    }
    return 0;
}

//***********************************debug code*****************************
//    cout <<endl<<endl<< "=====================" << endl<<endl;
//    int grid[MAX][MAX];
//    char repeat;
//    int generation = 1;

//    srand(time(0));

//    x.init();
//    x.print();


//    cout<<"Generation: "<<endl;
//    cout<<"come alive"<<endl;
//    x.setAlive(1, 2);
//    x.setAlive(2, 2);
//    x.setAlive(3, 2);
//    x.print();

////    x.randomize();
////    x.print();

//    //        x.step(grid);
//    //        x.print(grid);
//    //        x.step(grid);
//    //        x.print(grid);

//    do{
//        x.step();
//        x.print();
//        cout<<"Generation: "<<generation++<<endl;
//        cin.get(repeat);
//    }while(repeat == '\n');

//    cout <<endl<< "=====================" << endl;
//    return 0;
//}
