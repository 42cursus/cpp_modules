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
    dataPtr->flags = 1u;

    Data *befire = new Data();
    dataPtr->tag[0] = 'm';
    dataPtr->tag[1] = 'f';
    dataPtr->tag[2] = '\0';
    befire->len = 640;
    befire->kind = 'm';
    befire->flags = 0u;

    uintptr_t dataRaw = Serializer::serialize(dataPtr);
    Data *restored = Serializer::deserialize(dataRaw);

    std::cout << "Pointer round-trip: \n" << std::endl;
    std::cout << "Initial : " << FT_GREEN << dataPtr << FT_RST << std::endl;
    std::cout << "    raw = " FT_GREEN "0x" << std::hex << dataRaw << FT_RST << std::dec << "\n";
    std::cout << "restored: " << FT_GREEN << restored << FT_RST << std::endl;
    std::cout << std::endl;

    std::cout << FT_BOLD "POINTER COMPARISON BEFORE REINTERPRET_CAST" FT_RST << std::endl;

    std::cout << "dataPtr: " << FT_BLUE << dataPtr  << FT_RST << std::endl;
    std::cout << "restored: " << FT_CYAN << restored << FT_RST << std::endl;

    std::cout << FT_BOLD "\nTESTING DIRECT REINTERPRET_CAST WITHOUT RAW CONVERSION" FT_RST << std::endl;

    Data *after = reinterpret_cast<Data*>(befire); // NOLINT(*-redundant-casting, *-pro-tag-reinterpret-cast)
    std::cout << "Address of befire: " << FT_GREEN << befire << FT_RST << std::endl;
    std::cout << "Address of dataPtrTest1: " << FT_GREEN << after << FT_RST "\n" << std::endl;

    std::cout << FT_BOLD "POINTER COMPARISON AFTER REINTERPRET_CAST" FT_RST << std::endl;
    std::cout << "befire: " << FT_BLUE << befire << FT_RST "\n" << std::endl;
    std::cout << "dataPtrTest1: " << FT_CYAN << after << FT_RST "\n" << std::endl;

    char value[4] = {'5'};
    char *ptrValue = &value[0];
    int *numValue = reinterpret_cast<int*>(ptrValue); // NOLINT(*-pro-tag-reinterpret-cast)

    std::cout << "Address of ptrValue: " << FT_GREEN << static_cast<void*>(ptrValue) << FT_RST << std::endl;
    std::cout << "Address of numValue: " << FT_GREEN << numValue << FT_RST << std::endl;
    std::cout << "Value of ptrValue:   " << FT_BLUE << *ptrValue << FT_RST << std::endl;
    std::cout << "Value of numValue: " << FT_BLUE << *numValue << FT_RST << std::endl;
    *numValue = 10;
    std::cout << "Value of ptrValue after reassignment: " << FT_CYAN << *ptrValue << FT_RST << std::endl;
    std::cout << "Value of numValue after reassignment: " << FT_CYAN << *numValue << FT_RST << std::endl;

    delete dataPtr;
    delete befire;

    return 0;
}
