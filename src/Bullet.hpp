/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aratinau <aratinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:11 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 21:53:11 by aratinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_H
# define BULLET_CLASS_H

# include "IEntity.hpp"

# include <string>

class Bullet : public IEntity
{
	public:
		Bullet(char type);
		Bullet(Bullet const & obj);
		~Bullet(void);

		Bullet& operator=(Bullet const &);

		char	getType(void);

		std::string getModel(void);
		void	update(void);
		void	render(void);
	private:
		char	_type;
};

#endif // BULLET_CLASS_H
