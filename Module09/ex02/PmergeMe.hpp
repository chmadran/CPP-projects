/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:31:23 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/09 16:32:07 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstdlib>
# include <cstring>
# include <iostream>
# include <vector>
# include <deque>
# include <iterator>
# include <ctime>
# include <chrono>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		int			validArray(int ac, char **av);
		void		launchVector(int ac, char **av);
		void		launchDeque(int ac, char **av);
		
	private:
		PmergeMe	&operator=(PmergeMe const &src);
		PmergeMe(PmergeMe const &src);

		bool		validArg(const char *allowed, char *str);

		void		sortVector(std::vector<int> &_vector);
		void		mergeVector(std::vector<int> &_vector, std::vector<int> &left, std::vector<int> &right);
		void		insertVector(std::vector<int> &_vector);

		void		sortDeque(std::deque<int> &_deque);
		void		mergeDeque(std::deque<int> &deq, std::deque<int> &left, std::deque<int> &right);
		void		insertDeque(std::deque<int> &deq);

};

#endif