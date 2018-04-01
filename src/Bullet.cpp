/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 21:55:31 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ncurses.h>
#include "Bullet.hpp"
#include "IEntity.hpp"

Bullet::Bullet(char type) : _type(type)
{
	this->_x = 0;
	this->_y = LINES;
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

char Bullet::getType(void)
{
	return this->_type;
}

void Bullet::update(void)
{
	this->_counter++;

	if (this->_counter >= 50)
	{
		this->_y = this->_y - 1;
		this->_counter = 0;
	}
}

void Bullet::render(void)
{
	move(this->_y, this->_x);
	addch(this->getType());
}
