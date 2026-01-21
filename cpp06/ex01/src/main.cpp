/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:38:52 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:38:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int main() {

    std::cout << "Host endianness    : " << (host_is_little_endian() ? "Little" : "big") << " endian" << "\n";
    std::cout << "sizeof(uintptr_t)  = " << sizeof(uintptr_t) << "\n";
    std::cout << "sizeof(Data)       = " << sizeof(Data) << "\n";
    std::cout << "alignof(Data)      = " << __alignof__(Data) << "\n";
    std::cout << "offsetof(cookie)   = " << offsetof(Data, cookie) << "\n\n";

    Data *dataPtr = new Data();
    dataPtr->tag[0] = 'c';
    dataPtr->tag[1] = 'l';
    dataPtr->tag[2] = '\0';
    dataPtr->len = 64;
    dataPtr->kind = 'c';
    dataPtr->flags = 1U;

    Data *before = new Data();
    dataPtr->tag[0] = 'm';
    dataPtr->tag[1] = 'f';
    dataPtr->tag[2] = '\0';
    before->len = 640;
    before->kind = 'm';
    before->flags = 0U;

    uintptr_t dataRaw = Serializer::serialize(dataPtr);
    Data *restored = Serializer::deserialize(dataRaw);

    std::cout << "Pointer round-trip: \n" << std::endl;
    std::cout << "initial : " << FT_GREEN << dataPtr << FT_RST << std::endl;
    std::cout << *dataPtr << std::endl;
    std::cout << "reinterpreted : " FT_GREEN "0x" << std::hex << dataRaw << FT_RST << std::dec << "\n" << std::endl;
    std::cout << "restored: " << FT_GREEN << restored << FT_RST << std::endl;
    std::cout << *restored << std::endl;
    std::cout << std::endl;



    char value[4] = {'5'};
    char *ptrValue = &value[0];
    int *numValue = reinterpret_cast<int*>(ptrValue); // NOLINT(*-pro-tag-reinterpret-cast, *-pro-type-reinterpret-cast)

    std::cout << "Address of ptrValue: " << FT_GREEN << static_cast<void*>(ptrValue) << FT_RST << std::endl;
    std::cout << "Address of numValue: " << FT_GREEN << numValue << FT_RST << std::endl;
    std::cout << "Value of ptrValue:   " << FT_BLUE << *ptrValue << FT_RST << std::endl;
    std::cout << "Value of numValue: " << FT_BLUE << *numValue << FT_RST << std::endl;
    *numValue = 42;
    std::cout << "Value of ptrValue after reassignment: " << FT_CYAN << *ptrValue << FT_RST << std::endl;
    std::cout << "Value of numValue after reassignment: " << FT_CYAN << *numValue << FT_RST << std::endl;

    delete dataPtr;
    delete before;

    return 0;
}
