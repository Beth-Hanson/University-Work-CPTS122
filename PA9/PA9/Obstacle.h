/*Programmer: Brittany Hurst
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Obstacle.h
Date: 12/1/18
Description: */

#pragma once

#include <SFML/Graphics.hpp>
//Location of Macros changed by EH
#define OBSTACLE_LENG 200
#define OBSTACLE_HEIG 20

#define XCOORD_1 50 //this is just a beginning variable. might need to make each obstacle have it's own constant X member
#define SPEED 200.0f
#define Y_MOVE -.05 //y moves upward in a negative direction

class Obstacle : public sf::RectangleShape
{

public:
	Obstacle(){}
	Obstacle(const sf::Color &newColor, const sf::Vector2f &dimensions,
		const sf::Vector2f &pos) : sf::RectangleShape(dimensions)
	{
		this->setFillColor(newColor);
		this->setPosition(pos);

	}

private:
	//int xPos;
};