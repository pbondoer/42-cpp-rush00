/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:48:57 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:26:21 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <string>
#include <typeinfo>
#include "Player.hpp"
#include "IEntity.hpp"

const int Player::_xSize = 3;
const std::string Player::_model = "A";

Player::Player(void) {}
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

}

void Player::render(void)
{
	move(this->_y, this->_x);
	addstr(this->getModel().c_str());
}

bool Player::collide(IEntity &)
{
	return false;
}
