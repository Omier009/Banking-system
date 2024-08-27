#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen : protected clsScreen
{
private:
    static void PrintTransferLogRecord(clsBankClient::stTransferLogData TransferLogData)
    {

        cout << setw(8) << left << "" << "| " << setw(21) << left << TransferLogData.DateTime;
        cout << "| " << setw(11) << left << TransferLogData.SClientAccountNumber;
        cout << "| " << setw(11) << left << TransferLogData.DClientAccountNumber;
        cout << "| " << setw(9) << left << TransferLogData.TransferAmount;
        cout << "| " << setw(9) << left << TransferLogData.SClientBalance;
        cout << "| " << setw(9) << left << TransferLogData.DClientBalance;
        cout << "| " << setw(9) << left << TransferLogData.CurrentUsername;
    }

public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogData> vData = clsBankClient::GetTransferLogData();
		short TransferLogRecords = vData.size();

		string Title = "\tTransfer Log List Screen",
			SubTitle = to_string(TransferLogRecords)+"Record(s)";

		_DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(21) << "Date/Time";
        cout << "| " << left << setw(11) << "s.Acct";
        cout << "| " << left << setw(11) << "d.Acct";
        cout << "| " << left << setw(9) << "Amount";
        cout << "| " << left << setw(9) << "s.Balance";
        cout << "| " << left << setw(9) << "d.Balance";
        cout << "| " << left << setw(9) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (TransferLogRecords == 0)
            cout << "\t\t\t\tNo Transfer Log Records Available In the System!";
        else

            for (clsBankClient::stTransferLogData&Record : vData)
            {

                PrintTransferLogRecord(Record);
                cout << '\n';
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



	}
};

