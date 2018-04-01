/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 21:38:14 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
# define PLAYER_CLASS_H

# include "IEntity.hpp"

# include <string>

class Player : public IEntity
{
	public:
		Player(char type);
		Player(Player const & obj);
		~Player(void);

		Player& operator=(Player const &);

		char	getType(void);

		std::string getModel(void);
		void	update(void);
		void	render(void);
	private:
		static const int _xSize;
		static const int _ySize;
		static const std::string _model;

		char	_type;
};

#endif // PLAYER_CLASS_H
