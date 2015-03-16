#ifndef C_STRING
#define C_STRING
#pragma once

const short max_string_length = 1028;

class c_string
{	
	// might change this to a dyn_array in the future
	char m_data[max_string_length];
	short get_pointer_string_length(char* in_string);
public:
	c_string(char* in_string);
	~c_string();
	c_string operator=(char* in_string);

	void set_string(char* in_string);

	char* get_string(void)
	{
		return m_data;
	}

	void clear_string(void)
	{
		for (short index = 0; index < max_string_length; ++index)
		{
			m_data[index] = 0;
		}
	}
};

#endif //C_STRING