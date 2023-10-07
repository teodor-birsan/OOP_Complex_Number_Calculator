#include "UI.h"
#include "tests.h"

int main() {
	enitityTests();
	repoTests();
	serviceTests();
	UI console;
	console.runConsole();
	return 0;
}