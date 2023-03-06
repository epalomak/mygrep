
#include"header.h++"

int		main(int argc, char **argv)
{
	fstream file;
	string source, find_str;

	if (argc == 1)
	{
		int x;
		cout << "Give a string from which to search for: ";
		getline(cin, source);
		cin.clear();

		cout << "Give search string: ";
		getline(cin, find_str);
		x = findstr(source, find_str);
		if (x != -1)
			cout << "\"" << find_str << "\"" << " found in " << "\"" << source << "\"" << " in position " << x << endl;
		else
			cout << "\"" << find_str << "\"" << " NOT found in " << "\"" << source << "\"" << endl;
	}
	
	else if (argc == 3)
	{
		find_str = argv[1];
		file.open(argv[2], ios::in);
		if(!file)
			cout << "Error opening the file, file does not exist or you don't have access to the file";
		while(getline(file, source))
			if (findstr(source, find_str) != -1)
				cout << source << endl;
	}

	else if (argc == 4)
	{
		options chosen_options;
		int i = 0, count = 0;
		while(argv[1][i])
		{
			if(argv[1][1] != 'o' || argv[1][0] != '-')
			{
				cout << "Error, missing initial o or - from the commandline";
				exit(0);
			}
			if(argv[1][i] == 'o')
				count++;
			i++;
		}		
		if (count == 2)
			chosen_options.o = 1;
		if(strchr(argv[1], 'l'))
			chosen_options.l = 1;
		if(strchr(argv[1], 'i'))
			chosen_options.i = 1;
		if(strchr(argv[1], 'r'))
			chosen_options.r = 1;
		grep_with_options(argv, chosen_options);
	}

}