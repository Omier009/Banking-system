#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCalculatorScreen.h"
#include <iomanip>
#include "clsInputValidate.h"

class clsCurrencyMainScreen : protected clsScreen
{
private:
  
	enum enCurrencyMenuOptions
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate =3 , CurrencyCalculator = 4,
		eMainMenu = 5
	};

    static short _ReadCurrencyExchangeMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do [1 to 5] ? ";
        return clsInputValidate::ReadShortNumberBetween(1, 5,"\n\t\t\t\t    Please Enter a Number between 1 and 5 ? ");
    }

    static void _GoBackToCurrencyExchangeMenu()
    {
        cout << setw(37) << left << "" "\n\nPress any key to go back to Currency exchange menu..";
        system("pause>0");

        system("cls");
        ShowCurrencyMainScreen();
    }

    static void _ShowCurrencyListScreen()
    {
        clsCurrencyListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        /*cout << "\nFind Currency Screen will be here";*/
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        /*cout << "\nUpdate Rate Screen will be here";*/
        clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        /*cout << "\nCurrency Calculator Screen will be here";*/
        clsCalculatorScreen::ShowCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenuOption(enCurrencyMenuOptions Option)
    {
        switch (Option)
        {
        case enCurrencyMenuOptions::eListCurrencies:

            system("cls");
            _ShowCurrencyListScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyMenuOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyMenuOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyMenuOptions::CurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeMenu();
            break;

        case enCurrencyMenuOptions::eMainMenu:
        {

        }
        }
    }

public:
  
	static void ShowCurrencyMainScreen()
	{
        _DrawScreenHeader("   Currency exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenuOption(enCurrencyMenuOptions(_ReadCurrencyExchangeMenuOption()));
	}
};

