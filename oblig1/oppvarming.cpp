#include<iostream>
#include<string>
#include <bitset>
#include <sstream>

using namespace std;

long long msg1{28539401679696455};
int msg2[]{1918986818,1998611822,1684829551,
	544483182,1701538156,1768453152,8563};
int encrypted[]{1498105673, 1227249735, 1498829639,
	1196119078, 1314530904, 1197024843, 5853000};


int main(){
int i = 0;
int x = 7;

string s1 = "";
string s2 = "";
string s3 = "";

int offset;

char byteArray[8]; //For storing the hidden msg1
char byteArray2[7][4];	//For temporary storing msg2 and msg3 as bytearrays

//Converting msg1 to a byteArray, long long = 64 bit = 8 bytes
while(x >= 0 && i <= 64){
	byteArray[x] = (char)((msg1 >> i)&0xFF); 	
	i+=8;
	x--;
}
//adding the message hidden in msg1 byteArray to string s1
for(i = 7; i >= 0; i--){
	s1 += byteArray[i];
}

//Message 2 to string s2, int consists of 4 bytes
for(i = 0; i <= 6; i++){
	byteArray2[i][0] = (char)((msg2[i])&0xFF);
	byteArray2[i][1] = (char)((msg2[i]>>8)&0xFF);
	byteArray2[i][2] = (char)((msg2[i]>>16)&0xFF);
	byteArray2[i][3] = (char)((msg2[i]>>24)&0xFF);
	
	//addng the message hidden in msg2's byteArray to string s2
	for(int t = 0; t < 4; t++){
		s2+=byteArray2[i][t];
	}
}

//encrypted to byte array
for(i = 0; i <= 6; i++){
        byteArray2[i][0] = (char)((encrypted[i])&0xFF);
        byteArray2[i][1] = (char)((encrypted[i]>>8)&0xFF);
        byteArray2[i][2] = (char)((encrypted[i]>>16)&0xFF);
        byteArray2[i][3] = (char)((encrypted[i]>>24)&0xFF);
}

//loops through the encrypted bytearray and shifting with offset
offset = -6;
for(i=0; i<=6; i++){
	for(x = 0; x < 4; x++){
		byteArray2[i][x]+=offset;
		s3+=byteArray2[i][x];
	}
}

// Print out the messages in human-readable form!
cout << "Message 1: " << s1 << endl;
cout << "Message 2: " << s2 << endl;
cout << "Decrypted: " << s3 << endl;
}
