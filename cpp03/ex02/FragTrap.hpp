/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:28:05 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:28:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP


#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	static const u_int	DEFAULT_HEALTH = 100;
	static const u_int	DEFAULT_ENERGY = 50;
	static const u_int	DEFAULT_DAMAGE = 20;
	static const std::string& DEFAULT_NAME;
protected:
	static const std::string _className;
	static const std::string _classLabel;
public:
	FragTrap();
	explicit FragTrap(const std::string& Name);
	FragTrap(FragTrap &other);

	FragTrap &operator = (const FragTrap &other);

	~FragTrap();
	const std::string& getClassName() const;
	const std::string& getClassLabel() const;

	void attack(const std::string& target);
	void highFivesGuys();
};

#endif //FRAGTRAP_HPP
