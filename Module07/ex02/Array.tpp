/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chmadran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:02:00 by chmadran          #+#    #+#             */
/*   Updated: 2023/10/02 15:35:10 by chmadran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/************************************************************
 *				CONSTRUCTORS/DESTRUCTOR					*
 ************************************************************/

template < typename T >
Array<T>::Array() : _array(new T), _size(1) {}

template < typename T >
Array<T>::Array(unsigned int n) : _size(n) {
	_array = new T[n]();
}

template < typename T >
Array<T>::Array(Array<T> const &src) : _array(new T[src.getSize()]), _size(src.getSize()){
	for (size_t i = 0; i < _size; ++i)
		_array[i] = src._array[i];
};

template < typename T >
Array<T>::~Array(){
	delete[] _array;
};

template < typename T >
Array<T>	&Array<T>::operator=(const Array<T> &src){
	if (this != &src)
	{
		_array = new T[src.getSize()];
		for (size_t i = 0; i < _size; ++i)
			_array[i] = src._array[i];
		_size = src.getSize();
	}
	return (*this);
};

/************************************************************
 *				OTHER					*
 ************************************************************/

template < typename T >
unsigned int Array<T>::getSize() const {
	return (_size);
}

template < typename T >
T			&Array<T>::operator[](unsigned int index){
	if (index > _size - 1)
		throw Array<T>::indexOutOfRange();
	else
		return (_array[index]);
}

template < typename T >
const char*	Array<T>::indexOutOfRange::what() const throw(){
	return ("Index out of range");
}