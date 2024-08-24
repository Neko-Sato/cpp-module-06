/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:19:34 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:37:06 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
private:
public:
  Serializer();
  ~Serializer();
  Serializer(Serializer const &other);
  Serializer &operator=(Serializer const &other);

  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};

#endif
