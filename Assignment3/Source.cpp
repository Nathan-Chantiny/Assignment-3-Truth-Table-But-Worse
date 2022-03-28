#include <iostream>

using namespace std;

string TorF;

bool A;
bool B;
bool C;
bool ABC[8][3] = {
	{0,0,0},
	{0,0,1},
	{0,1,0},
	{0,1,1},
	{1,0,0},
	{1,0,1},
	{1,1,0},
	{1,1,1}
};

void boolsAndStatements(int row, int position) {
	A = ABC[row][0];
	B = ABC[row][1];
	C = ABC[row][2];

	if (position == 0 && (!(A || C) ^ B)) {
		TorF = "True";
	}
	else if (position == 1 && !((!B || C) && !(A || B))) {
		TorF = "True";
	}
	else if (position == 2 && (!(A ^ B) || !(B ^ C))) {
		TorF = "True";
	}
	else if (position == 3 && (!(!A || B) || !C)) {
		TorF = "True";
	}
	else {
		TorF = "False";
	}
	cout << A << "    " << B << "    " << C << "    " << TorF << endl;
}

int main() {
	cout << "(A nor C) xor B" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 0);
	}

	cout << "\n(B implies C) nand (A nor B)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 1);
	}

	cout << "\n(A xor B) implies (B xnor C)" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 2);
	}

	cout << "\n(A implies B) implies !C" << endl;
	cout << "A    B    C    bool" << endl;
	for (int row = 0; row < 8; row++) {
		boolsAndStatements(row, 3);
	}
}