#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "Texture.h"
#include "Circles.h"
#include <windows.h>
#include <stdio.h>
#include <string>
#include "Caption.h"
#include <list>
#include "Cat.h"
#include "Macros.h"
#include <iosfwd>


using std::cin;
using std::cout;
using std::endl;





class Board {
public:
	Board();

	void drawWindow(sf::RenderWindow& window);
	bool mouseClick(sf::Event evnt, sf::RenderWindow& window);
	bool getwinlevel()
	{
		return m_newlevel;
	}
	bool getGameover()
	{
		return m_gameover;
	}
	void clearBoard(bool win);


private:

	
	void CatMove(std::pair<int, int>loccir, sf::RenderWindow& window);
	void nextLevel();
	void moveRandomcat(std::pair<int, int>, sf::RenderWindow& window);
	void wingamecheck();
	void drawSquares();
	void changeCatLoc(sf::Vector2f cat, std::pair<int, int>location, sf::RenderWindow& window);
	void setArraySurround();
	int ShortestDistance(std::pair< int, int> s,
		std::pair< int, int> dest, std::vector<std::pair< int, int>>& path);
	bool BFS(std::pair< int, int>src, std::pair< int, int> dest,
		std::vector<std::vector< std::pair< int, int>>>& pred, std::vector< std::vector<int>>& dist);
	void setBlackCircles();


	
	
	Cat m_Cat;
	std::vector < std::vector<std::unique_ptr<Circles>>>m_circles;
	std::vector<std::pair<int, int>> m_array;
	std::vector < std::pair<int, int>>m_blackcircle;


	int index_of_cat;
	int m_xStart;
	int m_yStart;
	int m_blackCircles;
	bool m_newlevel;
	bool m_gameover;

	
};

