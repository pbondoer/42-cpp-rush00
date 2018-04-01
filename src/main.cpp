/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:17:56 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 16:46:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <csignal>
#include <iostream>

#include "Player.hpp"

// XXX
void onResize(int);
// XXX

int main(void)
{
	initscr(); // initialize ncurses
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	keypad(stdscr, TRUE); // allow special keys
	nodelay(stdscr, TRUE); // dont delay strokes
	scrollok(stdscr, FALSE); // dont allow scrolling

	move(0, 0);

	// handlers
	std::signal(SIGWINCH, onResize); // allow resizing

	bool shouldQuit = false;
	int ch;

	Player p;

	while (!shouldQuit) {
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

		// type it in the window

		clear();

		move(p.getY(), p.getX());
		addstr(p.getModel().c_str());

		// refresh the window
		refresh();

		napms(1);
	}

	// clean the memory
	// delwin(win);

	// stop using ncurses
	endwin();
	return 0;
}

void onResize(int)
{
	endwin();
	// Needs to be called after an endwin() so ncurses will initialize
	// itself with the new terminal dimensions.
	refresh();
	clear();
}
