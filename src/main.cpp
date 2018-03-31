/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 18:17:56 by pbondoer          #+#    #+#             */
/*   Updated: 2018/03/31 18:45:21 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <csignal>
#include <iostream>

// XXX
void onResize(int);
// XXX

int main(void)
{
	initscr(); // initialize ncurses
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	keypad(stdscr, TRUE); // allow special keys
	nodelay(stdscr, TRUE); // dont delay strokes

	// handlers
	std::signal(SIGWINCH, onResize); // allow resizing

	// init window
	WINDOW * win = newwin(5, 5, 5, 5);
	scrollok(win, FALSE);
	wmove(win, 0, 0); // window, y, x

	while (std::cin.good()) {
		int ch = getch();

		if (ch == ERR)
			continue;

		// type it in the window
		box(win, 0, 0);
		waddch(win, static_cast<chtype>(ch));

		// refresh the window
		wrefresh(win);
	}

	// clean the memory
	delwin(win);

	// stop using ncurses
	endwin();
	return 0;
}

void onResize(int)
{
	int nh, nw;
	getmaxyx(stdscr, nh, nw);
}
