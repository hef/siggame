
/*****************************************************************************/
//header guards to prevent multiple compilation of definitions
#ifndef DOG_H
#define DOG_H

// Declaration of class Dog
/* filename: Dog.h			*/
#include <iostream>
//#include <stdio.h>
using namespace std;		//only if the class is declared in a separate file

class Dog{
	
	//private members
	private:
		//private data members
		float dogHeight_M,
			  dogWeight;
		  
		char 	dogID [16];
		char	*startDog;

	
	//public members
	public:
		//public data


		//Default constructor:
		Dog(){
			dogHeight_M = 0.0;
			dogWeight = 0.0;
			cout<<"From default constructor Dog's height is: "
			<<dogHeight_M<<endl;
			//set each element of the char array to '-'
			for (int i = 0; i< 15; i++){
				dogID [i] = '-';
			}
			dogID[15] = '\0';	
			for (int i = 0; i<=15; i++)
				cout<<dogID[i];
			cout<<"default constructor finished"<<endl;
		}

		//Parameterized constructor:
		Dog(float initDogHeight_M, float initDogWeight){
			dogHeight_M = initDogHeight_M;
			dogWeight = initDogWeight;
			cout<<"From the constructor, height and weight"
				<<dogHeight_M<<"  "<<dogWeight<<endl;

		}
		
		Dog(float initDogHeight_M, float initDogWeight, char newDogID[]){
			dogHeight_M = initDogHeight_M;
			dogWeight = initDogWeight;
			for (int i = 0; i <= 15; i++){
				dogID[i] = newDogID[i];
			}
			dogID[16] = '\0';
			startDog = &newDogID[0];
			cout<<"From triple constructor dog's tag is: ";
			char * transDog = startDog;
			while(*(transDog) != '\0'){
				cout<<*(transDog);
				(transDog = transDog + 1);
			}	
			cout<<endl;	
					

		}

		//copy constructor

		//accessor methods
		float Dog::getDogHeight_M(){
			return dogHeight_M;
		}

		float Dog::getDogWeight(){
			return dogWeight;
		}

	
	/*	void Dog::getDogName(){
			for (int i = 0; i <= 15; i++){
				cout<<dogID[i];
			}	
			cout<<endl;
		
		
		}*/
		
		void  Dog::getDogName(){
			startDog = &dogID[0];
			char *transDog = startDog;
			cout<<"Dog's tag is: ";
			while (*transDog != '\0'){
				cout<<*transDog;
				transDog  += 1;					
			}
			cout<<endl;
			
		}
		
		//mutator methods
		void Dog::setDogHeight_M(float newDogHeight_M){
			dogHeight_M = newDogHeight_M;
		}

		void Dog::setDogWeight(float newDogWeight){
			dogWeight = newDogWeight;	
		}


};

#endif /* DOG_H */  //end of compiler directive ndef

