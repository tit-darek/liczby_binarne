#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
string s, s2;
int a, w, wiecejzer, b, osiem, dwa;
fstream liczby;
bool podzielne (string s2)
{
    liczby.open("liczby.txt", ios::in);
    while (liczby.good())
    {
        liczby>>s2;
        int dl=s2.size();
        if(s2[dl-1]=='0')                                                               //sprawdza podzielnosc przez 2 (2 tylko do zerowej potegi da liczbe nieparzysta)
            dwa++;
        if(s2[dl-1]=='0' && s2[dl-2]=='0' && s2[dl-3]=='0')                             //sprawdza podzielnosc przez 8 (dwa do 0,1 i 2 potegi daje liczbe niepodzielna przez 8, nastepne potegi sa juz podzielne)
            osiem++;
    }
    cout<<"Ilosc liczb podzielnych przez 2 wynosi: "<<dwa<<endl<<"Ilosc liczb podzielnych przez 8  wynosi: "<<osiem;
    liczby.close();
}
bool czegowiecej (string s)
{
    liczby.open("liczby.txt", ios::in);
    while (liczby.good())
    {
        liczby>>s;
        int dl=s.size();
        int x=0, y=0;
        for (int i=0; i<dl; i++)
        {
            if(s[i]=='1')
                x++;
            else
                y++;
        }
        if(x<y)
            wiecejzer++;
    }
    liczby.close();
    cout<<"Wiecej zer jest w tylu liczbach: "<<wiecejzer<<endl;
}
int main()
{
    cout<<"Jezeli chcesz sie dowiedziec w ilu liczbach wiecej jest 0, niz 1, wcisnij 1"<<endl;
    cout<<"Jezeli chcesz sie dowiedziec ile liczb jest podzielnych przez 2 oraz ile liczb jest podzielnych przez 8, wcisnij 2"<<endl;
    cout<<"Wprowadz twoj wybor: ";
    cin>>w;
    switch(w)
    {
    case 1:
        czegowiecej(s);
        break;
    case 2:
        podzielne(s2);
        break;
    default:
        cout<<"Nie ma takiej opcji! :c";
    }
    return 0;
}
