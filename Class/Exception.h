#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

template <class T>
class Exception
{
private:
	T type;

public:
	Exception(T type) { this->type = type; };
	~Exception() {};

	T leType() { return type; };
};
#endif