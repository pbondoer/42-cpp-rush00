/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:17:56 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:33:09 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <iostream>
#include <list>
#include <typeinfo>

#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"

#include "NCurses.hpp"
#include "FakeList.hpp"

int main(void)
{
	NCurses e;
	env(&e);

	bool shouldQuit = false;
	int ch;

	FakeList entities;
	int counter = 0;

	// add our player
	Player p;
	entities.add(&p);
	
	p.setPosition(LINES / 2, COLS / 2);

	bool lost = false;
	WINDOW * win = newwin(3, 10, LINES / 2 - 2, COLS / 2 - 5);

	while (!shouldQuit) {
		// handle keyboard input
		while ((ch = getch()) != ERR)
		{
			if (ch == 'q')
				shouldQuit = true;

			if (ch == 'd')
				p.setX(p.getX() + 1);
			if (ch == 'a')
				p.setX(p.getX() - 1);

			if (ch == 's')
				p.setY(p.getY() + 1);
			if (ch == 'w')
				p.setY(p.getY() - 1);

			if (ch == ' ')
			{
				entities.add(new Bullet(p.getY(), p.getX()));
			}
		}

		// spawn enemies
		counter++;
		if (counter >= 300)
		{
			entities.add(new Enemy());
			counter = 0;
		}

		clear(); // pfff we're just lazy

		if (!lost)
		{
			IEntity **raw = entities.getArray();
			for (size_t i = 0; i < entities.getHigh(); i++)
			{
				IEntity *ptr = raw[i];

				if (ptr == NULL)
					continue;

				ptr->update();

				if (ptr->shouldRemove())
				{
					entities.remove(i);
					continue;
				}
				else
				{
					// perform collision checks
					for (size_t c = 0; c < entities.getHigh(); c++)
					{
						IEntity *cptr = raw[c];

						if (cptr == NULL || cptr == ptr)
							continue;

						if (cptr->collide(*ptr))
						{
							entities.remove(c);
							entities.remove(i);

							ptr = NULL;
							break;
						}
						else if (cptr->checkCollide(*ptr) &&
								typeid(*ptr) == typeid(Player) &&
								typeid(*cptr) == typeid(Enemy))
						{
							lost = true;
						}
					}
				}

				if (ptr == NULL)
					continue;

				ptr->render();
			}
		}

		box(win, 0, 0);
		wmove(win, 1, 1);
		waddstr(win, "YOU LOSE");

		// refresh the window
		refresh();

		if (lost)
			wrefresh(win);

		napms(2);
	}

	return 0;
}
