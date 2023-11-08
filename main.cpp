// Program: Student DB using 2d arrays
// Programmer: M Maaz Ahmad
// Compiler: Microsoft Visual Studio Community Edition 2022

#include <iostream>
#include <string>
#define MAX 70
using namespace std;

// get students data from the user
void readData(int mks[][7], string nname[], int& nn) {
	cout << "Enter number of students, you want to enter: ";
	cin >> nn;
	
	for (int i = 0; i < nn; i++) {
		cout << endl << "Enter student " << i + 1 << " regirstion number: ";
		cin >> mks[i][0];
		cout << endl << "Enter student " << i + 1 << " name: ";
		cin.ignore(); // to ignore whitespace character left in the buffer by cin
		getline(cin, nname[i]);
		// getting subject marks
		for (int j = 1; j <= 5; j++)
		{
			do {
				int tempMks;
				cout << endl << "Enter student " << i + 1 << " Subject " << j << " marks: ";
				cin >> tempMks;
				if (tempMks >= 0 && tempMks <= 100)
				{
				mks[i][j] = tempMks;
				break;
				}
				else
					cout << "Invalid Marks. Enter marks between 0-100";
			} while (true);
		}
		cout << endl << "===================================================";
	}
	cout << endl;
}

// appending data at the end only if the data is available
void appendData(int mks[][7], string nname[], int& nn) {
	if (nn > 0)
	{
		cout << endl << "Enter student " << nn + 1 << " regirstion number: ";
		cin >> mks[nn][0];
		cout << endl << "Enter student " << nn + 1 << " name: ";
		cin.ignore(); // to ignore whitespace character left in the buffer by cin
		getline(cin, nname[nn]);
		for (int j = 1; j <= 5; j++)
		{
			do {
				int tempMks;
				cout << endl << "Enter student " << nn + 1 << " Subject " << j << " marks: ";
				cin >> tempMks;
				if (tempMks >= 0 && tempMks <= 100)
				{
					mks[nn][j] = tempMks;
					break;
				}
				else
					cout << "Invalid Marks. Enter marks between 0-100";
			} while (true);
		}
		cout << endl << "===================================================";
		nn++;
	}
	else {
		cout << endl << "No Data available. Please, insert some data.";
	}
}

// generating student result data
void resultGen(int mks[][7], double prc[], int nn) {
	if (nn == 0)
		cout << "No Data available. Please, insert some data.";
	else {
		for (int i = 0; i < nn; i++) {
			int mksSum = 0;
			for (int j = 1; j <= 5; j++) {
				mksSum += mks[i][j];
			}
			mks[i][6] = mksSum;
			prc[i] = (mksSum / 500.0) * 100;
		}
	}
}

// showing student result data
void resultShow(int mks[][7], double prc[], string nname[], int nn) {
	if (nn == 0)
		cout << "No Data available. Please, insert some data.";
	else
	{
		cout << "Name\t" << "\t\t\tReg #\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t"
			<< "MKS OBT\t" << "Percentage" << endl
			<< "----------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < nn; i++) {
			cout << nname[i] << "\t\t\t\t" << mks[i][0] << "\t" << mks[i][1] << "\t" << mks[i][2] << "\t" << mks[i][3] << "\t"
				<< mks[i][4] << "\t" << mks[i][5] << "\t" << mks[i][6] << "\t" << prc[i] << "%\t" << endl;
		}
	}
}

// searching a specific record and returning its index in the array
int searchRec(int mks[][7], string nname[], int nn) {
	int sInfo;
	int sPos = -1;
	if (nn == 0)
		cout << "No Data available. Please, insert some data." << endl;
	else {
		cout << endl << "Enter reg no. of student: ";
		cin >> sInfo;
		for (int i = 0; i < nn; i++) {
			if (sInfo == mks[i][0]) {
				sPos = i;
				break;
			}
		}
		return sPos;
	}
}

// deleting the student record by getting the index of the specific student
void delRecord(int mks[][7], double prc[], string nname[], int& n) {
	if (n == 0)
		cout << endl << "No Data available. Please, insert some data." << endl;
	else {
		int delPos = searchRec(mks, nname, n);
		if (delPos == -1)
			cout << endl << "Not found for Deletion" << endl;
		else {
			for (int i = delPos; i < n - 1; i++) {
				for(int j = 0; j < 7; j++)
					mks[i][j] = mks[i + 1][j];
				nname[i] = nname[i + 1];
				prc[i] = prc[i + 1];
			}
			n--;
			cout << endl << "Operation Successful!" << endl;
		}
	}
		
}

// tester
int main() {
	int marks[MAX][7];
	string name[MAX];
	double perc[MAX];
	int n=0;
	char ch;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < 7; j++)
			marks[i][j] = 0;
	}

	do {
		cout << endl << "----------------****----------------" << endl
			<< "1. Add or Append Data" << endl
			<< "2. Display Result Card" << endl
			<< "3. Search a particular Record" << endl
			<< "4. Delete a Record" << endl
			<< "5. Exit" << endl
			<< "----------------****----------------" << endl;

		cout << "Enter your choice: ";
		cin >> ch;
		cout << endl;
		switch (ch) {
		case '1':
			if (n == 0)
				readData(marks, name, n);
			else
				appendData(marks, name, n);
			break;
		case '2':
			resultGen(marks,perc, n);
			resultShow(marks, perc, name, n);
			break;
		case '3':
			int sPos;
			resultGen(marks, perc, n);
			sPos = searchRec(marks, name, n);
			if (n != 0)
			{
				cout << "Name\t" << "\t\t\tReg #\t" << "Subj 1\t" << "Subj 2\t" << "Subj 3\t" << "Subj 4\t" << "Subj 5\t"
					<< "MKS OBT\t" << "Percentage" << endl
					<< "----------------------------------------------------------------------------------------------------" << endl;
				cout << name[sPos] << "\t\t\t\t" << marks[sPos][0] << "\t" << marks[sPos][1] << "\t" << marks[sPos][2] << "\t" << marks[sPos][3] << "\t"
					<< marks[sPos][4] << "\t" << marks[sPos][5] << "\t" << marks[sPos][6] << "\t" << perc[sPos] << "%\t" << endl;
			}
			break;
		case '4':
			delRecord(marks, perc, name, n);
			break;
		case '5':
			exit(-1);
			break;
		default:
			cout << "Invalid Input" << endl;
		}
	} while (true);
}
// end of main
