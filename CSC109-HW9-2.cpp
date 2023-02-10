#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
	istringstream inSS;
	string title;
	string header1;
	string header2;
	string datapointfull;
	string datapointName;
	string datapointFirst;
	string datapointmiddle;
	string datapointLast;
	int datapointNum;
	vector<int> numvals;
	vector<string> strvals;
	int commacount;
	bool isvalid;

	cout << "Enter a title for the data:" << endl;
	getline(cin, title);
	cout << "You entered: " << title << endl << endl;
	cout << "Enter the column 1 header:" << endl;
	getline(cin, header1);
	cout << "You entered: " << header1 << endl << endl;
	cout << "Enter the column 2 header:" << endl;
	getline(cin, header2);
	cout << "You entered: " << header2 << endl << endl;

	do
	{
		//datapointfull = "none";
		//datapointName = "none";
		//datapointNum = 0;
		cout << "Enter a data point (-1 to stop input):" << endl;
		getline(cin, datapointfull);
		datapointfull = datapointfull + '\n';
		commacount = 0;
		isvalid = false;
		for (int i = 0; datapointfull.at(i) != '\n'; i++)
		{
			if (datapointfull.at(i) == ',')
			{
				datapointfull.at(i) = ' ';
				commacount++;
			}
		}
		if (commacount != 1 && datapointfull != "-1\n")
		{
			if (commacount < 1)
			{
				cout << "Error: No comma in string." << endl << endl;
			}
			if (commacount > 1)
			{
				cout << "Error: Too many commas in input." << endl << endl;
			}
		}

		inSS.clear();
		inSS.str(datapointfull);

		inSS >> datapointFirst;
		inSS >> datapointLast;
		if (inSS.good())
		{
			inSS >> datapointNum;
			if (inSS.good())
			{
				isvalid = true;
				datapointName = datapointFirst + " " + datapointLast;
			}
			else
			{
				inSS.clear();
				inSS.str(datapointfull);
				inSS >> datapointFirst;
				inSS >> datapointmiddle;
				inSS >> datapointLast;
				inSS >> datapointNum;
				if (inSS.good())
				{

					isvalid = true;
					datapointName = datapointFirst + " " + datapointmiddle + " " + datapointLast;
				}
			}
		}
		if (isvalid == false && commacount == 1)
		{
			cout << "Error: Comma not followed by an integer." << endl << endl;
		}
		if (commacount == 1 && isvalid == true)
		{
			strvals.push_back(datapointName);
			numvals.push_back(datapointNum);
			cout << "Data string: " << datapointName << endl;
			cout << "Data integer: " << datapointNum << endl << endl;
		}

	} while (datapointfull != "-1\n");

	cout << endl << setw(33) << title << endl;
	cout << left << setw(20) << header1 << "|" << right << setw(23) << header2 << endl;
	cout << setfill('-') << setw(44) << "-" << endl;
	for (int i = 0; i < numvals.size(); i++)
	{
		cout << setfill(' ') << left << setw(20) << strvals.at(i) << "|" << right << setw(23) << numvals.at(i) << endl;
	}
	cout << endl;
	for (int i = 0; i < numvals.size(); i++)
	{
		cout << setfill(' ') << right << setw(20) << strvals.at(i) << " " << setw(numvals.at(i)) << setfill('*') << left << "*" << endl;
	}
}


