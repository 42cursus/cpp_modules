/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:44:34 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:44:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cstring>

/*
** -------------------------------- STATIC VARS -------------------------------
*/

/*
** ------------------------------- CONSTRUCTORS -------------------------------
*/

Serializer::Serializer() {};
Serializer::Serializer(const Serializer &other) { (void) other; };


/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

Serializer::~Serializer() {};

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Serializer &Serializer::operator=(const Serializer &other) {
    (void) other;
    return *this;
};

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

std::ostream &operator<<(std::ostream &oss, const Data &data) {
    oss << "  id     = 0x" << std::hex << data.id << std::dec << "\n";
    oss << "  len    = 0x" << std::hex << data.len << std::dec << "\n";
    oss << "  kind   = 0x" << std::hex << (unsigned) data.kind << std::dec << "\n";
    oss << "  flags  = 0x" << std::hex << (unsigned) data.flags << std::dec << "\n";
    oss << "  cookie = 0x" << std::hex << data.cookie << std::dec << "\n";
    oss << "  tag    = " << std::string(data.tag, 6) << std::endl;
    return oss;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);// NOLINT(*-pro-tag-reinterpret-cast, *-pro-type-reinterpret-cast)
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);// NOLINT(*-pro-tag-reinterpret-cast, *-no-int-to-ptr, *-pro-type-reinterpret-cast)
}

/*
** -------------------------------- ACCESSORS ---------------------------------
*/

/*
** -------------------------------- EXCEPTIONS --------------------------------
*/

/*
** -------------------------------- MISCELLANEOUS --------------------------------
*/

bool host_is_little_endian() {
    uint16_t test = 0x0102;
    uint8_t byte[sizeof(test)];
    std::memcpy(byte, &test, sizeof(test));// NOLINT(*-pro-bounds-array-to-pointer-decay)
    return byte[0] == 0x02;
}

namespace {
    __attribute__((__used__))
    uint16_t
    bswap16(uint16_t var) {
        return static_cast<uint16_t>((var >> 8) | (var << 8));
    }

    __attribute__((__used__))
    uint32_t
    bswap32(uint32_t var) {
        return ((var & 0x000000FFU) << 24) |
               ((var & 0x0000FF00U) << 8) |
               ((var & 0x00FF0000U) >> 8) |
               ((var & 0xFF000000U) >> 24);
    }

    __attribute__((__used__))
    uint64_t
    bswap64(uint64_t var) {
        return ((var & 0x00000000000000FFULL) << 56) |
               ((var & 0x000000000000FF00ULL) << 40) |
               ((var & 0x0000000000FF0000ULL) << 24) |
               ((var & 0x00000000FF000000ULL) << 8) |
               ((var & 0x000000FF00000000ULL) >> 8) |
               ((var & 0x0000FF0000000000ULL) >> 24) |
               ((var & 0x00FF000000000000ULL) >> 40) |
               ((var & 0xFF00000000000000ULL) >> 56);
    }

}//namespace