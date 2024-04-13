/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:20:29 by chmadran          #+#    #+#             */
/*   Updated: 2023/09/26 13:29:22 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

#define FRAG_HP 100
#define FRAG_EP 100
#define FRAG_DAM 30

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &original);
	~FragTrap(void);

	FragTrap& operator=(const FragTrap &original);

	void highFivesGuys(void);
};

#endif