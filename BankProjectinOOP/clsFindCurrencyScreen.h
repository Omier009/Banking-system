#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
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


public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("\t  Find Currency Screen");

        cout << "Find By: [1] Code or [2] Country ? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 2, "\nPlease enter a choice between 1 and 2 ? ");

        
        clsCurrency Currency = clsCurrency::GetEmptyCurrencyObject();

        if (Choice == 1)
        {
            string Code;
            cout << "\n\nPlease enter Currency Code: ";
            cin >> Code;
            Currency = clsCurrency::FindByCode(Code);
        }
        else
        {
            string CountryName;
            cout << "\n\nPlease enter Country Name: ";
            cin >> CountryName;
            Currency = clsCurrency::FindByCountry(CountryName);
        }

        if (!Currency.IsEmpty())
        {
            cout << "\n\nCurrency Found (-:";
            _PrintCurrencyCard(Currency);

        }
        else
        {
            char Answer = 'n';
            cout << "\n\nCurrency is not found ";

            cout << "\nDo you want to Find another Currency y/n ? ";
            cin >> Answer;

            if (Answer == 'y' || Answer == 'Y')
            {
                system("cls");
                ShowFindCurrencyScreen();
            }
        }

    }
};

