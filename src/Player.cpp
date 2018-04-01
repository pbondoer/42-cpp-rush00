/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 21:38:42 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include "Player.hpp"
#include "IEntity.hpp"

const int Player::_xSize = 3;
const int Player::_ySize = 2;
const std::string Player::_model = "/o\\";

Player::Player(char type) : _type(type) {}
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

void Player::update(void)
{
	this->_counter++;

	if (this->_counter >= 50)
	{
		this->_y = this->_y + 1;
		this->_counter = 0;
	}
}

void Player::render(void)
{
	move(this->_y, this->_x);
	addch(this->getType());
}

char Player::getType(void)
{
	return this->_type;
}
