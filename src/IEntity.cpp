/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:34:28 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:47:18 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IEntity.hpp"
#include "NCurses.hpp"

IEntity::IEntity(void) {}
IEntity::IEntity(IEntity const & obj) :
	_counter(obj._counter), _x(obj._x), _y(obj._y) {}
IEntity::~IEntity(void) {}

IEntity& IEntity::operator=(IEntity const &rhs)
{
	this->_counter = rhs._counter;
	this->_x = rhs._x;
	this->_y = rhs._y;

	return *this;
}

void IEntity::setPosition(int y, int x)
{
	this->setX(x);
	this->setY(y);
}

int IEntity::getX(void)
{
	return this->_x;
}

int IEntity::getY(void)
{
	return this->_y;
}

void IEntity::setX(int x)
{
	int max = env()->getX();
	this->_x = (x < 0 ? 0 : (x > max ? max : x));
}

void IEntity::setY(int y)
{
	int max = env()->getY();
	this->_y = (y < 0 ? 0 : (y > max ? max : y));
}
