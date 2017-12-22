
#include "MainWindow.h"
#include "Game.h"
#include "ctime"
#include <ctime>
#include <iostream>
#include <cmath>
#include <math.h>
#include "Colors.h"
using namespace std;
using namespace Colors;
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


//playan with them arrays, ya'll https://www.cs.nmsu.edu/~rth/cs/cs471/C%2B%2BDynamicArray.pdf
class Dynarray {
private:
	int *pa;
	int length;
	int nextIndex;
public:
	Dynarray();						//constructor
	~Dynarray();					//desctructor
	int& operator[] (int index);	//indexing op
	void add(int val);				//add a new value to the end of the array
	int size();						//return length
	
	
	
};
Dynarray::~Dynarray() {
	delete[] pa;
}

Dynarray::Dynarray() { //whenever this bitch is called, he just makes 11 elements, and assigns them all to zero.
	pa = new int[10];
	for (int i = 0; i < 10; i++) {
		pa[i] = 0;
		length = 10;
		nextIndex = 0;
	}
}
int Dynarray::size() {
	return length;
}
int& Dynarray::operator[](int index) {
	int *pnewa;										// pointer for new array
	if (index >= length) {							// is element in the array?
		pnewa = new int[index + 10];				 // allocate a bigger array
		for (int i = 0; i < nextIndex; i++)				// copy old values
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < index + 10; j++)		// initialize remainder
			pnewa[j] = 0;
		length = index + 10;						// set length to bigger size
		delete[] pa;								// delete the old array
		pa = pnewa;									// reassign the new array
	}
	if (index > nextIndex)							// set nextIndex past index
		nextIndex = index + 1;
	return *(pa + index);							// a reference to the element
}
void Dynarray::add(int val) {
	int *pnewa;
	if (nextIndex == length) {
		length = length + 10;
		pnewa = new int[length];
		for (int i = 0; i < nextIndex; i++)
			pnewa[i] = pa[i];
		for (int j = nextIndex; j < length; j++)
			pnewa[j] = 0;
	//	jhbkljhbkjhbkjhbkjhbkjhb
		delete[] pa;
		pa = pnewa;
	}
	pa[nextIndex++] = val;
}
	
	//DO WHAT YOU WERE SUPPOSED TO DO, PLEASE! ADD THE REQUESTED ELEMENT!
	/*
	2175234281493376693817212167497687911136241765326
	1522357855816893656462449168377359285244818489723
	8699878612479122897295792966916847611435449569915
	8394221523656896187585175585497794614717874646467
	5227699149925227227137557479769948569788884399379
	8211113825367226995757594744732739397563489927146
	6796359618976573474316948959912577144334819338356
	6159843593541134749392569865481578359825844394454
	1732198579193493414421482822296895415611693416222
	2235465139734292867849647867133938392376985642579
	5211323673389723181967933933832711545885653952861
	8792315379762925178663548129431927282632695247356
	9842333667373515899385355614883386132795926225475
	6647827739145283577793481526768156921138428318939
	3618597217785562645196434358718357448592431672278
	8956273871295365112831762467398521352589752237825
	9178625416722152155728615936587369515254936828668
	5648572832264398812668719459987964884722491825388
	8335418657392518315266386268399544967166328577539
	7453876262722567452435914777363522817594741946638
	9865717936558894664198959969241229157772244994814
	9683734319414912373535526815194171287124586355383
	6953349887831949788869852929147849489265325843934
	6699993918462863192686867893725139765222825875268
	6614816633721596149353626285151221879413927236129
	2811529888161198799297966893366553115353639298256
	7888193852724711872135791855235213416511179476767
	8534114623544141144181324251481322782184381942461
	9974979886871646621918865274574538951761567855845
	6812723646461385847163335998438351673735252485475
	4244294258312262453449444251625961697323585846913
	1159773167334953658673271599748942956981954699444
	5286896288486944468188254654851228697428397114711
	2986263212863577965836575636286362713598361761333
	2849756371986376967117549251566281992964573929655
	5893138719765567848492319165138315382548123471162
	5394981863352718517422156527977576674226268771311
	4114344843534958833372634182176866315441583887177 W 
	7592225988537351141918742777114346538548168415892
	2991416468136449742932446319366933782746766177383
	3517841763711156376147664749175267212562321567728
	5757658448932327189714712898411716428689488521368
	1866174123817867685738158315554775521983711612599
	5361896562498721571413742


	*/





