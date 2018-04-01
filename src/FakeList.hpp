/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FakeList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:16:01 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 22:39:57 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FAKELIST_CLASS_H
# define FAKELIST_CLASS_H

# include "IEntity.hpp"

class FakeList
{
	public:
		FakeList(void);
		FakeList(FakeList const &);
		~FakeList(void);

		FakeList& operator=(FakeList const &);

		IEntity **getArray(void) const;
		size_t getSize(void) const;
		size_t getHigh(void) const;
		size_t getCount(void) const;
		void add(IEntity *entity);
		void remove(size_t i, bool del = true);
	private:
		IEntity	**_lst;
		size_t	_size;
		size_t	_count;
		size_t	_high;
};

#endif // FAKELIST_CLASS_H
