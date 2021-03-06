#pragma once
#include <vector>
#include "AllClasses.h"
#include <ctime>
#include "Composite.h"
#include <memory>
#include <algorithm>

using std::unique_ptr;
using std::weak_ptr;

enum CTypeOfComponent {
    COMP_POSITION,
    COMP_GRAPHIC,
    COMP_ACCESSORY,
    COMP_HEALTH,
    COMP_POWER,
    COMP_ACTIVE_SKILL,
    COMP_PASSIVE_SKILL,
    COMP_TARGET_SKILL,
	COMP_OTHER
};

/**
 * \brief Класс CTower
 *
 * Содержит вектор указателей на компаненты
 *
 */

class CTower : public IComposite{
private:
    std::vector<unique_ptr<IComponent> > components;
public:

	/**
	 * \brief Функция добавляющая компоненту в components
	 * @param comp - указатель на компоненту
	 */

    void AddComponent(IComponent* comp);

    /**
     * \brief Функция, обновляющая состояние башни
     * @param dtime
     */

    void Update(double dtime) override ;

    /**
     * \brief Функция, уничтожающая башню
     */

    void Die();
};

/**
 * \brief Интерфейс фабрики
 */

class IFactory {
public:
    virtual ~IFactory() = default;
    /**
     * \brief Создает башню
     * \param Указатель на игрока, на чьей стороне башня, и указатель на точку, на
     * которой башня находится
     * @return Указатель на созданную башню
     */
    virtual CTower* Create(CPoint*, CPlayer*) = 0;
    /**
     * \brief Возвращает время отката башни
     */
    virtual int GetCD() const = 0;  //added that
	/**
	 * \brief Возвращает стоимость башни
	 */
    virtual int GetCOST() const = 0; //added that
};



//------------------------------------------------------

/**
 * \brief Реализация Фабрики для обычной башни
 */

class CFactoryNormal : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 10;

public:
    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для дальнобойной башни
 */

class CFactoryLongRange : public IFactory {
private:
    const int HP = 50;
    const int DMG = 5;
    const int RADIUS = 200;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 15;

public:

    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для защитной башни
 */

class CFactoryProtective : public IFactory {
private:
    const int HP = 200;
    const int CD = 10;
    const int COST = 15;

public:

    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для ракетной установки
 */

class CFactoryMissile : public IFactory {
private:
    const int HP = 100;
	const int SKILL_CD = 30;
	const int CD = 30;
    const int COST = 25;

public:

    int GetCD() const override;

    int GetCOST() const override;

    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для башни поддержки
 */

class CFactorySupport : public IFactory {
private:
    const int HP = 100;
	const int RADIUS = 100;
	const double MULTIPLY = 2;

    const int CD = 10;
    const int COST = 15;

public:

    int GetCD() const override;
    int GetCOST() const override;

    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для мобильной башни
 */

class CFactoryMoving : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
	const int SKILL_CD = 20;

    const int CD = 40;
    const int COST = 25;

public:

    int GetCD() const override;

    int GetCOST() const override;

    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для хилящей башни
 */

class CFactoryHealer : public IFactory {
private:
    const int HP = 100;
    const int RADIUS = 200;
    const int HEAL_SPEED = 5;
    const int CD = 20;
    const int COST = 20;

public:

    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для добывающей башни
 */

class CFactoryEnlarger : public IFactory {
private:
    const int HP = 100;
	const int ENLARGE_SPEED = 10;
    const int CD = 20;
    const int COST = 20;

public:


    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для генератора
 */

class CFactoryGenerator : public IFactory { //do something with generating
private:
    const int HP = 100;
	const int ENLARGE_SPEED = 5;
    const int CD = 10;
    const int COST = 10;

public:

    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};

/**
 * \brief Реализация Фабрики для базы
 */

class CFactoryBase : public IFactory {
private:
    const int HP = 100;
    const int DMG = 5;
    const int RADIUS = 100;
    const double ATTACK_CD = 0.5;
    const int CD = 10;
    const int COST = 10;

public:

    int GetCD() const override;
    int GetCOST() const override;
    CTower* Create(CPoint*, CPlayer*) override;
};
//****************************************************
