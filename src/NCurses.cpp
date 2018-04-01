/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCurses.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:19:16 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:48:29 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <csignal>
#include "NCurses.hpp"

NCurses* env(NCurses *c)
{
	static NCurses* ptr;

	if (c)
		ptr = c;
	return ptr;
}

void	onResize(int)
{
	// reinitialize the window
	endwin();
	refresh();
	clear();

	// get the new dimensions
	int x, y;
	getmaxyx(stdscr, y, x);
	env()->setSize(y, x);
}

NCurses::NCurses(void) : _x(0), _y(0)
{
	initscr(); // initialize ncurses
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	// main window flags
	keypad(stdscr, TRUE); // allow special keys
	nodelay(stdscr, TRUE); // dont block the main thread when querying keys
	scrollok(stdscr, FALSE); // dont allow scrolling the window

	// get dimensions
	getmaxyx(stdscr, this->_y, this->_x);

	// register handlers
	std::signal(SIGWINCH, onResize); // allow resizing
}


NCurses::~NCurses(void)
{
	// foreach window
	// delwin(win)

	endwin();
}

void NCurses::setSize(int y, int x)
{
	this->_y = y;
	this->_x = x;
}

int NCurses::getX(void)
{
	return this->_x;
}

int NCurses::getY(void)
{
	return this->_y;
}

NCurses::NCurses(NCurses const &) {}
NCurses& NCurses::operator=(NCurses const &) { return *this; }
