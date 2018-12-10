/*Programmer: Perla Murua
Class: CptS 122, Fall 2018
Programming Assignment: Project 9
File: Background.cpp
Date: 12/1/18
Description: */


#include "Background.h"
#include"Parachuter.h"

using std::cout;
using std::endl;

//int main()
//{
//	Background background;
//	Parachuter parachuter;
//
//
//	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");
//	//window.setVerticalSyncEnabled(true);
//	//window.setKeyRepeatEnabled(false);
//
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//
//			if (event.type == sf::Event::KeyPressed)
//			{
//				//if (sf::Event::key )
//				if (event.key.code == sf::Keyboard::Left)
//				{
//					parachuter.move(1, 0);
//				}
//				if (event.key.code == sf::Keyboard::Right)
//				{
//					parachuter.move(1, 0);
//				}
//			}
//		}
//
//		window.clear();
//		window.draw(background);
//		window.draw(parachuter);
//		window.display();
//
//
//
//	}
//
//	return 0;
//}


Background::Background()
{

	mBackgroundImage.loadFromFile("sky.jpg");
	mBackground.setTexture(mBackgroundImage);
	mBackground.setScale(0.85f, 0.80f);

	//if (!mParachuterImage.loadFromFile("Parachuter.png"))
	//{
	//	cout << "Couldn't load the parachuter file" << endl;
	//}
	//mParachuterImage.setSmooth(true);
	//mParachuter.setTexture(mParachuterImage);
	//mParachuter.setPosition(sf::Vector2f(100, 0));
	//mParachuter.setScale(0.10f, 0.25f);


	if (!music.openFromFile("Tetris.ogg"))
	{
		std::cout << "ERROR" << std::endl;
	}

	music.play();// plays the music //https://www.sfml-dev.org/documentation/2.4.2/classsf_1_1SoundStream.php#a16cc6a0404b32e42c4dce184bb94d0f4
	music.setPitch(1);// increase the pitch
	music.setVolume(70);// reduce the volume	


}

Background::~Background()
{
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(mBackground, states);
	//target.draw(mParachuter, states);

}

//std::size_t sf::Shape::getPointCount()	const
//{
//	std::size_t variable_size;
//	variable_size = 0;
//	return variable_size;
//}
//sf::Vector2f sf::Shape::getPoint(std::size_t index)	const
//{
//	sf::Vector2f variable(0, 0);
//	return variable;
//}

//using std::cout;
//using std::endl;

//int main()
//{
//	Background background;
//
//	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//
//	while (window.isOpen())
//	{
//
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//
//		/*	window.clear();
//			window.draw(shape);
//			window.display();*/
//
//		window.clear();		window.draw(background);
//		window.display();
//
//
//
//	}
//
//	return 0;
//}

//
//Background::Background()
//{
//
//	mBackgroundImage.loadFromFile("sky.jpg");
//	mBackground.setTexture(mBackgroundImage);
//	mBackground.setScale(0.75f, 0.75f);
//
//	if (!mParachuterImage.loadFromFile("Parachuter.png"))
//	{
//		cout << "Couldn't load the parachuter file" << endl;
//	}
//	mParachuterImage.setSmooth(true);
//	mParachuter.setTexture(mParachuterImage);
//	mParachuter.setPosition(sf::Vector2f(100, 0));
//	mParachuter.setScale(0.60f, 0.65f);
//
//
//	if (!music.openFromFile("Tetris.ogg"))
//	{
//		std::cout << "ERROR" << std::endl;
//	}
//
//	//music.play();// plays the music //https://www.sfml-dev.org/documentation/2.4.2/classsf_1_1SoundStream.php#a16cc6a0404b32e42c4dce184bb94d0f4
//	music.setPitch(1);// increase the pitch
//	music.setVolume(70);// reduce the volume	
//
//
//}
//
//
//Background::~Background()
//{
//}
//
//void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
//{
//	target.draw(mBackground, states);
//	target.draw(mParachuter, states);
//
//}
