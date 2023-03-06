
#include"header.h++"

int	findstr(string s1, string s2)
{
	int i, x, lenght1, lenght2;

	i = 0;
	lenght1 = s1.length();
	lenght2 = s2.length();
	while(i != lenght1)
	{
		x = 0;
		if (s1[i] == s2[x])
		{
			while (x != lenght2 && s1[i + x] == s2[x])
				x++;
			if (x == lenght2)
				return (i);
		}
		i++;
	}
	return (-1);
}

string	to_lower(string src)
{
	for ( int i = 0; i < src.length(); i++)
		src[i] = tolower(src[i]);

	return(src);
}

void	grep_with_options(char **argv, options chosen_options)
{
	fstream file;
	string source, find_str;
	int	line_nbr = 0, occurance = 0, str_found;
	
	if (chosen_options.i == 1)
		find_str = to_lower(argv[2]);
	else
		find_str = argv[2];
	
	file.open(argv[3], ios::in);
	if(!file)
	{
		cout << "Error opening the file, file does not exist or you don't have access to the file";
		exit(0);
	}
	while(getline(file, source))
	{
		line_nbr++;
		if (chosen_options.i == 1)
			source = to_lower(source);
		str_found = findstr(source, find_str);
		if (str_found != -1 && chosen_options.r != 1)
		{
			if (chosen_options.l == 1)
				cout << line_nbr << ":" << source << endl;
			else
				cout << source << endl;
			occurance++;
		}
		else if (chosen_options.r == 1 && str_found == -1)
		{
			if (chosen_options.l == 1)
				cout << line_nbr << ":" << source << endl;
			else
				cout << source << endl;
			occurance++;
		}
	}
	if(chosen_options.o == 1 && chosen_options.r == 0)
		cout << "\nOccurances of lines containing \"" << find_str << "\": " << occurance;
	else if (chosen_options.o == 1 && chosen_options.r == 1)
		cout << "\nOccurances of lines not containing \"" << find_str << "\": " << occurance;
}
 