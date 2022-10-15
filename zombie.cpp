#include "zombie.h"
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

char Zombie::getColor(){
	return color;
}

void Zombie::setColor(char str){
	color = str;
}