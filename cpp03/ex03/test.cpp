#include <string>
#include <iostream>

class ClapTrap {
protected:
	const std::string _name;
public:
	virtual void attack(const std::string &target) {
		std::cout << "ClapTrap::attack" << std::endl;
	}
};

class ScavTrap : public virtual ClapTrap {
public:
	void attack(const std::string &target);
};

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap::attack" << std::endl;
}

class FragTrap : public virtual ClapTrap
{
public:
	void attack(const std::string& target) {
		std::cout << "FragTrap::attack" << std::endl;
	}
};

class DiamondTrap : public ScavTrap, public FragTrap {
protected:
	const std::string _name;
public:
	void attack(const std::string& target) {
		ScavTrap::attack(target);
	}
};


int main() {
	DiamondTrap d;
	d.attack("qlwdokqjd"); // Unambiguous: calls A::foo through B
}