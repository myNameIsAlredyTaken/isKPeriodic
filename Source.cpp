#include <iostream>

using namespace std;

void findLps(const string& pat, int* lps) {
	lps[0] = 0;

	int i = 1, j = 0;
	while (i < pat.size()) {
		if (pat[i] == pat[j]) {
			j++;
			lps[i] = j;
			i++;
		} 
		else {
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool isKPeriodic(const string& txt, int mlt) {
	if (txt.size() % mlt != 0)
		return 0;

	string pat;
	for (int i = 0; i < mlt; i++)
		pat += txt[i];
	int* lps = new int[pat.size()];
	int count = 0;

	findLps(pat, lps);

	int i = 0, j = 0;
		while (i < txt.size()) {
			if (txt[i] == pat[j]) {
				i++;
				j++;
			}
			if (j == pat.size()) {
				count++;
				j = lps[j - 1];
			}
			else if (i < txt.size() && pat[j] != txt[i]) {
				if (j != 0)
				{
					j = lps[j - 1];
				}
				else {
					i = i + 1;
				}
			}
		}
	if (txt.size() / count == mlt) {
		return 1;
	}
	return 0;
}

int main(void)
{
	string txt;
	int mlt = -1;
	cout << "Input string: ";
	cin >> txt;
	while (mlt <= 0) {
	cout << "Input multiplicity (>0): ";
		cin >> mlt;
	}
	cout << isKPeriodic(txt, mlt);
	return 0;
}