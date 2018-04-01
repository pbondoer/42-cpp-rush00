/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:26:35 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "IEntity.hpp"

Bullet::Bullet(int y, int x)
{
	this->_x = x;
	this->_y = y - 1;
}
Bullet::Bullet(Bullet const & obj)
{
	*this = obj;
}
Bullet::~Bullet(void) {}

Bullet& Bullet::operator=(Bullet const &)
{
	return *this;
}

void Bullet::update(void)
{
	this->_counter++;

	if (this->_counter >= 5)
	{
		this->_y = this->_y - 1;
		this->_counter = 0;

		if (this->_y < 0)
			this->_remove = true;
	}
}

bool Bullet::collide(IEntity &entity)
{
	return typeid(entity) == typeid(Enemy) && checkCollide(entity);
}

void Bullet::render(void)
{
	if (this->_y < 0)
		return;

	move(this->_y, this->_x);
	addch('^');
}
