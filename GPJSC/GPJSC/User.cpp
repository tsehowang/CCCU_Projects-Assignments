#include "User.h"

//type constructer
User::User(string username, string name) {
	this->username = username;
	this->name = name;
}

//getter
string User::getUsername() {
	return username;
}

//getter
string User::getName() {
	return name;
}

//setter
void User::setUsername(string uname) {
	username = uname;
}

//setter
void User::setName(string nm) {
	name = nm;
}