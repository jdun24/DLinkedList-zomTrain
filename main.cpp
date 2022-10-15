/* 
		Author: Joseph Dunagan
		Date: 07/01/2022
		Description: A silly zombie conga line
*/ 
#include <iostream>
#include <stdio.h>
#include <cstdlib>	//required to rand()
#include <ctime>
#include <string>

#include "dlist.h"
#include "zombie.h"

//ZOMBIE CAN BE: Red, Yellow, Green, Blue, Magenta or Cyan
dlist<Zombie> l;	//object from class doubly list

void engine(Zombie z){
	cout << "Engine Called!__________\n";
	l.addToFront(z);
}

void caboose(Zombie z){
	cout << "Caboose Called!__________\n";
	l.addToEnd(z);
}

void jumpInTheLine(Zombie z, int x){
	cout << "jumpInTheLine Called!__________\n";
	if(x == 0){	//Encountered a problem where this function wouldn't work only when index was 0, did this due to time constraints
		l.addToFront(z);
	}else{
		l.addAtIndex(z,x);
	}
}

void everyoneOut(Zombie z){
	cout << "EveryoneOut Called!__________\n";
	l.removeAllOf(z);
}

void urdone(Zombie z){
	cout << "You're Done Called!__________\n";
	l.removeTheFirst(z.getColor());
}

void brains(Zombie z){
	cout << "Brains! Called!__________\n";
	if(z.getColor() == 'r'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('r')));
	}else if(z.getColor() == 'y'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('y')));
	}else if(z.getColor() == 'g'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('g')));
	}else if(z.getColor() == 'b'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('b')));
	}else if(z.getColor() == 'm'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('m')));
	}else if(z.getColor() == 'c'){
		l.addToFront(z);
		l.addAtIndex(z, (l.length() / 2));
		l.addToEnd(*(new Zombie('c')));
	}
}

void rainbowBrains(Zombie z){
	cout << "RainbowBRAINS Called!__________\n";
	l.addToFront(z);
	l.addToEnd(*(new Zombie('r')));
	l.addToEnd(*(new Zombie('y')));
	l.addToEnd(*(new Zombie('g')));
	l.addToEnd(*(new Zombie('b')));
	l.addToEnd(*(new Zombie('m')));
	l.addToEnd(*(new Zombie('c')));
}

void makingNewFriends(Zombie z){
	cout << "makingNewFriends Called!__________\n";

	int chance = rand() % 99;	//100 options
	if(chance <= 49 && l.Find(z) != NULL){
		l.addAfter(l.Find(z),z);
	}else if(chance > 49 && l.Find(z) != NULL){
		l.addBefore(l.Find(z),z);
	}else if(l.Find(z) == NULL){
		l.addAtIndex(z,(l.length() - 1));
	}
}

void unstableZom(Zombie z){
	//DID MOT HAVE TIME TO FINISH THIS FUNCTION
	/*
	cout << "UnstableZombie Called!__________\n";
	int index = indexOf(z);
	bool red = false, yellow = false, green = false, blue = false, magenta = false, cyan = false;
	char color;
	l.deleteNode(l.getHead(), l.Find(z));
	for(int i = 0;i < l.length(); i++){
		color = l.retrieve(i).getColor();
		if(red == false && color == 'r'){
			addAfter(l.Find())
		}else if(yellow == false && color == 'y'){
			
		}else if(green == false && color == 'g'){
			
		}else if(blue == false && color == 'b'){
			
		}else if(magenta == false && color == 'm'){
			
		}else if(cyan == false && color == 'c'){
			
		}
	}
	*/
}

int main(){

	srand(time(0));
 	int num = 0;
	int index = 0;
	//Initial rainbow brain call
	cout<<"__________";
	rainbowBrains(*(new Zombie));
	l.printList();
	cout << "\n";
	
	for(int round = 0; round < 16; round++){
		num = rand() % 8;
		cout << "Round: " << round << "    __________";
		if(round % 5 == 0){
			l.removeFromFront();
			l.removeFromEnd();
		}
		switch(num){
			case 0:
				engine(*(new Zombie));
			break;
			case 1:
				caboose(*(new Zombie));
			break;
			case 2:
				index = (rand() % (l.length()));	//Picks an index thats within the size of the list
				jumpInTheLine(*(new Zombie), index);
			break;
			case 3:
				everyoneOut(*(new Zombie));
			break;
			case 4:
				urdone(*(new Zombie));
			break;
			case 5:
				brains(*(new Zombie));
			break;
			case 6:
				rainbowBrains(*(new Zombie));
			break;
			case 7:
				makingNewFriends(*(new Zombie));
			break;
			case 8:
				unstableZom(*(new Zombie));
			break;
		}
		l.printList();
		cout << "\n";
	}

 	return 0;
} 
	
