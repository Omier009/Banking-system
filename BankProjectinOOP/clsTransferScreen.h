#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumber(string Massage)
    {
        string AccountNumber = "";
        cout << Massage;
        cin >> AccountNumber;

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "Account Number not found. \n"
                "Please enter another Account Number: ";

            cin >> AccountNumber;
        }
        return AccountNumber;
    }

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

        string Massage = "\nPlease enter Account Number to Transfer from: ";
       clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber(Massage));

       _PrintClient(SourceClient);

       Massage = "\nPlease enter Account Number to Transfer to: ";

       clsBankClient DistinationClient = clsBankClient::Find(_ReadAccountNumber(Massage));

       _PrintClient(DistinationClient);

       cout << "\nEnter Transfer Amount? ";
       float Amount = clsInputValidate::ReadFloatNumberBetween(0,SourceClient.AccountBalance,
           "\nAmount Exceeds the available Balance, Enter another Amount ? ");

       char Answer = 'n';
       cout << "\nAre you sure you want to perform this Operation y/n ? ";
       cin >> Answer;

       if (Answer == 'y' || Answer == 'Y')
       {
           if (SourceClient.Transfer(Amount, DistinationClient))
           {
               cout << "\nTransfer done successfully (-:\n";
               _PrintClient(SourceClient);
               _PrintClient(DistinationClient); 
           }
          else
            cout << "\nTransfer Failed n";
          
       }
	}

};

