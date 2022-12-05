#pragma once

#include <initializer_list>

template<class T> // � ���� � ���� ������ ����???
class TableBody
{
	using Row = std::initializer_list<T>;
	using Body = std::initializer_list<Row>;

	Body* _body;
public:
	TableBody(Body body)
	{
		_body = &body;
	}

};