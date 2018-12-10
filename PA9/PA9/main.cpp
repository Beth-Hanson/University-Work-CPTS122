/*Programmer: Elisabeth Hanson, Perla Murua, Brittany Hurst
Class: CptS 122, Fall 2018 Lab 5
Programming Assignment: Project 9
File: main.cpp
Date: 12/1/18
Description: */

#include "Menu.h"
#include "Obstacle.h"
#include "Background.h"
#include "Parachuter.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 800), "");
	Background background; //PM
	Parachuter parachuter; //PM
	//BH 
	Obstacle o1(sf::Color::Blue, *(new sf::Vector2f(OBSTACLE_LENG, OBSTACLE_HEIG)), *(new sf::Vector2f(XCOORD_1, window.getSize().y - OBSTACLE_HEIG + 1)));
	Obstacle o2(sf::Color::Blue, *(new sf::Vector2f(OBSTACLE_LENG, OBSTACLE_HEIG)), *(new sf::Vector2f(XCOORD_1 + OBSTACLE_LENG + 50, (window.getSize().y + (window.getSize().y * 0.5)) - OBSTACLE_HEIG + 1)));
	Obstacle o3(sf::Color::Blue, *(new sf::Vector2f(OBSTACLE_LENG, OBSTACLE_HEIG)), *(new sf::Vector2f(XCOORD_1 + (OBSTACLE_LENG * 2) + 50, (window.getSize().y * 2) - OBSTACLE_HEIG + 1)));
	Obstacle o4(sf::Color::Blue, *(new sf::Vector2f(OBSTACLE_LENG, OBSTACLE_HEIG)), *(new sf::Vector2f(XCOORD_1 + (OBSTACLE_LENG * 3) + 50, (window.getSize().y * 2.5) - OBSTACLE_HEIG + 1)));

	sf::Vector2f pos1 = sf::Vector2f(XCOORD_1, window.getSize().y - OBSTACLE_HEIG + 1);
	sf::Vector2f pos2 = sf::Vector2f(XCOORD_1 + OBSTACLE_LENG + 50, (window.getSize().y + (window.getSize().y * 0.5)) - OBSTACLE_HEIG + 1);
	sf::Vector2f pos3 = sf::Vector2f(XCOORD_1 + (OBSTACLE_LENG * 2) + 50, (window.getSize().y * 2) - OBSTACLE_HEIG + 1);
	sf::Vector2f pos4 = sf::Vector2f(XCOORD_1 + (OBSTACLE_LENG * 3) + 50, (window.getSize().y * 2.5) - OBSTACLE_HEIG + 1);
	
	Menu menu; 
	bool playSelect = false, gameOver = false;

	while (window.isOpen()) {
		//sf::Color color = sf::Color::Cyan;
		sf::Event userEvent;
		while (window.pollEvent(userEvent)) {
			if (userEvent.type == sf::Event::Closed) {
				window.close();
			} 
			if (userEvent.mouseButton.x > 300 && userEvent.mouseButton.x < 500 && userEvent.mouseButton.y > 300 && userEvent.mouseButton.y < 400) {
				//menu.setPlayColor(color);
				if (sf::Event::MouseButtonPressed) {
					playSelect = true;
				}
			}
			else {
				/*color = sf::Color::White;
				menu.setPlayColor(color);*/
			}
			if (userEvent.mouseButton.x > 300 && userEvent.mouseButton.x < 400 && userEvent.mouseButton.y > 650 && userEvent.mouseButton.y < 700) {
				//color = sf::Color::Cyan;
				//menu.setExitColor(color);
				if (sf::Event::MouseButtonPressed) {
					window.close();
				}
			}
			if (userEvent.type == sf::Event::KeyPressed)
			{
						//if (sf::Event::key )
				if (userEvent.key.code == sf::Keyboard::Left)
				{
					parachuter.moveLeft(); //EH

				}
				if (userEvent.key.code == sf::Keyboard::Right)
				{
					parachuter.moveRight(); //EH

				}
			}
		
			if (userEvent.type == sf::Keyboard::Escape) {
				playSelect = false;
				window.close();
			}
		}
		if (!playSelect) {
			window.clear();
			//menu.draw(window); 
			window.draw(menu);
			window.display();
		}
		if (playSelect) {
			window.clear();
			window.draw(background); //PM
			window.draw(parachuter);//PM
			window.draw(o1); //BH
			window.draw(o2); //BH
			window.draw(o3); 
			window.draw(o4); 
			window.display();
			if (o1.getPosition().y < 1) {
				o1.setPosition(pos1);
			}
			if (o2.getPosition().y < 1) {
				o2.setPosition(pos2);
			}
			if (o3.getPosition().y < 1) {
				o3.setPosition(pos3);
			}
			if (o4.getPosition().y < 1) {
				o4.setPosition(pos4);
			}
			if (!gameOver) {
				o1.move(0, Y_MOVE); //x doesn't change, y moves the defined amount
				o2.move(0, Y_MOVE);
				o3.move(0, Y_MOVE);
				o4.move(0, Y_MOVE);
			}
			if (parachuter.getGlobal().intersects(o1.getGlobalBounds()) || parachuter.getGlobal().intersects(o2.getGlobalBounds()) 
				|| parachuter.getGlobal().intersects(o3.getGlobalBounds()) || parachuter.getGlobal().intersects(o4.getGlobalBounds())) {
				gameOver = true;
				playSelect = false;
			}
			if (gameOver) {
				menu.setGameOverColor(sf::Color::Red);
				menu.setPlayColor(sf::Color::Black);
			}
		}
	}
	
	return 0;
}