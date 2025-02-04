// Методы классов заголовочного файла emp.h
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include "emp.h"
const char fileName[FILENAME_MAX] = "OrgStr.txt";
const int Buffer = 1024;
std::ofstream outFile;
std::ifstream inFile;
// Методы Класса abstr_emp
abstr_emp::abstr_emp() : fname("no fname"), lname("no lname"), job("without work")
{

}

abstr_emp::abstr_emp(const std::string & fn, const std::string & ln,
              const std::string & j) : fname(fn), lname(ln), job(j)
{

}

void abstr_emp::ShowAll() const
{
    std::cout << fname << std::endl;
    std::cout << lname << std::endl;
    std::cout << job << std::endl;
    char Buf[Buffer];
    inFile.open(fileName, std::ios_base::in | std::ios_base::binary);
    inFile.clear();
    if (!inFile.is_open())
    {
        std::cerr << "Error: Failed to open input file: ";
        exit(EXIT_FAILURE);
    }
    std::cout << "Contents from file " << fileName << std::endl;
    while (inFile.read(Buf, sizeof(Buf) || inFile.gcount() > 0))
    {
        char ch;
        int index = 0;
        index++;
        ch = Buf[index];
        while (inFile.get(ch) && !inFile.eof())
            std::cout << ch;
    }
    inFile.close();
}

void abstr_emp::SetAll()
{
    std::cout << "Enter please your first name: " << std::flush;
    std::getline(std::cin, fname);
    std::cout << "Enter please youe last name: " << std::endl;
    std::getline(std::cin, lname).get();
    std::cout << "Enterp please work place: " << std::flush;
    std::getline(std::cin, job).get();
    outFile.open(fileName, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    outFile.clear();
    if (!outFile.is_open())
    {
        std::cerr << "Error: Failed to open output file: 1";
        exit(EXIT_FAILURE);
    }
    outFile << "Your Full name: " << fname << " " << lname << std::endl
    << "Your job place: " << job << std::endl;
    outFile.close();
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << e.fname << std::endl;
    os << e.lname << std::endl;
    os << e.job << std::endl;
    return os;
}

abstr_emp::~abstr_emp()
{
    std::cout << "Object abstr_emp remove! " << std::endl;
}

// Методы Класса employee

employee::employee() : abstr_emp()
{

}

employee::employee(const std::string & fn, const std::string & ln,
             const std::string & j) : abstr_emp(fn, ln, j)
{

}

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

// Методы Класса manager
manager::manager() : abstr_emp(), inchargeof(0)
{

}

manager::manager(const std::string & fn, const std::string & ln, const std::string & j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{

}

manager::manager(const abstr_emp & e, int ico) : abstr_emp(e), inchargeof(ico)
{

}

manager::manager(const manager & m)
    : abstr_emp(m), inchargeof(m.inchargeof)
{

}

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of: " << inchargeof << std::endl;

}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter please in charge of manager: ";
    std::cin >> inchargeof;
    outFile.open(fileName, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    outFile.clear();
    if (!outFile.is_open())
    {
        std::cerr << "Error: Failed to open output file: 2";
        exit(EXIT_FAILURE);
    }
    outFile << "In charge of: " << inchargeof << std::endl;
    outFile.close();
}

// Методы класса fink

fink::fink() : abstr_emp(), reportsto("")
{

}

fink::fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo)
         : abstr_emp(fn, ln, j), reportsto(rpo)
{

}

fink::fink(const abstr_emp & e, const std::string & rpo)
    : abstr_emp(e), reportsto(rpo)
{

}

fink::fink(const fink & e) : abstr_emp(e), reportsto(e.reportsto)
{

}

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Reports to: " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::getline(std::cin, reportsto);
    outFile.open(fileName, std::ios_base::in | std::ios_base::out | std::ios_base::binary);
    outFile.clear();
    if (!outFile.is_open())
    {
        std::cerr << "Error: Failed to open output file: 3";
        exit(EXIT_FAILURE);
    }
    outFile << "Report to: " << reportsto << std::endl;
    outFile.close();
}

// Методы класса highfink

highfink::highfink() : abstr_emp(), manager(), fink()
{

}

highfink::highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo, int ico)
             : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{

}

highfink::highfink(const abstr_emp & e, const std::string & rpo, int ico)
    : abstr_emp(e), manager(e, ico), fink(e, rpo)
{

}

highfink::highfink(const fink & f, int ico)
    : abstr_emp(f), manager(f, ico), fink(f)
{

}

highfink::highfink(const manager & m, const std::string & rpo)
    : abstr_emp(m), manager(m), fink(m, rpo)
{

}

highfink::highfink(const highfink & h)
    : abstr_emp(h), manager(h), fink(h)
{

}

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();
    manager::ShowAll();
    fink::ShowAll();
}

void highfink::SetAll()
{
    manager::SetAll();
    fink::SetAll();
}

