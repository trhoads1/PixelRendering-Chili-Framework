/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	adouble with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
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
			for (double i = 0; i < 300; i = i + pixelDensity) {
				if (clock() < next) {
					tickingClock = false;
				}
				if (clock() > next)
				{
					next += 100;
					tickingClock = true;


					double xPos = (hOfSlowLine + i);
					double yPos = (kOfSlowLine + i);
					gfx.PutPixel(xPos, yPos, 255, 255, 255);
					int rise = yPos - k;
					int run = xPos - h;
					double slope = rise / run;
					int tempY = 0 + k;
					int tempX = 0 + h;


					//this for loop runs for every x value between xpos and h. it should be expected that every time this is accessed, 
					//it will draw xpos-h number of pixels. any use of tempcomp is assessing which of the three pixels we should use
					//based on which one has a lesser magnitude to our desired point, (xpos,ypos)
					double tempcompx1, tempcompx2, tempcompx3;
					double tempcompy1, tempcompy2, tempcompy3;
					double magright, magabove, magtopright;

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
						if (above == true || right == true) {
							tempcompx1 = 1 + z + h; //x value to the right
							tempcompx2 = 0 + z + h; //x value above us
							tempcompx3 = 1 + z + h; //x value diagonally top right
							tempcompy1 = 0 + z + k;//y value to the right
							tempcompy2 = 1 + -z + k;//y value above us
							tempcompy3 = -1 - z + k;//y value diagonally to the right	

							double tempcompminusx1pos = tempcompx1 - xPos;
							double tempcompminusx2pos = tempcompx2 - xPos;
							double tempcompminusx3pos = tempcompx3 - xPos;
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
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								
							}
							else { notright = true; }
							if (magabove < magright && magabove < magtopright) {
								tempX = tempcompx2;
								tempY = tempcompy2;
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
							
							}
							else { notabove = true; }
							if (magtopright < magright && magtopright < magabove) {
								tempX = tempcompx3;
								tempY = tempcompy3;
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

