// emp.h -- Заголовочный файл для класса abstr_emp и его дочерних классов. Классы создания организационной структуры
#ifndef ORGANIZATION_STRUCTURE_H_INCLUDED
#define ORGANIZATION_STRUCTURE_H_INCLUDED
#include <iostream>
#include <string>
class abstr_emp
{
private:
    std::string fname;      // Имя abstr_emp
    std::string lname;      // Фамилия abstr_emp
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn, const std::string & ln,
              const std::string & j);
    virtual void ShowAll() const;   // Выводит все данные с именами
    virtual void SetAll();               // Запрашивает значения у пользователя
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    // Выводит только имя и фамилию
    virtual ~abstr_emp() = 0;   // Виртуальный базовый класс -- АБК
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const std::string & fn, const std::string & ln,
             const std::string & j);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;             // Количество управляемых abstr_emp
protected:
    int InChargeOf() const {return inchargeof; } // Вывод
    int & InChargeOf() {return inchargeof; }     // Ввод
public:
    manager();
    manager(const std::string & fn, const std::string & ln, const std::string & j, int ico = 0);
    manager(const abstr_emp & e, int ico);
    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
    std::string reportsto;      // Кому выводить отчеты
protected:
    const std::string ReportsTo() const {return reportsto; }
    std::string & ReportsTo() {return reportsto; }
public:
    fink();
    fink(const std::string & fn, const std::string & ln,
         const std::string & j, const std::string & rpo);
    fink(const abstr_emp & e, const std::string & rpo);
    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink    // Надзор за управляющими
{
public:
    highfink();
    highfink(const std::string & fn, const std::string & ln,
             const std::string & j, const std::string & rpo, int ico);
    highfink(const abstr_emp & e, const std::string & rpo, int ico);
    highfink(const fink & f, int ico);
    highfink(const manager & m, const std::string & rpo);
    highfink(const highfink & h);
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif // ORGANIZATION_STRUCTURE_H_INCLUDED
