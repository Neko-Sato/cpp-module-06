/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertException.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:15:31 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/23 03:53:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CONVERTEXCEPTION_HPP__
#define __CONVERTEXCEPTION_HPP__

#include <exception>
#include <string>

class ConvertException : public std::exception {
private:
public:
  ConvertException();
  ~ConvertException() throw();
  ConvertException(const ConvertException &other);
  ConvertException &operator=(const ConvertException &other);
  const char *what() const throw();
};

#endif
