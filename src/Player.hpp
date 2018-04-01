/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 16:23:51 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
# define PLAYER_CLASS_H

# include<string>

class Player
{
	public:
		Player(void);
		Player(Player const & obj);
		~Player(void);

		Player& operator=(Player const &);

		std::string getModel(void);

		int getX(void);
		void setX(int x);

		int getY(void);
		void setY(int y);
	private:
		static const int _xSize;
		static const int _ySize;
		static const std::string _model;

		int _x;
		int _y;
};

#endif // PLAYER_CLASS_H
