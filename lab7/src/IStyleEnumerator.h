#pragma once

#include <functional>
#include "ILineStyle.h"

template<typename T>
class IStyleEnumerator
{
public:
	typedef std::function<void(T& style)> Callback;

	virtual void EnumerateAll(const Callback& callback) const = 0;

	virtual ~IStyleEnumerator() = default;
};
