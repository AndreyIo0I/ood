﻿#pragma once

#include <set>
#include <functional>
#include <map>

/*
Шаблонный интерфейс IObserver. Его должен реализовывать класс, 
желающий получать уведомления от соответствующего IObservable
Параметром шаблона является тип аргумента,
передаваемого Наблюдателю в метод Update
*/
template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

/*
Шаблонный интерфейс IObservable. Позволяет подписаться и отписаться на оповещения, а также
инициировать рассылку уведомлений зарегистрированным наблюдателям.
*/
template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T> & observer, int priority = 0) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T> & observer) = 0;
};

// Реализация интерфейса IObservable
template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	CObservable()
	:m_observers(cmp)
	{
	}

	void RegisterObserver(ObserverType & observer, int priority = 0) override
	{
		m_observers.insert(&observer);
		std::cout << m_observers.size() << "#\n";
		m_observersPriority[&observer] = priority;
	}

	void NotifyObservers() override
	{
		m_notifyingObservers = true;
		T data = GetChangedData();
		for (auto & observer : m_observers)
		{
			observer->Update(data);
		}
		EraseObservers();
		m_notifyingObservers = false;
	}

	void RemoveObserver(ObserverType & observer) override
	{
		if (m_notifyingObservers)
		{
			m_observersToErase.insert(&observer);
		}
		else {
			m_observers.erase(&observer);
		}
	}

protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData()const = 0;

private:
	void EraseObservers()
	{
		for (auto & observer : m_observersToErase)
		{
			m_observers.erase(observer);
		}
		m_observersToErase.clear();
	}

	std::map<ObserverType*, int> m_observersPriority;
	std::function<bool(ObserverType*, ObserverType*)> cmp = [this](ObserverType* l, ObserverType* r){ return m_observersPriority[l] < m_observersPriority[r]; };
	std::set<ObserverType*, decltype(cmp)> m_observers;

	std::set<ObserverType*> m_observersToErase;
	bool m_notifyingObservers = false;
};
