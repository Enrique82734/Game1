#pragma once
#include <string>
#include <map>

using namespace std;

class Item
{
public:
	string name;
	string descriptionOrUse;
	int id, var, loc;
	Item();

	Item(string _name, string _descriptionOrUse) : name(_name), descriptionOrUse(_descriptionOrUse) {}
	Item(string _name) : name(_name) {}
	Item(string _name, int _id) : name(_name), id(_id){}
	Item(string _name, int _id, int _loc) : name(_name), id(_id), loc(_loc){}
	Item(string _name, string _descriptionOrUse, int _var) : name(_name), descriptionOrUse(_descriptionOrUse), var(_var) {}
	Item(string _name, string _descriptionOrUse, int _var, int _id) : name(_name), descriptionOrUse(_descriptionOrUse), var(_var), id(_id) {}
	
	virtual ~Item();

};
inline bool operator==(const Item& a, const Item& b) {
	return true;
}

