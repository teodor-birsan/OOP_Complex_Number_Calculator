#include "Service.h"

Service::Service()
{
}

Service::Service(Repository& repo)
{
	this->repo = repo;
}

void Service::addEntity(float real, float imaginary)
{
	Entitate ent(real, imaginary);
	this->repo.add(ent);
}

bool Service::removeEntity(float real, float imaginary)
{
	Entitate ent(real, imaginary);
	return this->repo.remove(ent);
}

bool Service::searchEntity(float real, float imaginary)
{
	Entitate ent(real, imaginary);
	return this->repo.findEntity(ent);
}

bool Service::updateEntity(float oldReal, float oldImaginary, float newReal, float newImaginary)
{
	Entitate oldEntity(oldReal, oldImaginary);
	Entitate newEntity(newReal, newImaginary);
	return this->repo.update(oldEntity, newEntity);
}

Entitate Service::greatestEntity()
{
	Entitate max;
	stack <Entitate> elements = this->repo.getAll();
	while (!elements.empty()) {
		if (elements.top().absoluteValue() >  max.absoluteValue()) {
			max = elements.top();
		}
		elements.pop();
	}
	return max;
}

stack <Entitate> Service::firstQuadrantElements()
{
	stack <Entitate> firstQuadrant;
	stack <Entitate> elements = this->repo.getAll();
	while (!elements.empty()) {
		if (elements.top().getReal() > 0 and elements.top().getImaginary() > 0) {
			firstQuadrant.push(elements.top());
		}
		elements.pop();
	}
	return firstQuadrant;
}

void clearStack(stack <Entitate>& elem) {
	while (!elem.empty())
		elem.pop();
}

void copyStack(stack <Entitate>& source, stack <Entitate>& dest)
{
	while (!source.empty())
		dest.push(source.top());
	source.pop();
}



stack <Entitate> Service::longestSequenceWithEqualValues()
{
	stack <Entitate> elements = this->getAll();
	stack <Entitate> sequence;
	stack <Entitate> longestSequence;
	while(elements.size() >= 1){
		Entitate entity = elements.top();
		elements.pop();
		if (!elements.empty() && entity == elements.top()) {
			sequence.push(entity);
		}
		else {
			if (!sequence.empty() &&  entity == sequence.top())
				sequence.push(entity);
			if (sequence.size() > longestSequence.size()) {
				longestSequence = sequence;
			}
			clearStack(sequence);
		}
	}
	return longestSequence;
}

stack <Entitate> Service::getAll()
{
	return this->repo.getAll();
}

int Service::size()
{
	return this->repo.stackSize();
}

Service::~Service()
{
	cout << "!! Service destructor exectuted !!\n";
}