void Game::ComposeFrame()
{
	Dynarray xValLastLineDrawn; //bitchcall
	Dynarray yValLastLineDrawn;	//bitchcall
	double pixelDensity = 1;
	pixelDensity = (pixelDensity * 5);
	for (double i = 0; i < 200; i = i + pixelDensity) {
		gfx.PutPixel(i, 50, 255, 255, 0);
		//yellow is 50 mark
	}

	for (double i = 0; i < 200; i = i + pixelDensity) {
		gfx.PutPixel(i,100, 255, 255, 0);
		//yellow is 100 mark
	}

	for (double i = 0; i < 200; i = i + pixelDensity) {
		gfx.PutPixel(200, i, 255, 255, 0);
		//yellow is 200 mark
	}
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
			boolean notabove = false;
			boolean notright = false;
			boolean nottopright = false;
			boolean yintercepted = false;
			boolean breakpoint = false;
		
			int h = 0;
			int k = 100;
			int tempY = 0 + k;
			int tempX = 0 + h;
			for (double i = 0; i < 300; i++) {
				if (clock() < next) {
					tickingClock = false;
				}

				//for(x val 1, x val 2, val 3){
				//        for y val 1 2 3 { 
				//        
				if (clock() > next)
					for (int xxx = 0; xxx < xValLastLineDrawn.size(); xxx++) {
					//	gfx.PutPixel(xValLastLineDrawn[xxx], yValLastLineDrawn[xxx], LightGray);
					}
				yValLastLineDrawn.~Dynarray();
				xValLastLineDrawn.~Dynarray();
				Dynarray xValLastLineDrawn; //bitchcall
				Dynarray yValLastLineDrawn;	//bitchcall	
				{
					next += 1000;
					tickingClock = true;


					double xPos = (hOfSlowLine + i);
					double yPos = (kOfSlowLine + i);
					gfx.PutPixel(xPos, yPos, 255, 255, 255);
					tempX = h;
					tempY = k;
					int rise = yPos - k;
					int run = xPos - h;
					double slope = rise / run;
					


					
					double tempcompx1, tempcompx2, tempcompx3 = 0;
					double tempcompy1, tempcompy2, tempcompy3 = 0;
					double magright, magabove, magtopright;
					tempX = h;
					tempY = k;
					notabove, notright, nottopright = false;
					int z = 0;
					while(tempX < xPos || tempY < yPos) {
						z++;
						////this while loop runs for until the x and y value of our line meet our iteration point 
						//it will draw #### number of pixels. any use of tempcomp is assessing which of the three pixels we should use
						//based on which one has a lesser magnitude to our desired point, (xpos,ypos)
						//any use of tempx tempy is line placement coordinates for moving line, as it is a temporary line.
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
						tempcompx1, tempcompx2, tempcompx3 = 0;
						tempcompy1, tempcompy2, tempcompy3 = 0;
						
						if (above == true || right == true) {
							
							tempcompx1 = 1  + tempX;	//x value to the right
							tempcompx2 = 0  + tempX;	//x value above us								             			2727
							tempcompx3 = 1 + tempX;		//x value diagonally top right				       11122            			2626
							tempcompy1 = 0 + tempY;		//y value to the right				               11221                 2525
							tempcompy2 = -1 + tempY;	//y value above us					               12211               
							tempcompy3 = -1 + tempY;	//y value diagonally to the right	 1 1 1 1       22111                    

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
							//magtopright = sqrt(powxy3);
							magtopright = 99999999;
						
							if (magright < magabove && magright < magtopright) {
								tempX = tempcompx1;
								tempY = tempcompy1;
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								xValLastLineDrawn.add(tempX);
								yValLastLineDrawn.add(tempY);
								nottopright = false;
								notright = false;
								notabove = false;

								
							}                                       
							else { notright = true; }
							if (magabove < magright && magabove < magtopright) {
								tempX = tempcompx2;
								tempY = tempcompy2;
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								xValLastLineDrawn.add(tempX);
								yValLastLineDrawn.add(tempY);
								nottopright = false;
								notright = false;
								notabove = false;
							
							}
							else { notabove = true; }
							//temporarily disabled the if below this line.
							if (magtopright < magright && magtopright < magabove) {
								tempX = tempcompx3;
								tempY = tempcompy3;
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								xValLastLineDrawn.add(tempX);
								yValLastLineDrawn.add(tempY);
								nottopright = false;
								notright = false;
								notabove = false;
								
							}
							//disabled end.
							else {
								
							}
							if (magright == magabove) {
								tempX = tempcompx3;
								tempY = tempcompy3;
								gfx.PutPixel(tempX, tempY, 255, 255, 255);
								xValLastLineDrawn.add(tempX);
								yValLastLineDrawn.add(tempY);
								nottopright = false;
								notright = false;
								notabove = false;

							}
							else {
								nottopright = true;
							}
								if (notabove == true && nottopright == true && notright == true) {
									breakpoint = true;
									notabove = false;
									notright = false;
									nottopright = false;

									//	tempX = tempcompx3;
									//	tempY = tempcompy3;
									//	gfx.PutPixel(tempX, tempY, 255, 255, 255);
									//array thoughts.
									//if(tempX tempy != xpos ypos || < < xpos ypos){
									/*
									
									array 
									
									
									
									
									
									
									
									
									
									
									
									
									
									*/
								}
							}
							}
							//while end. line is drawn.
						}
					}
				}
			}


		


	


