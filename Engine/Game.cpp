
#include "MainWindow.h"
#include "Game.h"
#include "ctime"
#include <ctime>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

int xena[999];
int yondel[999];
int counter = 0;

void usedPixels(int x, int y, int counter) {
	xena[counter] = x;
	yondel[counter] = y;

}

void Game::ComposeFrame()
{
	double pixelDensity = 1;
	pixelDensity = (pixelDensity * 5);

	for (double i = 0; i < 200; i = i + pixelDensity) {
		gfx.PutPixel(200, i, 255, 255, 0);
		//yellow is 200 mark
		for (double i = 0; i < 200; i = i + pixelDensity) {
			gfx.PutPixel(i, 200, 255, 255, 0);
			//yellow is 200 mark
		}//reds
		for (double i = 0; i < 300; i = i + pixelDensity) {
			gfx.PutPixel(300, i, 255, 0, 0);
			//red is 300 mark
			for (double i = 0; i < 300; i = i + pixelDensity) {
				gfx.PutPixel(i, 300, 255, 0, 0);
				//red is 300 mark
			}//blues
			for (double i = 0; i < 400; i = i + pixelDensity) {
				gfx.PutPixel(400, i, 0, 0, 255);
				//blue is 400 mark
			}
			for (double i = 0; i < 400; i = i + pixelDensity) {
				gfx.PutPixel(i, 400, 0, 0, 255);
				//blue is 400 mark
			}
			double tempValueX;
			double tempValueY;
			double hOfMovingLine;
			double kOfMovingLine;
			double radius = 25;
			double milliseconds = 50;
			double sinradius = sin(radius);
			double cosradius = cos(radius);
			long hOfSlowLine = 25;
			long kOfSlowLine = 25;
			double next = 0;
			double xPosMovingLine = 0;
			double yPosMovingLine = 0;
			double xPos = 0;
			double yPos = 0;
			boolean doubleersection = false;
			double iterationcounter = 0;
			boolean tickingClock = false;
			int adjacentdistance;
			int oppositedistance;
			int thirdcoordinatexPos;
			int thirdcoordinateyPos;
			int magnitudedistancethirdcoordinatex;
			int magnitudedistancethirdcoordinatey;
			int ultra;
			boolean right = false;
			boolean above = false;
			boolean below = false;
			boolean left = false;
			boolean xintercepted = false;
			boolean notabove;
			boolean notright;
			boolean nottopright;
			boolean yintercepted = false;
			//okay, so the shower code i wrote this morning was as follows
			//create the proper slope of 25Rise/75Run, that's our slope. not fucking 25/25.
			//you get these numbers by finding the distance between our tempX, and xPos.
			int h = 0;
			int k = 100;
			//this is the master for loop. every time this terminates, a new point is drawn on the master to-draw-to line, and a new line should be redrawn to meet it.
			for (double i = 0; i < 300; i = i + pixelDensity) { //master for loop
				if (clock() < next) { // does nothing currently
					tickingClock = false; //does nothing currently
				}
				if (clock() > next) //ticker, every next milliseconds, run the entire master for loop.
				{
					next += 100; //milliseconds to wait before attempting next master for loop
					tickingClock = true; //does nothing currently


					double xPos = (hOfSlowLine + i); //xpos is x position of the line of the master to-draw-to line, 
					double yPos = (kOfSlowLine + i); //ypos is the y position of the master TDT line.
					gfx.PutPixel(xPos, yPos, 255, 255, 255); //put a pixel, every next milliseconds, to xpos, ypos, this is the line that creates the TDT line.
					int rise = yPos - k;		//deprecated
					int run = xPos - h;			//deprecated
					double slope = rise / run;  //deprecated
					int tempY = 0 + k;			//this is the master variable for the position of the lines drawn to meet the to-draw-to line. (TDT Line)
					int tempX = 0 + h;			//this is the master variable for the position of the lines drawn to meet the to-draw-to line. (TDT Line)



					
					double tempcompx1, tempcompx2, tempcompx3;
					double tempcompy1, tempcompy2, tempcompy3;
					double magright, magabove, magtopright;

					/*
					//for loop description - orientation logic.
					//this for loop is just a logic algorithm that determines if the point to create a line to,
					//is to the left, to the right, above, or below, the line's h,k draw point.
					*/

			//start orientation logic, description above
					for (int z = 0; z < xPos || z == xPos; z++) {
						if (xPos > tempX) {
							right = true;
							left = false;
							xintercepted = false;
						}
						if (xPos == tempX) {
							xintercepted = true;
							right = false;
							left = false;
						}
						if (xPos < tempX) {
							left = true;
							right = false;
							xintercepted = false;
						}
						if (yPos < tempY) {
							above = true;
							below = false;
							yintercepted = false;
						}
						if (yPos > tempY) {
							below = true;
							above = false;
							yintercepted = false;
						}
						if (yPos == tempY) {
							yintercepted = true;
							below = false;
							above = false;
						}
			//end orientation logic


			//closest pixel logic. this is not ideal, but again, this is experimental just to practice and have fun. using magnitudes instead of slopes is the idea here.
			//the easiest solution would obviously be to utilize slopes, and for every number x travelled, travel a number y, before utilizing x again. 
						//again, this is for fun!
						if (above == true || right == true) {
							tempcompx1 = 1 + z + h; //x value to the right, of Meet Line.
							tempcompx2 = 0 + z + h; //x value above, of Meet Line.
							tempcompx3 = 1 + z + h; //x value diagonally top right, of Meet Line.
							tempcompy1 = 0 + z + k; //y value to the right, of Meet Line.
							tempcompy2 = 1 + -z + k;//y value above, of Meet Line.
							tempcompy3 = -1 - z + k;//y value diagonally to the right, of Meet Line.

							//the logic below is the literal maths, determining what orientation to use to achieve
							//the least amount of pixels to draw to meet our TDT Line from our Meet Line.
							double tempcompminusx1pos = tempcompx1 - xPos; //example; this says, theoretically, if we chose the pixel above meet line, the
							double tempcompminusx2pos = tempcompx2 - xPos; //magnitude would be X. Is X less than the magnitude of below, diagonal, or whatever?
							double tempcompminusx3pos = tempcompx3 - xPos; //then set that as the chosen next pixel.
							double tempcompminusy1pos = tempcompy1 - yPos;
							double tempcompminusy2pos = tempcompy2 - yPos;
							double tempcompminusy3pos = tempcompy3 - yPos;
							double powmagx1 = pow(tempcompminusx1pos, 2);
							double powmagy1 = pow(tempcompminusy1pos, 2);
							double powxy1 = powmagx1 + powmagy1;
							magright = sqrt(powxy1);
							double powmagx2 = pow(tempcompminusx2pos, 2);
							double powmagy2 = pow(tempcompminusy2pos, 2);
							double powxy2 = powmagx2 + powmagy2;
							magabove = sqrt(powxy2);
							double powmagx3 = pow(tempcompminusx3pos, 2);
							double powmagy3 = pow(tempcompminusy3pos, 2);
							double powxy3 = powmagx3 + powmagy3;
							magtopright = sqrt(powxy3);
						
							if (magright < magabove && magright < magtopright) {
								tempX = tempcompx1;
								tempY = tempcompy1;
								usedPixels(tempX, tempY, z);
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								
							}
							else { notright = true; }
							if (magabove < magright && magabove < magtopright) {
								tempX = tempcompx2;
								tempY = tempcompy2;
								usedPixels(tempX, tempY, z);
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
							
							}
							else { notabove = true; }
							if (magtopright < magright && magtopright < magabove) {
								tempX = tempcompx3;
								tempY = tempcompy3;
								usedPixels(tempX, tempY, z);
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								
							}
							else {
								nottopright = true;
								if (notabove == true && nottopright == true && notright == true) {
									notabove = false;
									notright = false;
									nottopright = false;
									tempX = tempcompx3;
									tempY = tempcompy3;
									usedPixels(tempX, tempY, z);
									gfx.PutPixel(tempX, tempY, 255, 255, 255);
								}
							}
						}
					}
				}
			}


		}


	}
}

