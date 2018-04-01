/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NCurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:17:12 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:49:17 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_CLASS_H
# define NCURSES_CLASS_H

# include <cstddef>

class NCurses
{
	public:
		NCurses(void);
		NCurses(NCurses const &);
		~NCurses(void);

		NCurses& operator=(NCurses const &);

		void setSize(int y, int x);
		int getX(void);
		int getY(void);
	private:
		int _x;
		int _y;
};

NCurses* env(NCurses *c = NULL);

#endif
