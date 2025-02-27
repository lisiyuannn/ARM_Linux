#include <iostream>
#include "exam.h"
using namespace std;

Examinee::~Examinee()
{
    cout << "~Examinee()" << endl;
}

void ExcellentStd::exam()
{
    cout << "Excellent student is examing..." << endl;
}

ExcellentStd::~ExcellentStd()
{
    cout << "~ExcellentStd()" << endl;
}

PoorStd::PoorStd()
{
    this->gunner = new ExcellentStd();
    cout << "PoorStd()" << endl;
}

PoorStd::~PoorStd()
{
    if(this->gunner != nullptr)
    {
        delete this->gunner;
    }
    cout << "~PoorStd()" << endl;
}


void PoorStd::exam()
{
    this->gunner->exam();
}
