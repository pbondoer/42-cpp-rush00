/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 17:30:47 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H

# include "IEntity.hpp"

class Enemy : public IEntity
{
	public:
		Enemy();
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy& operator=(Enemy const &);

		char	getType(void);
		void	update(void);
		void	render(void);
		bool	collide(IEntity &entity);

	private:
		char	_type;
		int		_speed;
		static char _types[6];
};

#endif // ENEMY_CLASS_H
