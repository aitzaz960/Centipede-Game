

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_

#include "head.h"
#include "Bomb.h"
#include "Board.h"
#include "util.h"
#include <iostream>
#include<stdlib.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt

using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


Bomb bmb[500];
Mushroom food[30];
int bomb_count=0;
Player p1;
Centipede cbs[10]={ {10},{1},{1},{1},{1},{1},{1},{1},{1},{1} };
ScoreBoard sb;
Flea f;
int f_count = 0;
/*
 * Main Canvas drawing function.
 * */
Board *b;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	//Grid of the game
	/*for(int a=0; a<51; a++)
	{	for(int q=0; q<42; q++)
			DrawSquare(a*20, q*20,19, colors[BROWN]);
	}*/
	for(int a=0; a<51; a++)
	{
		for(int m=0; m<5; m++)
		{
			if(b->board_array[a][m]==5)
			{
				b->board_array[a][m] = 0;
			}
			b->board_array[p1.getPosition().getX() ][p1.getPosition().getY() ] = 5;
		}
	}
	
	if( f_count < 250 & f.getDis() == 1)
	{
		f.draw();
		f.move();
	}

	if(f_count == 10)
	{
		f.showOnScren();
	}
	if(f_count == 250)
		f_count = 0;
	f_count++;

	sb.draw();
	//fixing mushroom position in the grid
	for(int r=0; r<30; r++)
	{
		b->board_array[ food[r].getPosition().getX() ][ food[r].getPosition().getY() ] = 65;
		for(int a=0; a<10; a++)
		{
			if(cbs[a].isAlive()==1)
				cbs[a].centi_location[ food[r].getPosition().getX() ][ food[r].getPosition().getY() ] =65;
		}
	}


	//Draws Mushrooms which are active
	for(int c=0; c<30; c++)
	{	//food[c].dead();
		if(food[c].isActive() == 0 && b->board_array[ food[c].getPosition().getX() ][ food[c].getPosition().getY() ] == 65)
			b->board_array[ food[c].getPosition().getX() ][ food[c].getPosition().getY() ] = 0;
		if(food[c].isActive() == 1)
			food[c].draw();
	}

	//Draws the player
	p1.draw();

	//Draws Centipedes which are alive	
	for(int a=0; a<10; a++)
	{	if(cbs[a].isAlive()==1)
			cbs[a].draw();
	}

	for(int c=0; c<10; c++)
	{
		if(cbs[c].isAlive() ==1)
		{
			for(int m=0; m<51; m++)
			{	for(int n=0; n<42; n++)
				{
					if( cbs[c].centi_location[m][n]==112 )
						b->board_array[m][n] = 112;	
				}
			}
		}
	}

	
	for(int i=0; i<500; i++)
	{
		if( bmb[i].isActive() == 1)
		{
			bmb[i].move();
			
			for(int m=0; m<51; m++)
			{	for(int n=0; n<42; n++)
				{	
					//Decrease the life of mushroom if encountered
					if( b->board_array[m][n] == 65 && bmb[i].getPosition().getX() == m && bmb[i].getPosition().getY() == n)
					{	
						for(int v=0; v<30; v++)
						{
							if(food[v].getPosition().getX() == m && food[v].getPosition().getY() == n)
							{
								food[v].decreaseLife();
								if( food[v].isActive() == 0)
									sb.updateScore(1);
								bmb[i].setActive();
							}
						}
					}

					//kills a segment of centipede if encountered with
					if( b->board_array[m][n] == 112 && bmb[i].getPosition().getX() == m && bmb[i].getPosition().getY() == n)
					{
						int f =0;
						for(int x=0; x<10; x++)
						{
							if( cbs[x].isAlive()==1)
							{
								if(cbs[x].centi_location[m][n]==112)
									f = x;
							}
						}

						if( cbs[f].getSegments()[0]->getCX() == m && cbs[f].getSegments()[0]->getCY() == n )
						{
							cbs[f].shiftHead();
							if(cbs[f].isAlive() == 0)
								sb.updateScore(100);
						}
						else
						{
							bool go = true;
							int temp = 0;
							while( go == true && temp<10)
							{
								if(cbs[temp].isAlive() == 0)
								{
									cbs[temp].setLife(cbs[f], m, n);
									sb.updateScore(10);
									go = false;
								}
								temp++;
							}
							bmb[i].setActive();
						}
					}
				}
			}
		//	bmb[i].move();
		//	bmb[i].move();
		}

	}

	for(int a=0; a<10; a++)
	{
		if(cbs[a].isAlive() ==1)
		{
			cbs[a].move();
		}
	}
	
	for(int a=0; a<51; a++)
	{
		for(int m=0; m<5; m++)
		{
			for(int n=0; n<10; n++)
			{
				if(cbs[n].isAlive() ==1 )
				{
					if( p1.getPosition().getX() == cbs[n].getSegments()[0]->getCX() && p1.getPosition().getY() == cbs[n].getSegments()[0]->getCY() )
					{
						sb.decreaseLives();						
					}
				}
			}
		}
	}

	for(int m=0; m<51; m++)
	{	for(int n=0; n<42; n++)
		{
			if(b->board_array[m][n]==112)
			b->board_array[m][n] =0;
		}
	}

	for(int c=0; c<10; c++)
	{
		if(cbs[c].isAlive() ==1)
		{
			for(int m=0; m<51; m++)
			{	for(int n=0; n<42; n++)
				{
					if( cbs[c].centi_location[m][n]==112 )
						b->board_array[m][n] = 112;	
				}
			}
		}
	}
	
	

	/*
	//Fire Gun
	DrawSquare( 400 , 20 ,40,colors[RED]); 
	//Mushroom
	DrawSquare( 250 , 250 ,16,colors[GREEN]); 
	//Display Score
	DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	//Spider
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//glutPostRedisplay();
	*/
	glutSwapBuffers(); // do not modify this line..
	
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key	== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) 
	{
		// what to do when left key is pressed...
		p1.setDirection(3);
		p1.move();

	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{	
		p1.setDirection(2);
		p1.move();
	}
	else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		p1.setDirection(1);
		p1.move();
	}
	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		p1.setDirection(4);
		p1.move();
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	//glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	if( key == 'o')
	{
		bmb[bomb_count].setActive();
		bmb[bomb_count].setPosition( p1.getPosition().getX(), p1.getPosition().getY() );
		//cout << bmb[bomb_count].getPosition().getX() << "@" << bmb[bomb_count].getPosition().getY() << endl;
		bomb_count++;
	}

	if( key == 'q')
	{
		
	}

	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {


	// implement your functionality here
	glutPostRedisplay();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(80, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	srand(time(NULL));
	b = new Board(51, 42); // create a new board object to use in the Display Function ...

	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...



	for(int s=0; s<30; s++)
	{
		food[s].getPosition().setX(rand()%51);
		food[s].setPosition( rand()%51, rand()%34+5 );
		b->board_array[ food[s].getPosition().getX() ] [ food[s].getPosition().getY() ] = 65;
	}
	for(int a=1; a<10; a++)
	{
		cbs[a].killCentipede();
	}
	
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
