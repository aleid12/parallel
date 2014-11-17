extern "C" {
#include "bspedupack.h"
} 
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

const int dim = 2;
const int particles =10;
double sigma;
double epsilon;
double timestep;

double position[particles][2*dim]; //dim positiecoordinaten, dim snelheidscoordinaten



int startingcondition(){

//iets met een statistische logische verdeling van posities en snelheden

for(int i = 0; i < particles; i++){
	for(int j = 0; j < dim; j++){
		position[i][j] = (double)rand()/(double)RAND_MAX;
		position[i][j+dim] = 0;  //snelheden op 0 zetten	
	}
}
return 0;

}

void printposition(int t)
{
	ofstream outfile;
	stringstream ss;
	ss << "Positions/Position_" << t << ".txt";
	const char* filename = ss.str().c_str();
	outfile.open(filename);
	for(int i = 0; i< particles;i++)
	{
		for(int j=0;j<2*dim;j++)
		{
			outfile << position[i][j] << " ";
		}
		outfile << endl;
	}
}

int main(int argc, char **argv){


srand(time(NULL));

startingcondition();


printposition(0);

//cout << velocity[3][1] << endl;
cout <<position[3][1] << " " << rand() << endl;




}




