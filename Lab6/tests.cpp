#include "Entitate.h"
#include "Repository.h"
#include "Service.h"
#include <cassert>


void enitityTests()
{
    Entitate nr0(5, 3);
    Entitate nr1(7, -10);
    Entitate nr2(-8, 2);
    Entitate nr3(0, 2);
    assert(nr0 + nr1 == Entitate(12, -7));
    assert(nr1 - nr2 == Entitate(15, -12));
    assert(nr2 * nr0 == Entitate(-46, -14));
    assert(nr1.getReal() == 7);
    assert(nr2.getImaginary() == 2);
    assert(nr3.conjugate() == Entitate(0, -2));
    assert(nr2.absoluteValue() == sqrtf(68));
    cout << "All entity tests have passed!" << endl;
}

void repoTests()
{
    Repository repo;
    Entitate nr1(5, 3); // 34
    Entitate nr2(7, -10); // 149
    Entitate nr3(-8, 2); // 68
    Entitate nr4(0, 2); // 4
    Entitate nr5(0, 0); // 0
    repo.add(nr1);
    repo.add(nr2);
    repo.add(nr3);
    repo.add(nr4);
    assert(repo.findEntity(nr1) == true);
    assert(repo.findEntity(nr5) == false);
    cout << "All repository tests have passed!" << endl;
}

void serviceTests()
{
    Service service;
    Entitate nr1(5, 3); // 34
    Entitate nr2(7, -10); // 149
    Entitate nr3(-8, 2); // 68
    Entitate nr4(0, 0); // 0
    Entitate nr5(0, 0); // 0
    Entitate nr6(1, 2); // 5
    Entitate nr7(10, 1); // 101
    Entitate nr8(12, 6); // 180
    Entitate nr9(4, 9); // 97
    Entitate nr10(2, 1); // 5
    service.addEntity(5, 3);
    service.addEntity(7, -10);
    service.addEntity(-8, 2);
    service.addEntity(0, 0);
    service.addEntity(0, 0);
    service.addEntity(1, 2);
    service.addEntity(10, 1);
    service.addEntity(12, 6);
    service.addEntity(4, 9);
    service.addEntity(2, 1);
    stack <Entitate> v1;
    v1.push(nr4);
    v1.push(nr5);
    stack <Entitate> v2;
    v2.push(nr10);
    v2.push(nr9);
    v2.push(nr8);
    v2.push(nr7);
    v2.push(nr6);
    v2.push(nr1);
    stack <Entitate> v3 = service.firstQuadrantElements();
    for (int i = 0; i < 6; i++) {
        assert(v2.top() == v3.top());
        v2.pop();
        v3.pop();
    }
    assert(service.greatestEntity() == nr8);
    stack <Entitate> v4 = service.longestSequenceWithEqualValues();
    for (int i = 0; i < 2; i++) {
        assert(v1.top() == v4.top());
        v1.pop();
        v4.pop();
    }
    cout << "All service tests have passed!\n";
}