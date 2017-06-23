#include <iostream>
#include "estruturas.cpp"

using namespace std;

int main () {
	Stack s1;
	int n;
	string res;
	s1 >> res;
	cout << res << endl;
	do {
		cin >> n;
		s1 << n;
	} while (n != 0);
	s1 >> res;
	cout << res << endl;
	int x;
	cout << "Type '0' to exit" << endl;
	cin >> x;
	while (x != 0) {
		try {
			s1 >> n;
		} catch (DataStructureException e) {
			cerr << e.what() << endl;
		}
		s1 >> res;
		cout << n << " was destacked!" << endl << res << endl;
		cin >> x;
	}
}