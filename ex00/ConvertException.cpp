/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertException.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:16:16 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:14:59 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConvertException.hpp"

ConvertException::ConvertException() {
}

ConvertException::~ConvertException() throw() {
}

ConvertException::ConvertException(const ConvertException &other)
    : std::exception(other) {
}

ConvertException &ConvertException::operator=(const ConvertException &other) {
  std::exception::operator=(other);
  return *this;
}

const char *ConvertException::what() const throw() {
  return "Illegal literal";
}