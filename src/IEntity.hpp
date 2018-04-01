/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IEntity.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 19:30:17 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 19:57:10 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INTERFACE_H
# define ENTITY_INTERFACE_H

class IEntity
{
	public:
		IEntity(void);
		IEntity(IEntity const & obj);
		virtual ~IEntity(void);

		IEntity& operator=(IEntity const &rhs);

		virtual void update(void) = 0;
		virtual void render(void) = 0;

		void setPosition(int y, int x);

		int getY(void);
		void setY(int y);

		int getX(void);
		void setX(int x);
	protected:
		int _counter;
		int _x;
		int _y;
};

#endif // ENTITY_INTERFACE_H
