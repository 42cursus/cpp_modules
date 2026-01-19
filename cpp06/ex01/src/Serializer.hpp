/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:44:26 by abelov            #+#    #+#             */
/*   Updated: 2026/01/18 15:13:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "formatting.h"
#include <cstddef>
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer {
public:

    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &other);
    virtual Serializer &operator=(const Serializer &other) = 0;
};

bool host_is_little_endian();

#endif//SERIALIZER_HPP
