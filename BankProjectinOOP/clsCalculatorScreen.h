#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCalculatorScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n______________________________________\n";
		cout << "\nCountry   : " << Currency.GetCountry();
		cout << "\nCode      : " << Currency.GetCurrenyCode();
		cout << "\nName      : " << Currency.GetCurrencyName();
		cout << "\nRate(1$)  : " << Currency.GetRate();
		cout << "\n______________________________________\n";
	}

	static clsCurrency _FindCurrency()
	{
		clsCurrency Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
		while (Currency.IsEmpty())
		{
			cout << "\nCurrency Code not exist, Please enter another Currency Code: ";
			Currency = clsCurrency::FindByCode(clsInputValidate::ReadString());
		}
		return Currency;
	}

public:

	static void ShowCalculatorScreen()
	{
		_DrawScreenHeader("\t   Calculator Screen");

		cout << "\nPlease enter Currency1 Code: ";
		clsCurrency CurrencyFrom = _FindCurrency();

		cout << "\nPlease enter Currency2 Code: ";
		clsCurrency CurrencyTo = _FindCurrency();

		float Amount;
		cout << "\nEnter Amount to exchange: ";
		Amount = clsInputValidate::ReadFloatNumber();

		cout << "\n\nConvert From:";
		_PrintCurrencyCard(CurrencyFrom);

		cout << Amount << " " + CurrencyFrom.GetCurrenyCode() + " = " 
			<< CurrencyFrom.ConvertToUSD(Amount) << " USD\n\n";

		if (CurrencyTo.GetCurrenyCode() == "USD")
		{
			return;
		}	
		cout << "\n\nConverting From USD";
		cout << "\nTo:";

		_PrintCurrencyCard(CurrencyTo);
		cout << Amount << " " + CurrencyFrom.GetCurrenyCode() + " = " <<
		 CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo) << " " + CurrencyTo.GetCurrenyCode();

		char Answer = 'n';

		cout << "\n\nDo you want to perform another calculation y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			system("cls");
			ShowCalculatorScreen();
		}
	}
};

