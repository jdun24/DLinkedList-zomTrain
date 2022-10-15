#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <cstdlib>	//required to rand()
#include <ctime>
#include <string>
using namespace std;
#pragma once

class Zombie
{
	private:
	char color;

	public:
	Zombie(char c){
		color = c;
	}
	Zombie(){
		int num = rand() % 5; //6 possibilities
		switch(num){
				case 0:
					color = 'r';
				break;
				case 1:
					color = 'y';
				break;
				case 2:
					color = 'g';
				break;
				case 3:
					color = 'b';
				break;
				case 4:
					color = 'm';
				break;
				case 5:
					color = 'c';
				break;
		}
	}
	
	bool operator ==(Zombie &z){
        if(color == z.getColor()){
            return true;
        }else{
            return false;
        }
    }
	
	char getColor();
	void setColor(char str);
};

#endif