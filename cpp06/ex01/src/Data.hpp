/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 15:24:00 by abelov            #+#    #+#             */
/*   Updated: 2026/01/18 15:24:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
#define DATA_HPP

#include <cstring>
#include <string>

struct Data {
    uint32_t id;
    uint16_t len;
    uint8_t  kind;
    uint8_t  flags;
    uint32_t cookie;
    char     tag[6];
};

std::ostream &operator<<(std::ostream &oss, const Data &data);


#endif//DATA_HPP
