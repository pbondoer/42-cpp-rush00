/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FakeList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 21:22:23 by pbondoer          #+#    #+#             */
/*   Updated: 2018/04/01 22:45:03 by pbondoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include "FakeList.hpp"
#include "IEntity.hpp"

FakeList::FakeList(void) : _size(16 * 1024), _count(0), _high(0)
{
	this->_lst = new IEntity *[this->_size];
	for (size_t i = 0; i < this->_size; i++)
		this->_lst[i] = NULL;
}
FakeList::FakeList(FakeList const &) {}
FakeList::~FakeList(void)
{
	delete [] this->_lst;
}

FakeList& FakeList::operator=(FakeList const &)
{
	return *this;
}

IEntity **FakeList::getArray(void) const
{
	return this->_lst;
}

size_t FakeList::getCount(void) const
{
	return this->_count;
}
size_t FakeList::getSize(void) const
{
	return this->_size;
}

size_t FakeList::getHigh(void) const
{
	return this->_high + 1;
}

void FakeList::add(IEntity *entity)
{
	for(size_t i = 0; i < this->_size; i++)
	{
		if (this->_lst[i] == NULL)
		{
			this->_lst[i] = entity;

			this->_count++;

			if (this->_high <= i)
				this->_high = i;

			return ;
		}
	}
}

void FakeList::remove(size_t i, bool del)
{
	if (this->_lst[i] == NULL)
		return;

	if (del)
		delete this->_lst[i];
	this->_lst[i] = NULL;

	if (this->_high == i)
	{
		for (int i = this->_high; i >= 0; i--)
		{
			if (this->_lst[i] != NULL)
			{
				this->_high = i;
				return;
			}
		}
	}
}
