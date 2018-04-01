/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:29:01 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include <typeinfo>
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "IEntity.hpp"

char Enemy::_types[6] = {
	'@', '#', '!', 'V', 'X', 'O'
};

Enemy::Enemy()
{
	this->_speed = std::rand() % 20 + 40;
	this->_type = Enemy::_types[std::rand() % 6];
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

	if (this->_counter >= _speed)
	{
		this->_y = this->_y + 1;
		this->_counter = 0;

		if (this->_y >= LINES)
			this->_remove = true;
	}
}

void Enemy::render(void)
{
	if (this->_y >= LINES)
		return;
	move(this->_y, this->_x);
	addch(this->getType());
}

bool Enemy::collide(IEntity &entity)
{
	return typeid(entity) == typeid(Bullet) && checkCollide(entity);
}
