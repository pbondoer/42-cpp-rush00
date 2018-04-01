/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:11:21 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
# define PLAYER_CLASS_H

# include "IEntity.hpp"

# include <string>

class Player : public IEntity
{
	public:
		Player(void);
		Player(Player const & obj);
		~Player(void);

		Player& operator=(Player const &);

		std::string getModel(void);
		void	update(void);
		void	render(void);
		bool	shouldRemove(void);
		bool	collide(IEntity &entity);
	private:
		static const int _xSize;
		static const std::string _model;
};

#endif // PLAYER_CLASS_H
