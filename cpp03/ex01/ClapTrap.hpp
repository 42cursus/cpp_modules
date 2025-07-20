/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 01:13:59 by abelov            #+#    #+#             */
/*   Updated: 2025/03/17 01:14:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <sstream>
#include <string>

/**
 * https://www.ditig.com/256-colors-cheat-sheet
 * List of ansi color escape sequences:
 * 	https://stackoverflow.com/questions/4842424/
 */
#define FT_BOLD  	"\033[1m"       // Bold
#define FT_UND   	"\033[4m"       // Underline
#define FT_RED   	"\033[0;31m"
#define FT_GREEN 	"\033[0;32m"    // Green
#define FT_BLUE 	"\033[0;32m"    // Blue
#define FT_CYAN  	"\033[36m"
#define FT_PINK		"\033[1;95m"    // Pink (Bright Magenta)
#define FT_SALMON	"\033[38;5;210m"
#define FT_ORANGE	"\033[38;5;202m"
#define FT_PUMPKIN	"\033[38;5;202m"
#define FT_PUMPKIN2		"\033[38;5;208m"
#define FT_STEEL_BLUE	"\033[38;5;67m"
#define FT_SKY_BLUE		"\033[38;5;117m"
#define FT_BRIGHT_RED2	"\033[38;5;196m"
#define FT_BRIGHT_RED3	"\033[38;5;160m"
#define FT_LIME_GREEN	"\033[38;5;196m"
#define FT_LIGHT_PURPLE	"\033[38;5;135m"
#define FT_HOT_PINK	"\033[38;5;197m"
#define FT_BOLD_R	"\033[1;31m"    // Bold red
#define FT_BOLD_G	"\033[1;32m"    // Bold green
#define FT_BOLD_B	"\033[1;34m"    // Bold blue
#define FT_BOLD_Y	"\033[1;33m"    // Bold yellow
#define FT_BOLD_M	"\033[1;35m"    // Bold magenta
#define FT_BOLD_C	"\033[1;36m"    // Bold cyan
#define FT_BOLD_W	"\033[1;37m"    // Bold white
#define FT_RST		"\033[0m"       // Reset to default color

// ************************************************************************** //
//                              ClapTrap Class                                //
// ************************************************************************** //

class ClapTrap
{

private:
	static const unsigned int	DEFAULT_HEALTH = 10;
	static const unsigned int	DEFAULT_ENERGY = 10;
	static const unsigned int	DEFAULT_DAMAGE = 0;
	static const std::string&	DEFAULT_NAME;

protected:
	static const char _className[];
	std::string _name;
	unsigned int _health;
	unsigned int _maxHealth;
	unsigned int _energy;
	unsigned int _damage;

public:
	ClapTrap();
	explicit ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &);
	~ClapTrap();

	ClapTrap& operator=(const ClapTrap &);
	virtual void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printStatus() const;

	const std::string &getName() const;
	virtual const char* getClassName() const;
	unsigned int getHealth() const;
	unsigned int getEnergy() const;
	unsigned int getDamage() const;

	void setName(const std::string &name);
	void setHealth(unsigned int health);
	void setEnergy(unsigned int energy);
	void setDamage(unsigned int damage);
};

#endif //CLAPTRAP_HPP
