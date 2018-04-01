/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:07:21 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ncurses.h>
#include "Enemy.hpp"

Enemy::Enemy(std::string type) : _type(type)
{
	this->_maxX = LINES - 1;
	this->_type = type;
	this->_x = std::rand() % COLS;
	this->_y = 0;
	this->_counter = 0;
}
Enemy::Enemy(Enemy const & obj)
{
	*this = obj;
}
Enemy::~Enemy(void) {}

Enemy& Enemy::operator=(Enemy const &)
{
	return *this;
}

std::string Enemy::getType(void)
{
	return this->_type;
}

void Enemy::update(void)
{
	this->_counter++;

	if (this->_y < this->_maxX)
	{
		if (this->_counter >= 100)
		{
			this->_y = this->_y + 1;
			this->_counter = 0;
		}
	}
}

void Enemy::render(void)
{
	move(this->_y, this->_x);
	addstr(this->getType().c_str());
}

int Enemy::getY(void)
{
	return this->_y;
}
void Enemy::setY(int y)
{
	this->_y = y;
}
