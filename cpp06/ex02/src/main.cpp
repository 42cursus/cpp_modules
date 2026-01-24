/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 21:39:12 by abelov            #+#    #+#             */
/*   Updated: 2025/07/25 21:39:13 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
    /* seed the random number generator (with the current time) */
    std::srand(std::time(0));

    std::cout << FT_ORANGE "Stage 1: generation:" FT_RST << std::endl;
    Base *ptr = generate();
    std:: cout << std::endl;

    std::cout << FT_ORANGE "Stage 2: identify(Base *p):\n" FT_RST << std::endl;
    identify(ptr);

    std::cout << FT_ORANGE "Stage 3: identify(Base &ref)\n" FT_RST << std::endl;
    identify(*ptr);
    delete ptr;
}
