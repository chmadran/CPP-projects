/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:17:40 by chmadran          #+#    #+#             */
/*   Updated: 2023/06/19 15:31:39 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);	
}
void	uppercase_str(char *str)
{	
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
}

int main(int argc, char **argv)
{	
	int 	i = 1;
	int		len = 0;
	char	*current;

	current = NULL;
	if (argc == 1)
	{
		std::cout << "*LOUD AND UNBEARABLE FEEDBACK NOISE*";
		return (0);
	}
	while (i < argc)
	{
		current = argv[i];
		len = ft_strlen(current);
		uppercase_str(current);
		for(int j = 0 ; j < len ; j++)
			std::cout << current[j];
		std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}