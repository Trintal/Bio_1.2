#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<char> ACGT = { 'A', 'C', 'G', 'T' };

int CharIndex(vector<char> alphabet, char c);

vector<string> motifSearch(string *DNA, int num, int size, int n)
{
	int global_score = 0;

	int* max = new int[size];
	string consensus;
	consensus.resize(size);
	vector<string> B(num);

	char**A = new char*[4];
	for (int i = 0; i < 4; i++)
			A[i] = new char[size];

	vector<string> Output(num);
	int *ind = new int[num];
	for (int i = 0; i < num; i++)
		ind[i] = 0;

	int Pos = pow(n - size + 1, num); 
	for (int i = 0; i < Pos; i++)
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < size; j++)
				A[i][j] = 0;


		for (int j = 0; j < num; j++)
		{
			B[j] = DNA[j].substr(ind[j], size);
		}

		//Fill 
		for (int k = 0; k < size; k++)
		{
			for (int j = 0; j < num; j++)
			{
				A[CharIndex(ACGT, toupper(B[j][k]))][k]++;
			}
		}
		int score = 0;
		for (int k = 0; k < size; k++)
		{
			max[k] = A[0][k];
			consensus[k] = ACGT[0];
			for (int j = 0; j < 4; j++)
			{
				if (A[j][k] > max[k])
				{
					max[k] = A[j][k];
					consensus[k] = ACGT[j];
				}
			}
			score += max[k];
		}
		if (score == global_score)
		{
			Output = B;
		}
		else
		{
			if (score > global_score)
			{
				global_score = score;
				Output.clear();
				Output = B;
				cout << "New max score:" << global_score << endl;
			}
		}


		for (int j = 0; j < num; j++)
		{
			ind[j]++;
			if (ind[j] < (n - size + 1))
				break;
			ind[j] = 0;
		}

	}
	delete[] max;
	delete[] ind;
	B.clear();
	for (int i = 0; i < 4; i++)
		delete[] A[i];
	delete[] A;
	return Output;
}

int CharIndex(vector<char> alphabet, char c)
{
	for (int i = 0; i < alphabet.size(); i++)
		if (alphabet[i] == c)
			return i;
	return -1;
}

int main()
{
	string* DNA;
	vector<string> motifs;
	int num, size;
	ifstream fin("input.txt");
		fin >> size; 
		cout << size;
		fin >> num;
		cout << num;
	DNA = new string[num];
	int i = 0;

	DNA = new string[num];
	for (int i = 0; i < num; i++)
	{
		fin >> DNA[i];
		cout << DNA[i] << endl;
	}
	//Alghorithm
	motifs = motifSearch(DNA, num, size, DNA[0].size());
	//Output
	for (int i = 0; i < motifs.size(); i++)
		cout << motifs[i] << endl;

	delete[] DNA;
	return 0;
}