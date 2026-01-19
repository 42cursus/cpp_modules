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
Serializer::Serializer(const Serializer &other) {(void)other;};


/*
** ------------------------------- DESTRUCTORS --------------------------------
*/

Serializer::~Serializer() {};

/*
** -------------------------------- OPERATORS ---------------------------------
*/

Serializer &Serializer::operator=(const Serializer &other) {(void)other; return *this;};

/*
** -------------------------------- OVERLOADS ---------------------------------
*/

static void print_tag(const char tag[6]) {
    for (int i = 0; i < 6; ++i)
        std::cout << tag[i];
}

std::ostream &operator<<(std::ostream &oss, const Data &data) {
    oss << "  id     = 0x" << std::hex << data.id << std::dec << "\n";
    oss << "  len    = 0x" << std::hex << data.len << std::dec << "\n";
    oss << "  kind   = 0x" << std::hex << (unsigned) data.kind << std::dec << "\n";
    oss << "  flags  = 0x" << std::hex << (unsigned) data.flags << std::dec << "\n";
    oss << "  cookie = 0x" << std::hex << data.cookie << std::dec << "\n";
    oss << "  tag    = ";
    print_tag(data.tag);
    return oss;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast <uintptr_t> (ptr); // NOLINT(*-pro-tag-reinterpret-cast)
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast <Data*> (raw);  // NOLINT(*-pro-tag-reinterpret-cast, *-no-int-to-ptr)
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
    uint16_t    test = 0x0102;
    uint8_t     byte[sizeof(test)];
    std::memcpy(byte, &test, sizeof(test)); // NOLINT(*-pro-bounds-array-to-pointer-decay)
    return byte[0] == 0x02;
}

namespace {
    __attribute__((__used__))
    uint16_t bswap16(uint16_t x) {
        return static_cast<uint16_t>((x >> 8) | (x << 8));
    }

    __attribute__((__used__))
    uint32_t bswap32(uint32_t x) {
        return ((x & 0x000000FFu) << 24) |
               ((x & 0x0000FF00u) << 8)  |
               ((x & 0x00FF0000u) >> 8)  |
               ((x & 0xFF000000u) >> 24);
    }

    __attribute__((__used__))
    uint64_t bswap64(uint64_t x) {
        return ((x & 0x00000000000000FFull) << 56) |
               ((x & 0x000000000000FF00ull) << 40) |
               ((x & 0x0000000000FF0000ull) << 24) |
               ((x & 0x00000000FF000000ull) << 8)  |
               ((x & 0x000000FF00000000ull) >> 8)  |
               ((x & 0x0000FF0000000000ull) >> 24) |
               ((x & 0x00FF000000000000ull) >> 40) |
               ((x & 0xFF00000000000000ull) >> 56);
    }

}//namespace