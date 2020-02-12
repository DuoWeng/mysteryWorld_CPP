#include <iostream>
#include <string.h>
using namespace std;
char mysteryWorld[] = "hello";


int main(){

    char guessess[] = "*****";

    char missed[10] = "";

    int times;

    bool gotIt = false;

    int len = strlen(mysteryWorld);
    //information for user
    cout << "Please guess a four letters Word. You have six chances.\n";

    for(times = 6;times > 0 && !gotIt;times--){
	//to show missed letter
	if(strlen(missed)>0){
 	cout <<"Misses: "<< missed<<endl;}
	//ask user to try to guess and read a character.
	cout <<"The word is: "<<guessess<<endl;
	cout << "Please try to guess: ";
	char chr;
	cin >> chr;
	chr = (chr <= 'Z' && chr >= 'A')? chr+32:chr;
 	//each time a letter in mysteryWorld is guessed
	if(strchr(mysteryWorld,chr) != NULL){
	  int i;
	  //replace the corresponding "*" in guessed with that letter
	  for(i = 0; i <= len;i++){
	     if(mysteryWorld[i] == chr){guessess[i]= chr;}}
	  //if letters in guessess array are the same with mysteryWorld,user win and stop loop.
          if(strcmp(guessess,mysteryWorld) == 0){gotIt = true;}

        }else{//store missed letter 
	  int le = strlen(missed);missed[le] = chr;missed[le+1] = '\0';}
     }

     if(gotIt == true){
	cout << "You got it! The Word is " << mysteryWorld<<endl;
     }else{
	cout << "The computer win!Play it again."<<endl;}

    return 0;
}
