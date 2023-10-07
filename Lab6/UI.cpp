#include "UI.h"
#include <iostream>
using namespace std;

void UI::addEnitty()
{
	float real;
	float imaginary;
	cout << "Introduceti partea reala: \n";
	cin >> real;
	cout << "Introduceti partea imaginara: \n";
	cin >> imaginary;
	this->service.addEntity(real, imaginary);
}

void UI::removeEntity()
{
	float real;
	float imaginary;
	cout << "Introduceti partea reala: \n";
	cin >> real;
	cout << "Introduceti partea imaginara: \n";
	cin >> imaginary;
	this->service.removeEntity(real, imaginary);
}

void UI::updateEntity()
{
	float oldReal;
	float oldImaginary;
	cout << "Introduceti partea reala a vechiului numar: \n";
	cin >> oldReal;
	cout << "Introduceti partea imaginara a vechiului numar: \n";
	cin >> oldImaginary;
	float newReal;
	float newImaginary;
	cout << "Introduceti partea reala a noului numar: \n";
	cin >> newReal;
	cout << "Introduceti partea imaginara a noului numar: \n";
	cin >> newImaginary;
	this->service.updateEntity(oldReal, oldImaginary, newReal, newImaginary);
}

void UI::searchEntity()
{
	float real;
	float imaginary;
	cout << "Introduceti partea reala: \n";
	cin >> real;
	cout << "Introduceti partea imaginara: \n";
	cin >> imaginary;
	if (this->service.searchEntity(real, imaginary)) {
		cout << "Elementul a fost gasit!\n";
		Entitate ent(real, imaginary);
		cout << ent << endl;
	}
	else
		cout << "Elementul nu a fost gasit!\n";
}

void UI::getAll()
{
	if (this->service.size() == 0) {
		cout << "Nu exista entitati!\n";
	}
	else {
		stack <Entitate> elements = this->service.getAll();
		while(elements.size() != 0){
			cout << elements.top() << " ";
			elements.pop();
		}
	}
	cout << endl;
}

void UI::greatestEntity()
{
	Entitate entity = this->service.greatestEntity();
	cout << entity << endl;
}

void UI::longestSequence()
{
	stack <Entitate> sequence = this->service.longestSequenceWithEqualValues();
	while (!sequence.empty()) {
		cout << sequence.top() << " ";
		sequence.pop();
	}
	cout << endl;
}

void UI::firstQuadrant()
{
	stack <Entitate> quadrant = this->service.firstQuadrantElements();
	while (!quadrant.empty()) {
		cout << quadrant.top() << " ";
		quadrant.pop();
	}
	cout << endl;
}

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

void menu() {
	cout << "\t\tMENIU\n"
		<< "1.Adauga o entitate.\n"
		<< "2.Sterge o entitate.\n"
		<< "3.Actualizeaza o entitate.\n"
		<< "4.Cauta o entitate.\n"
		<< "5.Afiseaza toate entitatile.\n"
		<< "6.Cea mai mare entitate din sir.\n"
		<< "7.Cea mai lunga secventa cu entitati egale.\n"
		<< "8.Afiseaza toate elementele din primul cadran al cercului trigonometric.\n"
		<< "\tq - Inchide\n";
}

void UI::runConsole()
{
	menu();
	while (true) {
		cout << "Alege o optiune: \n";
		char option;
		cin >> option;
		switch (option)
		{
		case '1':
			this->addEnitty();
			break;
		case '2':
			this->removeEntity();
			break;
		case '3':
			this->updateEntity();
			break;
		case '4':
			this->searchEntity();
			break;
		case '5':
			this->getAll();
			break;
		case '6':
			this->greatestEntity();
			break;
		case '7':
			this->longestSequence();
			break;
		case '8':
			this->firstQuadrant();
			break;
		case 'q':
			exit('q');
			break;
		default:
			menu();
			break;
		}
	}
}

UI::~UI()
{
}
