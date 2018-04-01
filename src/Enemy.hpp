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

# include<string>

class Enemy
{
	public:
		Enemy(std::string type);
		Enemy(Enemy const & obj);
		~Enemy(void);

		Enemy& operator=(Enemy const &);

		std::string getType(void);
		void	update(void);
		void	render(void);

		int getY(void);
		void setY(int y);

	private:
		std::string _type;
		int _x;

		int _maxX;
		int _y;
		int _counter;
};

#endif // ENEMY_CLASS_H
