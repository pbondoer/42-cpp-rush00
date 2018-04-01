/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:17:56 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:57:39 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <list>

#include "Player.hpp"
#include "Enemy.hpp"
#include "NCurses.hpp"

int main(void)
{
	NCurses e;
	env(&e);

	Player p;

	bool shouldQuit = false;
	int ch;

	std::list<IEntity *> enemies;
	int counter = 0;

	while (!shouldQuit) {
		// handle keyboard input
		while ((ch = getch()) != ERR)
		{
			if (ch == 'q')
				shouldQuit = true;

			if (ch == 'd')
				p.setX(p.getX() + 2);
			if (ch == 'a')
				p.setX(p.getX() - 2);

			if (ch == 's')
				p.setY(p.getY() + 1);
			if (ch == 'w')
				p.setY(p.getY() - 1);
		}

		counter++;
		if (counter >= 30)
		{
			Enemy *e = new Enemy('@');
			enemies.push_back(e);
			counter = 0;
		}

		clear(); // pfff we're just lazy

		for (std::list<IEntity *>::iterator it = enemies.begin();
				it != enemies.end();
				it++)
		{
			(*it)->update();
			(*it)->render();

			if ((*it)->getY() >= LINES)
			{
				delete *it;
				it = enemies.erase(it);
			}
		}


		// start drawing
		move(p.getY(), p.getX());
		addstr(p.getModel().c_str());

		// refresh the window
		refresh();

		napms(1);
	}

	return 0;
}
