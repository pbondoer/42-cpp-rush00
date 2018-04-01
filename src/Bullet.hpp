/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 23:09:48 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_H
# define BULLET_CLASS_H

# include "IEntity.hpp"

# include <string>

class Bullet : public IEntity
{
	public:
		Bullet(int y, int x);
		Bullet(Bullet const & obj);
		~Bullet(void);

		Bullet& operator=(Bullet const &);

		void	update(void);
		void	render(void);
		bool	collide(IEntity &entity);
	private:
};

#endif // BULLET_CLASS_H
