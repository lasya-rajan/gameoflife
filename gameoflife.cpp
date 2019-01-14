/* 

Game of Life Simulation
COMPLETED 1/14/2019
L. Rajan

*/ 



#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

const int GRID_SIZE = 10; 

const int GENERATION_LIMIT = 50; 

const int LONG_SLEEP = 5000;

const int SLEEP_TIME = 1;


int main()
{
	char grid[GRID_SIZE][GRID_SIZE] = {
							{'X','X','X','X','X','X','X','X','X','X'}, //1
							{'X','X','X','X','X','X','X','X','X','X'}, //2
							{'.','.','.','X','X','X','.','X','.','.'}, //3
							{'X','X','X','X','.','X','.','X','X','.'}, //4
							{'.','X','X','X','.','X','X','X','X','.'}, //5 
							{'X','X','X','X','X','.','.','.','X','.'}, //6
							{'X','.','X','.','X','.','X','X','X','X'}, //7
							{'X','X','X','.','.','.','.','X','X','X'}, //8
							{'.','X','X','X','X','.','X','.','X','X'}, //9
							{'X','X','X','X','.','.','.','.','.','.'}, //10
																	}; 


													

	int row = 0;
	int col = 0;
	int liveNeighbors = 0;
	int generationCount = 0;  
	bool alive; 

	


	cout << "Welcome to Conway's Game of Life." << endl; 

	cout << "Initial grid state:" << endl;
	cout << endl;

	for (row = 0; row < GRID_SIZE; row++)
	{
	        for (col = 0; col < GRID_SIZE; col++)
	        {
	            cout<<grid[row][col]<<"  ";
	        }

 		cout<<endl;
	}

	cout << endl;
	cout << endl;

	cout << "Beginning simulation..." << endl; 

	Sleep(LONG_SLEEP);

	system("cls");  ////////////////////////////////////////////CLEAR SCREEN 

	while (generationCount <= GENERATION_LIMIT)
	{
		
		//alive state is X, dead state is . 

		for(row = 0; row < GRID_SIZE; row++)           //iterate through the grid 
			for(col = 0; col < GRID_SIZE; col++)
			{

				// reset counter/bool 

				liveNeighbors = 0;
				alive = false; 

				//all the 8 neighbor conditions 

				if (grid[row-1][col-1] == 'X')
					liveNeighbors++; 

				if (grid[row-1][col] == 'X')
					liveNeighbors++;

				if (grid[row-1][col+1] == 'X')
					liveNeighbors++;

				if (grid[row][col-1] == 'X')
					liveNeighbors++;

				if (grid[row][col+1] == 'X')
					liveNeighbors++;

				if (grid[row+1][col-1] == 'X')
					liveNeighbors++;

				if (grid[row+1][col] == 'X')
					liveNeighbors++;

				if (grid[row+1][col+1] == 'X')
					liveNeighbors++;

				//determine local state before this generation

				if (grid[row][col] == 'X')
					alive = true; 
				else
					alive = false; 

				//determine local state after this generation 

				if (alive)
				{
					if (liveNeighbors < 2)
						alive = false;
					if ( (liveNeighbors == 2) || (liveNeighbors == 3))
						alive = true;
					if (liveNeighbors > 3)
						alive = false; 
				}
				else //dead
				{
					if (liveNeighbors > 3)
						alive = true; 
				}

				//set outcome in grid 

				if(alive)
					grid[row][col] = 'X';
				else
					grid[row][col] = '.';


			} // end of iterative for loop 

			generationCount++;

			//print grid 
				

			for (row = 0; row < GRID_SIZE; row++)
			{
		        for (col = 0; col < GRID_SIZE; col++)
		        {
		            cout<<grid[row][col]<<"  ";
		        }

	 		cout<<endl;
			}

			Sleep(1000); //delays screen for one second to allow viewing 

			system("cls"); /////////////////////////////////////////////////CLEAR SCREEN




		} // end of while generationLimit loop



cout << "Thank you for watching the Game of Life." << endl; 


return 0;

} // end int main 