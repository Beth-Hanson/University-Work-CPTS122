/*Programmer: Elisabeth Hanson
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Menu.h
Date: 12/1/18
Description: */

#include "Menu.h"

Menu::Menu() {
	int x = 1000, y = 1000;
	this->font.loadFromFile("arial.ttf");
	this->gameOver.setString("Game Over");
	this->gameOver.setFont(font);
	this->gameOver.setColor(sf::Color::Black);
	this->gameOver.setPosition(sf::Vector2f((x / 2) - 150, y / 3 * 0.5));
	this->play.setString("Play Game");
	this->play.setFont(font);
	this->play.setColor(sf::Color::White);
	this->play.setPosition(sf::Vector2f((x / 2)-150, y / 3));
	this->exit.setFont(font);
	this->exit.setString("Exit");
	this->exit.setColor(sf::Color::White);
	this->exit.setPosition(sf::Vector2f((x / 2)-150, y / 3 * 2));
}

Menu::~Menu() {

}

void Menu::draw(sf::RenderTarget & window, sf::RenderStates state) const {
	window.draw(gameOver, state);
	window.draw(play, state);
	window.draw(exit, state);
}



void Menu::setPlayColor(sf::Color color) {
	this->play.setColor(color);
}

void Menu::setExitColor(sf::Color color) {
	this->exit.setColor(color);
}

void Menu::setGameOverColor(sf::Color color) {
	this->gameOver.setColor(color);
}
