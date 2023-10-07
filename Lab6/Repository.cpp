#include "Repository.h"

Repository::Repository()
{

}

void Repository::add(Entitate& ent)
{
	this->elements.push(ent);
}

bool Repository::remove(Entitate& ent)
{
	if (this->elements.top() == ent) {
		this->elements.pop();
		return true;
	}
	else {
		if (this->findEntity(ent)) {

			stack <Entitate> newElements = this->elements;
			this->elements = this->removeALL();
			int stackSize = newElements.size();
			while (newElements.size() != 0) {
				if (newElements.top() == ent) {
					newElements.pop();
				}
				this->elements.push(newElements.top());
				newElements.pop();
			}
			return true;
		}
	}
	return false;
}

bool Repository::findEntity(Entitate& ent)
{
	stack <Entitate> newElements = this->elements;
	while (newElements.size() != 0) {
		if (newElements.top() == ent)
			return true;
		newElements.pop();
	}
	return false;
}

bool Repository::update(Entitate& oldEntity, Entitate& newEntity)
{
	if(!this->findEntity(oldEntity))
		return false;
	stack <Entitate> oldElems = this->getAll();
	stack <Entitate> updated;
	while (!oldElems.empty()) {
		if (oldElems.top() == oldEntity) {
			oldElems.pop();
			updated.push(newEntity);
		}
		else {
			updated.push(oldElems.top());
			oldElems.pop();
		}
	}
	return true;
}

int Repository::stackSize()
{
	return this->elements.size();
}

stack<Entitate> Repository::removeALL()
{
	while (!this->elements.empty()) {
		this->elements.pop();
	}
	return this->elements;
}

stack <Entitate> Repository::getAll()
{
	return this->elements;
}

Repository::~Repository()
{
}
