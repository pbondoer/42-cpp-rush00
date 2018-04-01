/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:55:54 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include "Enemy.hpp"
#include "IEntity.hpp"

Enemy::Enemy(char type) : _type(type)
{
	this->_x = std::rand() % COLS;
	this->_y = 0;
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

char Enemy::getType(void)
{
	return this->_type;
}

void Enemy::update(void)
{
	this->_counter++;

	if (this->_counter >= 50)
	{
		this->_y = this->_y + 1;
		this->_counter = 0;
	}
}

void Enemy::render(void)
{
	move(this->_y, this->_x);
	addch(this->getType());
}
