/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:28:49 by hshimizu          #+#    #+#             */
/*   Updated: 2024/08/25 00:46:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DATA_HPP__
#define __DATA_HPP__

#include <ostream>

struct Data {
  int data;
  Data(int data = 0);
  ~Data();
  Data(Data const &other);
  Data &operator=(Data const &other);
};

std::ostream &operator<<(std::ostream &os, Data const &data);

#endif
