#include <iostream>
#include <cstdlib>

using namespace std;

//number of roulette wheel spins
int n = 10000000;

//temp variable counts spins
unsigned int count = 0;

unsigned int color[2];

unsigned int seq = 1; //number of times the same color is hit in sequence

int seqs[25];


int rnd = rand()%2;; // holds current spin color, 0 = red, 1 is black
int preRnd = -1;



//spins the wheel
void spinWheel(){
	while(count < n){
		count++;
		
		preRnd = rnd;
			
		color[rnd]++;
		rnd = rand()%2;
		if(rnd == preRnd)
			seq++;
		else{
			seqs[seq]++;
			seq = 1;
		}		
	}
}
int main(){
	srand(time(NULL)); //setting the seed for the random number generator to clock
	cout << "Simulating, " << n <<  " rounds of roulette" << endl; 
	spinWheel();
	
	cout << "\nR E S U L T S: \n" << endl;
	for(int i = 1; i < (sizeof seqs/ sizeof *seqs); i++)
	{
		if(seqs[i] !=  0)
			cout << i << "\t" << seqs[i] << endl;
		
	}
	return 0;
}
