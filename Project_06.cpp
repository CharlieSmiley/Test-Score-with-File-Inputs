//
//Program Title: Test Averages
//Project File: Project_06.cpp
//Name: Charlie Smiley
//Course Section: CPE-211-02
//Lab Section: 1
//Due Date: 10/05/21
//
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	//File Stream Varibles
	ifstream Infile;
	ofstream Outfile;
	
	//Testing for correct # of command line arguments
	if(argc !=3)
	{
		cout << endl;
		cout << string(9,'*') << ' Command Line Argument Error ' << string(9,'*') << endl;
		cout << '==> Incorrect number of Command Line Argument Error!\n';
		cout << '==> Command for running the program is:\n';
		cout << '==./Project_06 inputFileName outFileName\n';
		cout << string(47,'*') << endl << endl;
		return 1;
	}

	//Prompt for Infile Name
	string IFN;
	cout << endl;
	cout << 'Opening Input Tile: ';
	cin >> IFN;
	cout << IFN << endl << endl;
	Infile.open(IFN);

	//Input Error
	while(Infile.fail())
	{
		cout << endl;
		cout << string(15,'*') << 'File Open Error' << string(15,'*') << endl;
		cout << '==> Input file failed to open properly!!\n';
		cout << '==> Attempted to open file: ' << IFN << endl;
		cout << '==> Try Again\n';
		cout << string(47,'*') << endl << endl;

		Infile.clear();

		cout << 'Opening Input file: ';
		cin << IFN << endl << endl;
		Infile.open(IFN);
	}

	//Prompt for Outfile Name
	string OFN;
	cout << endl;
	cout << 'Opening Output File: ';
	cin >> OFN;
	cout << OFN << endl << endl;
	Outfile.open(OFN);

	//Output Error
	while(Outfile.fail())
	{
		cout << endl;
		cout << string(15,'*') << ' File Open Error ' << string(15,'*') << endl;
		cout << '==> Output file failed to open properly!!\n';
		cout << '==> Attempted to open file: ' << OFN << endl;
		cout << '==> Try Again\n';
		cout << string(47,'*') << endl << endl;

		Outfile.clear();

		cout << 'Opening Output File: ';
		cin >> OFN >> endl >> endl;
		Outfile.open(OFN);
	}

	//Test Scores
	int T1;
	Infile.ignore(INT_MAX,'\n');
	Infile >> T1;

	int T2;
	Infile.ignore(INT_MAX,T1);
	Infile >> T2;

	int T3;
	Infile.ignore(INT_MAX,T2);
	Infile >> T3;

	int T4;
	Infile.ignore(INT_MAX,T3);
	Infile >> T4;

	//Error Message
	if(Infile.fail())
	{
		Outfile << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		Outfile << '==> Reading of the 4 test scores failed.' << endl;
		Outfile << '==> The input stream is in the fail state mode.' << endl;
		Outfile << '==> There is an error in the input file.' << endl;
		Outfile << '==> Program Terminated.' << endl;
		Outfile << string(47,'*') << endl;

		cout << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		cout << '==> Reading of the 4 test scores failed.' << endl;
		cout << '==> The input stream is in the fail state mode.' << endl;
		cout << '==> There is an error in the input file.' << endl;
		cout << '==> Program Terminated.' << endl;
		cout << string(47,'*');
		return 1;
	}

	if(T1<0||T2<0||T3<0||T4<0)
	{
		Outfile << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		Outfile << '==> Test Scores are: ' << T1 << T2 << T3 << T4 << endl;
		Outfile << '==> One or more of the scores is negative!' << endl;
		Outfile << '==> Program Terminated.' << endl;
		Outfile << string(47,'*') << endl;

		cout << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		cout << '==> Test Scores are: ' << T1 << T2 << T3 << T4 << endl;
		cout << '==> One or more of the scores is negative!' << endl;
		cout << '==> Program Terminated.' << endl;
		cout << string(47,'*');
		return 1;
	}

	//Sum and avg of the scores
	float sum;
	sum=(T1+T2+T3+T4);

	float avg;
	avg=(sum/4.00);

	//Variance
	float V1,V2,V3,V4;
	V1=pow(T1-avg,2.0);
	V2=pow(T2-avg,2.0);
	V3=pow(T3-avg,2.0);
	V4=pow(T4-avg,2.0);

	float var;
	var=(V1+V2+V3+V4)/3.0;

	//Deviation
	float sd;
	sd=sqrt(var);
	
	//Letter Grade
	char lg;
	if(avg>=90)
	{
		lg='A';
	}
	else if(avg<90 && avg>=80)
	{
		lg='B';
	}
	else if(avg<80 && avg>=70)
	{
		lg='C';
	}
	else if(avg<70 && avg>=60)
	{
		lg='D';
	}
	else(avg<60)
	{
		lg='F';
	}

	//Information Line
	string Info;
	Infile.ignore(INT_MAX,T4);
	Getline(Info);

	//Error Message
	if(Infile.fail())
	{
		Outfile << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		Outfile << '==> Reading of the information line failed.' << endl;
		Outfile << '==> The input stream is in the fail state mode.' << endl;
		Outfile << '==> There is an error in the input file.' << endl;
		Outfile << '==> Program Terminated.' << endl;
		Outfile << string(47,'*') << endl;

		cout << string(15,'*') << ' File Read Error ' << string(15,'*') << endl;
		cout << '==> Reading of the information line failed.' << endl;
		cout << '==> The input stream is in the fail state mode.' << endl;
		cout << '==> There is an error in the input file.' << endl;
		cout << '==> Program Terminated.' << endl;
		cout << string(47,'*');
		return 1;
	}

	//Outfile text
	Outfile << string(17,'*') << '   Statistics   ' << string(17,'*') << endl;
	Outfile << setw(32) << left << Info << setw(6) << left << T1 << setw(6) << left << T2 << setw(6) << left << T3 << setw(6) << left << T4 endl;
	Outfile << setw(32) << left << 'The Sum of the score is:' << fixed << setprecision(2) << sum << endl;
	Outfile << setw(32) << left << 'The average of the score is:' << fixed << setprecision(2) << avg << endl;
	Outfile << setw(32) << left << 'Letter grade equivalent:' << fixed << setprecision(2) << lg << endl;
	Outfile << setw(32) << left << 'The variance of the score is:' << fixed << setprecision(2) << var << endl;
	Outfile << setw(32) << left << 'The standard deviation is:' << fixed << setprecision(2) << sd << endl;
	Outfile << string(50,'*') << endl;
	
	//Closing Files
	Infile.close();
	Outfile.close();
	
	return 0;
}
