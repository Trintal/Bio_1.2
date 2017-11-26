#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int Count(string &DNK, string &pattern) {
	int count = 0;
	for (int i = 0; i < DNK.length() - pattern.length() + 1; i++) {
		if (DNK.substr(i, pattern.length()) == pattern) count++;
	}
	return count;
}


string FreqPattern(string DNK, int pattern)
{
	int max = 0;
	string Rez;
	int* count = new int [DNK.size() - pattern + 1];
	for (int i = 0; i < (DNK.size() - pattern + 1); i++)
	{
		count[i] = Count(DNK, DNK.substr(i,pattern));
			//if ((DNK.substr(i, (DNK.substr(i, pattern)).length())) == DNK.substr(i, pattern))
				//count[i]++;

		if (count[i] > max)
		{
			max = count[i];
		}
	}
	for (int i = 0; i < (DNK.size() - pattern + 1); i++)
		if (max == count[i])
			Rez += DNK.substr(i, pattern);

	for (int i = 0; i < Rez.length(); i += pattern)
		for (int j = 0; j < Rez.length() - pattern; j += pattern)
			if (Rez.substr(i, pattern) == Rez.substr(j, pattern))
				Rez.erase(j, pattern);

	return Rez;
}

int main()
{

	string DNK;
	int pattern;
	string k;

	ifstream fin("input.txt");
	fin >> pattern;
	cout << pattern << endl;
	fin >> DNK;
	cout << DNK << endl;
	fin.close();

	k = FreqPattern(DNK, pattern);
	ofstream fout("output.txt");
	fout << k;
	fout.close();
	//FreqPattern(DNK, pattern);
	return 0;
}