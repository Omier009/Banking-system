#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrencyScreen : protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card:";
		cout << "\n______________________________________\n";
		cout << "\nCountry   : " << Currency.GetCountry();
		cout << "\nCode      : " << Currency.GetCurrenyCode();
		cout << "\nName      : " << Currency.GetCurrencyName();
		cout << "\nRate(1$)  : " << Currency.GetRate();
		cout << "\n______________________________________\n";

	}

	static clsCurrency _FindCurrency()
	{
		string Code;

		cout << "\nPlease enter Currency Code: ";	
		Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);
		while (Currency.IsEmpty())
		{
			cout << "\nCurrency Code not exist, Please enter another Currency Code: ";
			 Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
		}
		return Currency;
	}

	static float _ReadNewRate()
	{
		cout << "\nUpdate Currency Rate:\n";
		cout << "-------------------------";
		cout << "\nEnter new Rate: ";
		return clsInputValidate::ReadFloatNumber();
	}

public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		clsCurrency Currency = _FindCurrency();

		_PrintCurrencyCard(Currency);

		char Answer = 'n';

		cout << "Are you sure you want to update the rate of this Currency y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			Currency.UpdateRate(_ReadNewRate());

			cout << "\nCurrency Rate updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nUpdate Currency Operation failed..";
		}
	}
};

