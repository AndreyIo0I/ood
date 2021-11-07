#pragma once

#include "IBeverage.h"

// Базовая реализация напитка, предоставляющая его описание
class CBeverage : public IBeverage
{
public:
	CBeverage(const std::string & description)
		:m_description(description)
	{}

	std::string GetDescription()const override final
	{
		return m_description;
	}
private:
	std::string m_description;
};

// Кофе
class CCoffee : public CBeverage
{
public:
	CCoffee(const std::string& description = "Coffee")
		:CBeverage(description)
	{}

	double GetCost() const override
	{
		return 60;
	}
};

// Капучино
class CCappuccino : public CCoffee
{
public:
	CCappuccino(bool isDouble = false)
		: CCoffee(isDouble ? "Double Cappuccino" : "Cappuccino")
		, m_isDouble(isDouble)
	{}

	double GetCost() const override
	{
		return m_isDouble ? 120 : 80;
	}

	bool m_isDouble;
};

// Латте
class CLatte : public CCoffee
{
public:
	CLatte(const bool isDouble = false)
		: CCoffee("Latte")
		, m_isDouble(isDouble)
	{}

	double GetCost() const override
	{
		return m_isDouble ? 130 : 90;
	}

	bool m_isDouble;
};

enum class TeaType
{
	Black,
	Green,
	Red,
	Yellow,
};

std::string GetTeaTypeString(TeaType type)
{
	switch (type) {
		case TeaType::Black: return "Black";
		case TeaType::Green: return "Green";
		case TeaType::Red: return "Red";
		case TeaType::Yellow: return "Yellow";
	}
	return "";
}

// Чай
class CTea : public CBeverage
{
public:
	CTea(const TeaType name = TeaType::Black)
		:CBeverage(GetTeaTypeString(name) + " Tea")
	{}

	double GetCost() const override
	{
		return 30;
	}
};

enum class MilkshakeSize
{
	Big,
	Medium,
	Small,
};

std::string GetMilkshakeSizeString(MilkshakeSize type)
{
	switch (type) {
		case MilkshakeSize::Big: return "Big";
		case MilkshakeSize::Medium: return "Medium";
		case MilkshakeSize::Small: return "Small";
	}
	return "";
}

// Молочный коктейль
class CMilkshake : public CBeverage
{
public:
	CMilkshake(MilkshakeSize size = MilkshakeSize::Big)
		:CBeverage(GetMilkshakeSizeString(size) + " Milkshake")
		,m_size(size)
	{}

	double GetCost() const override
	{
		switch (m_size) {
			case MilkshakeSize::Big: return 80;
			case MilkshakeSize::Medium: return 60;
			default: return 50;
		}
	}

	MilkshakeSize m_size;
};