#include <QCoreApplication>
#include <iostream>
#include <string>

using namespace std;

int m_topFrac1 = 1, m_botFrac1 = 1;
int m_topFrac2 = 1, m_botFrac2 = 1;

int greatestCommonDenominator(int a, int b)
{
    if (a == 0)
        return b;
    return greatestCommonDenominator(b%a, a);
}

list<int> simplify(int newNum, int newDen)
{
    int commonFactor = greatestCommonDenominator(newNum, newDen);
    int num = newNum/commonFactor;
    int den = newDen/commonFactor;

    if (num > 0 && den < 0)
    {
        list<int> fraction;
        fraction.push_back(0-(newNum/commonFactor));
        fraction.push_back(abs(newDen/commonFactor));
    }

    list<int> fraction;
    fraction.push_back(newNum/commonFactor);
    fraction.push_back(newDen/commonFactor);

    return fraction;
}

list<int> addFraction(int topFrac1, int botFrac1, int topFrac2, int botFrac2)
{
    int newNum, newDen;
    newDen = greatestCommonDenominator(botFrac1, botFrac2);
    newDen = (botFrac1 * botFrac2) / newDen;
    newNum = (topFrac1)*(newDen / botFrac1) + (topFrac2)*(newDen / botFrac2);

    return simplify(newNum, newDen);
}

list<int> subtractFraction(int topFrac1, int botFrac1, int topFrac2, int botFrac2)
{
    int newNum, newDen;
    newDen = greatestCommonDenominator(botFrac1, botFrac2);
    newDen = (botFrac1 * botFrac2) / newDen;
    newNum = (topFrac1)*(newDen / botFrac1) - (topFrac2)*(newDen / botFrac2);

    return simplify(newNum, newDen);
}

list<int> multiplyFraction(int topFrac1, int botFrac1, int topFrac2, int botFrac2)
{
    return simplify((topFrac1*topFrac2), (botFrac1*botFrac2));
}

list<int> divideFraction(int topFrac1, int botFrac1, int topFrac2, int botFrac2)
{
    return simplify((topFrac1*botFrac2), (botFrac1*topFrac2));
}

void loadFrac1(int num, int den)
{
    if (den == 0)
    {
        system("CLS");
        cout << "Error, Denominator cannot be zero!" << endl << endl;
        system("PAUSE");
        return;
    }
    else
    {
        m_topFrac1 = num;
        m_botFrac1 = den;
    }
}

void loadFrac2(int num, int den)
{
    if (den == 0)
    {
        system("CLS");
        cout << "Error, Denominator cannot be zero!" << endl << endl;
        system("PAUSE");
        return;
    }
    else
    {
        m_topFrac2 = num;
        m_botFrac2 = den;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    do
    {
        system("CLS");
        int choice;

        cout << "Menu:" << endl << endl;
        cout << "Fraction 1: " << m_topFrac1 << "/" << m_botFrac1 << endl;
        cout << "Fraction 2: " << m_topFrac2 << "/" << m_botFrac2 << endl << endl;
        cout << "1) Load/Reload Fraction One" << endl;
        cout << "2) Load/Reload Fraction Two" << endl;
        cout << "3) Fraction1 + Fraction2" << endl;
        cout << "4) Fraction1 - Fraction2" << endl;
        cout << "5) Fraction1 * Fraction2" << endl;
        cout << "6) Fraction1 / Fraction2" << endl;
        cout << "7) Exit" << endl;
        cout << endl;
        cout << "Enter Selection:";

        cin >> choice;

        if (choice >= 1 && choice <= 7)
        {
            system("CLS");
            switch (choice) {
            case 1:
            {
                int num, den;

                cout << "Load/Reload Fraction One" << endl << endl;
                cout << "Enter Fraction1's Numerator:" << endl;
                cin >> num;
                cout << "Enter Fraction1's Denominator:" << endl;
                cin >> den;

                loadFrac1(num, den);
                break;
            }
            case 2:
            {
                int num, den;

                cout << "Load/Reload Fraction Two" << endl << endl;
                cout << "Enter Fraction2's Numerator:" << endl;
                cin >> num;
                cout << "Enter Fraction2's Denominator:" << endl;
                cin >> den;

                loadFrac2(num, den);
                break;
            }
            case 3:
            {
                cout << "Fraction1 + Fraction2" << endl << endl;

                list<int> fraction = addFraction(m_topFrac1, m_botFrac1, m_topFrac2, m_botFrac2);
                list<int>::iterator it = fraction.begin();
                advance(it, 0);
                int num = *it;
                advance(it, 1);
                int den = *it;

                cout << "(" << m_topFrac1 << "/" << m_botFrac1 << ") + (" << m_topFrac2 << "/" << m_botFrac2 << ") = " << num << "/" << den << "            " << (double)num/den << endl;
                system("PAUSE");
                break;
            }
            case 4:
            {
                cout << "Fraction1 - Fraction2" << endl << endl;
                list<int> fraction = subtractFraction(m_topFrac1, m_botFrac1, m_topFrac2, m_botFrac2);
                list<int>::iterator it = fraction.begin();
                advance(it, 0);
                int num = *it;
                advance(it, 1);
                int den = *it;

                cout << "(" << m_topFrac1 << "/" << m_botFrac1 << ") - (" << m_topFrac2 << "/" << m_botFrac2 << ") = " << num << "/" << den << "            " << (double)num/den << endl;
                system("PAUSE");
                break;
            }
            case 5:
            {
                cout << "Fraction1 * Fraction2" << endl << endl;
                list<int> fraction = multiplyFraction(m_topFrac1, m_botFrac1, m_topFrac2, m_botFrac2);
                list<int>::iterator it = fraction.begin();
                advance(it, 0);
                int num = *it;
                advance(it, 1);
                int den = *it;

                cout << "(" << m_topFrac1 << "/" << m_botFrac1 << ") * (" << m_topFrac2 << "/" << m_botFrac2 << ") = " << num << "/" << den << "            " << (double)num/den << endl;
                system("PAUSE");
                break;
            }
            case 6:
            {
                cout << "Fraction1 / Fraction2" << endl << endl;
                list<int> fraction = divideFraction(m_topFrac1, m_botFrac1, m_topFrac2, m_botFrac2);
                list<int>::iterator it = fraction.begin();
                advance(it, 0);
                int num = *it;
                advance(it, 1);
                int den = *it;

                cout << "(" << m_topFrac1 << "/" << m_botFrac1 << ") / (" << m_topFrac2 << "/" << m_botFrac2 << ") = " << num << "/" << den << "            " << (double)num/den << endl;
                system("PAUSE");
                break;
            }
            case 7:
            {
                return 0;
            }
            }
            continue;
        }
        else
        {
            system("CLS");
            cout << "Error, invalid selection." << endl << endl;
            system("PAUSE");
            continue;
        }
        return 0;
    }
    while (0 == 0);

    return 0;
}
