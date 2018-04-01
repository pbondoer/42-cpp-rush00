/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 16:38:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Player.hpp"

const int Player::_xSize = 3;
const int Player::_ySize = 2;
const std::string Player::_model = "/o\\";

Player::Player(void) : _x(0), _y(0) {}
Player::Player(Player const & obj)
{
	*this = obj;
}
Player::~Player(void) {}

Player& Player::operator=(Player const &)
{
	return *this;
}

std::string Player::getModel(void)
{
	return this->_model;
}

// position
int Player::getX(void)
{
	return this->_x;
}
void Player::setX(int x)
{
	this->_x = x;
}
int Player::getY(void)
{
	return this->_y;
}
void Player::setY(int y)
{
	this->_y = y;
}
