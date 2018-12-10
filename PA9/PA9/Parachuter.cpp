/*Programmer: Perla Murua
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Parachuter.h
Date: 12/1/18
Description: */

#include"Parachuter.h"

Parachuter::Parachuter()
{
	if (!mParachuterImage.loadFromFile("Parachuter.png"))
			{
				cout << "Couldn't load the parachuter file" << endl;
			}
			mParachuterImage.setSmooth(true);
			mParachuter.setTexture(mParachuterImage);
			mParachuter.setPosition(sf::Vector2f(500, 0));
			mParachuter.setScale(0.60f, 0.65f);
}

Parachuter::Parachuter(const sf::Vector2f &dimensions, const sf::Vector2f &pos)
{
	//this->setPosition(pos);

	if (!mParachuterImage.loadFromFile("Parachuter.png"))
	{
		cout << "Couldn't load the parachuter file" << endl;
	}
	mParachuterImage.setSmooth(true);
	mParachuter.setTexture(mParachuterImage);
	mParachuter.setPosition(sf::Vector2f(200, 0));
	mParachuter.setScale(0.75f, 0.75f);
}

Parachuter::~Parachuter()
{
}

//EH
void Parachuter::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(mParachuter, states);
}

//EH
void Parachuter::moveRight() {
	mParachuter.move(2.5, 0);
}

//EH
void Parachuter::moveLeft() {
	mParachuter.move(-2.5, 0);

}

//EH
sf::FloatRect Parachuter::getGlobal() {
	return this->mParachuter.getGlobalBounds();
}
