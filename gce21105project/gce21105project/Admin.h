#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin
{
private:
	std::string adminId;
	std::string adminPassword;

public:
	Admin();
	std::string getAdminId();
	std::string getAdminPassword();
	void UpdateEquipment();
	~Admin();
};


#endif // !ADMIN_H