#ifndef Value_H
#define Value_H

enum class Value {
	SEVEN = 7,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,

	First = Value::SEVEN,
	Last = Value::ACE
};

#endif