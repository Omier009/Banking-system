#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsCurrencyListScreen : protected clsScreen
{
private:
    static void PrintCurrencyRecord(clsCurrency CurrencyRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << CurrencyRecord.GetCountry();
        cout << "| " << setw(16) << left << CurrencyRecord.GetCurrenyCode();
        cout << "| " << setw(30) << left << CurrencyRecord.GetCurrencyName();
        cout << "| " << setw(10) << left << CurrencyRecord.GetRate();

    }


public:
    static void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        short CurrenciesSize = vCurrencies.size();

        string Title = "\tCurrencies List Screen",
            SubTitle = "\t   " + to_string(CurrenciesSize) + " Currencies";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(16) << "Currency Code";
        cout << "| " << left << setw(30) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (CurrenciesSize == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency& C : vCurrencies)
            {

                PrintCurrencyRecord(C);
                cout << '\n';
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



    }
};

