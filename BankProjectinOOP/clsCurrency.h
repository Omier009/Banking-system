#pragma once
#include "clsUtil.h"
#include "clsString.h"
#include <fstream>

using namespace std;

class clsCurrency
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country, _CurrencyCode, _CurrencyName;
    float _Rate;

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency , string Delim = "#//#")
    {
        string Line = "";

        Line += Currency.GetCountry() + Delim;
        Line += Currency.GetCurrenyCode() + Delim;
        Line += Currency.GetCurrencyName() + Delim;
        Line += to_string(Currency.GetRate()) + Delim;

        return Line;
    }

    static clsCurrency _ConvertLineToCurrencyObject(string Line)
    {
        vector <string> vData = clsString::Split(Line, "#//#");

        return clsCurrency(UpdateMode, vData[0], vData[1], vData[2], stof(vData[3]));
    }

    static vector <clsCurrency>  _LoadCurrenciesDataFromFile()
    {
        vector <clsCurrency> vCurrencies;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                vCurrencies.push_back(Currency);
            }

            MyFile.close();

        }

        return vCurrencies;
    }

    static void _SaveCurrenciesToFile(vector <clsCurrency> &vCurrencies)
    {
        fstream MyFile;

        MyFile.open("Currencies.txt", ios::out);
        
        if (MyFile.is_open())
        {
            string Line;
            for (clsCurrency& Currency : vCurrencies)
            {
                 Line = _ConvertCurrencyObjectToLine(Currency);
                 MyFile << Line << '\n';
            }
           
        }
    }

    void _Update()
    {
        vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

        for (clsCurrency& C : vCurrencies)
        {
            if (C.GetCountry() == this->GetCountry())
            {
                C = *this;
                break;
            }
        }

        if(vCurrencies.size())
        _SaveCurrenciesToFile(vCurrencies);
    }

    static clsCurrency _GetEmptyCurrencyObject()
    {
        return clsCurrency(EmptyMode, "", "", "", 0);
    }

public:

    clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
    {
        _Mode = Mode;
        _Country = Country; _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName; _Rate = Rate;

    }

    enMode Mode()
    {
        return _Mode;
    }

    void UpdateRate(float NewRate)
    {
        _Rate = NewRate;
        _Update();
    }

    float ConvertToUSD(float Amount)
    {
      return Amount / GetRate();
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currency)
    {
       Amount = ConvertToUSD(Amount);
        return Amount * Currency.GetRate();
    }

    float GetRate()
    {
        return _Rate;
    }

    string GetCountry()
    {
        return _Country;
    }

    string GetCurrenyCode()
    {
        return _CurrencyCode;
    }

    string GetCurrencyName()
    {
        return _CurrencyName;
    }

    static vector <clsCurrency> GetAllUSDRates()
    {
        return _LoadCurrenciesDataFromFile();
    }

    static clsCurrency GetEmptyCurrencyObject()
    {
        return _GetEmptyCurrencyObject();
    }
    
    bool IsEmpty()
    {
        return (_Mode == EmptyMode);
    }

    static clsCurrency FindByCode(string CurrencyCode)
    {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                if (Currency.GetCurrenyCode() == CurrencyCode)
                {
                    MyFile.close();
                    return Currency;
                }
                
            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static clsCurrency FindByCountry(string Country)
    {
        Country = clsString::UpperAllString(Country);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

                if ((clsString::UpperAllString(Currency.GetCountry())) == Country)
                {
                    MyFile.close();
                    return Currency;
                }

            }

            MyFile.close();

        }

        return _GetEmptyCurrencyObject();
    }

    static bool IsCurrencyExist(string CurrencyCode)
    {
        clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
        return (!C1.IsEmpty());

    }

    static vector <clsCurrency> GetCurrenciesList()
    {
        return _LoadCurrenciesDataFromFile();
    }
};