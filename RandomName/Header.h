#pragma once

#include <Windows.h>
#include <random>
#include <string>
#include <iostream>

/* Random name class */
class RandomNameClass
{
private:
	/* Alphabet and numbers array */
	const typedef std::wstring AlphabetAndNumbers;
	AlphabetAndNumbers Array = { L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890" };

	/* Function for generate */
	std::random_device RandomDevice;

	/* Output variables */
	std::wstring RandomString_wstring;
	std::string RandomString_string;

	/* Generate the random name */
	void Random() noexcept {
		std::mt19937 Generator(RandomDevice());
		std::uniform_int_distribution<> Distribution(0, Array.size() - 1);

		for (std::size_t i = 0; i < Array.size(); ++i)
			RandomString_wstring += Array[Distribution(Generator)];

		for (auto& Symbols : RandomString_wstring)
			RandomString_string += Symbols;
	}
public:

	/* Functions with the random name */
	LPCWSTR Name_LPCWSTR() noexcept {
		Random();
		return RandomString_wstring.c_str();
	}
	std::string Name_string() noexcept {
		Random();
		return RandomString_string;
	}
};
