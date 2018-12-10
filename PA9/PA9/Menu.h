/*Programmer: Elisabeth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Menu.h
Date: 12/1/18
Description: */

#pragma once
#pragma warning(disable: 4996)
#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;
using std::endl;

class Menu : public sf::Drawable {
public:
	Menu();
	//Menu(std::string text, std::string font);
	~Menu();
	//void draw(sf::RenderWindow &window);
	void draw(sf::RenderTarget &window, sf::RenderStates state) const;
	//void drawGameOver(sf::RenderWindow &window);
	void setPlayColor(sf::Color color);
	void setExitColor(sf::Color color);
	void setGameOverColor(sf::Color color);

private:
	sf::Font font;
	sf::Text play;
	sf::Text exit;
	sf::Text gameOver;

};