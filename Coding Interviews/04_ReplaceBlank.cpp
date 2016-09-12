void replace_blank(char *cstr, int length)
{
	if (cstr == nullptr || length <= 0)
		return;
	unsigned origin_length = 0;
	unsigned number_blank = 0;
	for (auto i = 0; cstr[i] != '\0'; ++i)
	{
		++origin_length;
		if (cstr[i] == ' ')
			++number_blank;
	}
	unsigned new_length = origin_length + number_blank * 2;
	if (length < new_length)
		return;
	int index = origin_length;
	int new_index = new_length;
	while (index >= 0 && new_index > index)
	{
		if (cstr[index] == ' ')
		{
			cstr[new_index--] = '0';
			cstr[new_index--] = '2';
			cstr[new_index--] = '%';
		}
		else
		{
			cstr[new_index--] = cstr[index];
		}
		--index;
	}
}