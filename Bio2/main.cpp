#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void FreqPattern(char* DNK, int pattern)
{
	int max = -1;
	int Rez = 1;
	int k = 0;
	int* count = new int [strlen(DNK) - pattern + 1];
	char** buf = new char*[strlen(DNK) - pattern + 1];
	for (int i = 0; i < (strlen(DNK) - pattern + 1); i++)
	{
		count[i] = 1;
		buf[i] = new char[pattern];
		if (i == 0)
		{
			strncpy(buf[0], DNK, pattern);
		}
		else
		{
			strncpy_s(buf[i], pattern+1, DNK + i, pattern);
			for (int j = 0; j < i; j++)
			{
				if (!strcmp(buf[i],buf[j]))
				{
					Rez++;
					if (Rez >= max)
					{
						max = Rez;
						count[k]=j;
						k++;
					}
				}
			}
		}
	}
	ofstream fout("output.txt");
	for (int j = 0; j < k; j++)
	{
		cout << Rez << " -- " << buf[count[j]] << endl;
		fout << Rez << " -- " << buf[count[j]] << endl;	
	}
	fout.close();
	delete[] count;
	
}

int main()
{

	const int len = 50;
	char DNK[len];
	int pattern;

	ifstream fin("input.txt");
	fin >> pattern;
	cout << pattern << endl;
	fin >> DNK;
	cout << DNK << endl;
	fin.close();
	FreqPattern(DNK, pattern);
	return 0;
}