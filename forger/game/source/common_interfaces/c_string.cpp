#include "c_string.h"

c_string::c_string(char* in_string)
{
	set_string(in_string);
}

c_string c_string::operator=(char* in_string)
{
	set_string(in_string);

	return *this;
}

void c_string::set_string(char* in_string)
{
	clear_string();
	short str_len = get_pointer_string_length(in_string);

	for (short index = 0; index < str_len; ++index)
	{
		m_data[index] = in_string[index];
	}
}

short c_string::get_pointer_string_length(char* in_string)
{
	short to_return = 0;

	for (short index = 0; index < max_string_length; ++index)
	{
		if (in_string[index] == 0)
		{
			break;
		}

		to_return++;
	}

	return to_return;
}