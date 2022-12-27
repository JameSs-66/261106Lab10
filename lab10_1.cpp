#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){	
	double loanAmount, interestRate, payAmount;

	cout << "Enter initial loan: ";
	cin >> loanAmount;
	cout << "Enter interest rate per year (%): ";
	cin >> interestRate;
	cout << "Enter amount you can pay per year: ";
	cin >> payAmount;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";

	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect

	int year = 1;
	double prevBal = loanAmount, 
	inter = loanAmount * interestRate/100.00, 
	total = loanAmount + inter, 
	paym = payAmount, 
	newBal = total - paym;

	while(true){
		if (newBal <= 0){
			newBal = 0;
		}
		if (paym >= total){
			paym = total;
		}
		cout << fixed << setprecision(2); 
		cout << setw(13) << left << year; 
		cout << setw(13) << left << prevBal ;
		cout << setw(13) << left << inter;
		cout << setw(13) << left << total;
		cout << setw(13) << left << paym;
		cout << setw(13) << left << newBal;
		cout << "\n";	

		if (newBal == 0 ) break;

		year++;
		prevBal = newBal;
		inter = prevBal * interestRate/100.00;
		total = prevBal + inter;
	
		newBal = total - paym;
		

	}
	
	return 0;
}
