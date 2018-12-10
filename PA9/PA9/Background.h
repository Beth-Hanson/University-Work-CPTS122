/*Programmer: Perla Murua
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Background.h
Date: 12/1/18
Description: */

#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using std::cout;
using std::endl;


class Background :public sf::Drawable
{
public:
	Background();
	~Background();

	//std::size_t sf::Shape::getPointCount()	const;
	//sf::Vector2f sf::Shape::getPoint(std::size_t index)	const;

protected:

	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	sf::Texture mBackgroundImage;
	sf::Sprite mBackground; 

	sf::Music music;

};
