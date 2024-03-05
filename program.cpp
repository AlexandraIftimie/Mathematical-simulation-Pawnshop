#include <iostream>
#include <stdlib.h>
using namespace std;
float generare_numere()
{
    return (float)rand() / RAND_MAX;
}
int decizie_nr_clienti(float numar_generat)
{
    if (numar_generat < 0.2)
        return 0;
    else
        if (numar_generat >= 0.2 && numar_generat < 0.4)
            return 1;
        else
            if (numar_generat >= 0.4 && numar_generat < 0.9)
                return 2;
            else
                if (numar_generat >= 0.9 && numar_generat <= 1)
                    return 3;
}
int decizie_val_credit(float numar_generat)
{
    if (numar_generat < 0.5)
        return 1000;
    else
        if (numar_generat >= 0.5 && numar_generat < 0.8)
            return 2000;
        else
            if (numar_generat >= 0.8 && numar_generat <= 1)
                return 3000;
           
}
int decizie_nr_zile(float numar_generat)
{
    if (numar_generat < 0.3)
        return 2;
    else
        if (numar_generat >= 0.3 && numar_generat < 0.9)
            return 3;
        else
            if (numar_generat >= 0.9 && numar_generat <=1)
                return 4;   
}
int vector_clienti(int credit[3], int zile[3])
{
    
    int nr_clienti;  
    nr_clienti = decizie_nr_clienti(generare_numere());  // decide cati clienti vor fi in ziua respectiva, 
    for (int i = 0; i < nr_clienti; i++) //pt fiecare client genereaza valoarea creditului si numarul de zile
    {
        credit[i] = decizie_val_credit(generare_numere());
        zile[i] = decizie_nr_zile(generare_numere());
    }
    return nr_clienti; // returneaza numarul de clienti sa nu lucrezi in partea de vector null
}
float dobanda(int valoare_credit, int nr_zile) // functie care calculeaza valoarea dobanzii;
{
    if (valoare_credit == 1000)
    {
        if (nr_zile == 2)
            return 0.001*valoare_credit*nr_zile;
        else
            if (nr_zile == 3)
                return 0.005 * valoare_credit * nr_zile;
            else
                if (nr_zile == 4)
                    return 0.01 * valoare_credit * nr_zile;
                else
                    cout << endl << endl << "VALOARE GRESITA A NUMARULUI DE ZILE" << endl;
                    
    }
    else
        if (valoare_credit == 2000)
        {
            if (nr_zile == 2)
                return 0.005 * valoare_credit * nr_zile;
            else
                if (nr_zile == 3)
                    return 0.01 * valoare_credit * nr_zile;
                else
                    if (nr_zile == 4)
                        return 0.015 * valoare_credit * nr_zile;
                    else
                        cout << endl << endl << "VALOARE GRESITA A NUMARULUI DE ZILE" << endl;

        }
        else
            if (valoare_credit == 3000)
            {
                if (nr_zile == 2)
                    return 0.01 * valoare_credit * nr_zile;
                else
                    if (nr_zile == 3)
                        return 0.015 * valoare_credit * nr_zile;
                    else
                        if (nr_zile == 4)
                            return 0.02 * valoare_credit * nr_zile;
                        else
                            cout << endl << endl << "VALOARE GRESITA A NUMARULUI DE ZILE" << endl;

            }
            else
                cout << endl << endl << "VALOARE GRESITA A CREDITULUI " << endl;
}

int main()
{   

    float profit_mediu = 0;
    for (int j = 0; j < 2; j++)
    {
        int profit = 0;
        //ziua 1
        int c1[3], z1[3], clienti1, dobanda_i = 0, sold = 30000, profit_zilnic; 
        clienti1 = vector_clienti(c1, z1);
        for (int i = 0; i < clienti1; i++)
        {
            dobanda_i = dobanda_i + dobanda(c1[i], z1[i]);
            sold = sold - c1[i];
        }
        sold = sold - 50 + dobanda_i;
        profit_zilnic = sold - 30000;
        cout << sold << "  " << profit_zilnic << endl;
        profit = profit + profit_zilnic;
       

        //ziua 2
        int c2[3], z2[3], clienti2;
        dobanda_i = 0;
        clienti2 = vector_clienti(c2, z2);
        for (int i = 0; i < clienti2; i++)
        {
            dobanda_i = dobanda_i + dobanda(c2[i], z2[i]);
            sold = sold - c2[i];
        }
        sold = sold - 50 + dobanda_i;
        profit_zilnic = sold - 30000;
        cout << sold << "  " << profit_zilnic << endl;
        profit = profit + profit_zilnic;
       

         //ziua 3
        int c3[3], z3[3], clienti3;
        dobanda_i = 0;
        clienti3 = vector_clienti(c3, z3);
        for (int i = 0; i < clienti3; i++)
        {
            dobanda_i = dobanda_i + dobanda(c3[i], z3[i]);
            sold = sold - c3[i];
        }

        sold = sold - 50 + dobanda_i;
        for (int i = 0; i < clienti1; i++)
            if (z1[i] == 2)
                sold = sold + c1[i];
        profit_zilnic = sold - 30000;
        cout << sold << "  " << profit_zilnic << endl;
        profit = profit + profit_zilnic;
       

        // ziua 4 
        int sum = 0;
        int c4[3], z4[3], clienti4;
        dobanda_i = 0;
        clienti4 = vector_clienti(c4, z4);

        for (int i = 0; i < clienti4; i++)
            sum = c4[i] + sum;
        while ((sum + 50 > sold) && (clienti4 != 0))        {
            clienti4--;
            sum = 0;
            for (int i = 0; i < clienti4; i++)
                sum = c4[i] + sum;
        }
        for (int i = 0; i < clienti4; i++)
        {
            dobanda_i = dobanda_i + dobanda(c4[i], z4[i]);
            sold = sold - c4[i];
        }

        sold = sold - 50 + dobanda_i;
        for (int i = 0; i < clienti2; i++)
            if (z2[i] == 2)
                sold = sold + c2[i];
        for (int i = 0; i < clienti1; i++)
            if (z1[i] == 3)
                sold = sold + c1[i];
        profit_zilnic = sold - 30000;
        cout << sold << "  " << profit_zilnic << endl;
        profit = profit + profit_zilnic;




        //ziua 5+

        for (int i = 5; i < 27; i++)
        {
             sum = 0;
            int c5[3], z5[3], clienti5;
            dobanda_i = 0;
            clienti5 = vector_clienti(c5, z5);

            for (int i = 0; i < clienti5; i++)
                sum = c5[i] + sum;
            while ((sum + 50 > sold) && (clienti5 != 0))            {
                clienti5--;
                sum = 0;
                for (int i = 0; i < clienti5; i++)
                    sum = c5[i] + sum;
            }

            for (int i = 0; i < clienti5; i++)
            {
                dobanda_i = dobanda_i + dobanda(c5[i], z5[i]);
                sold = sold - c5[i];
            }
            sold = sold - 50 + dobanda_i;
            for (int i = 0; i < clienti1; i++) // verific daca am credite de acum 4 zile care trebuie sa fie predate azi
                if (z1[i] == 4)
                    sold = sold + c1[i];
            for (int i = 0; i < clienti2; i++) // verific daca am credite de acum 3 zile care trebuie sa fie predate azi
                if (z2[i] == 3)
                    sold = sold + c2[i];
            for (int i = 0; i < clienti3; i++) // verific daca am credite de acum 2 zile care trebuie sa fie predate azi
                if (z3[i] == 2)
                    sold = sold + c3[i];
            profit_zilnic = sold - 30000;
            cout << sold << "  " << profit_zilnic << endl;
            for (int i = 0; i < clienti2; i++)  //mut elementele din vectori sa fie la distanta egala fata de ziua actuala 
            {
                c1[i] = c2[i]; z1[i] = z2[i];
            }
            clienti1 = clienti2;
            for (int i = 0; i < clienti3; i++)
            {
                c2[i] = c3[i]; z2[i] = z3[i];
            }
            clienti2 = clienti3;
            for (int i = 0; i < clienti4; i++)  //mut elementele din vectori sa fie la distanta egala fata de ziua actuala 
            {
                c3[i] = c4[i]; z3[i] = z4[i];
            }
            clienti3 = clienti4;
            for (int i = 0; i < clienti5; i++)  //mut elementele din vectori sa fie la distanta egala fata de ziua actuala 
            {
                c4[i] = c5[i]; z4[i] = z5[i];
            }
            clienti4 = clienti5;
            profit = profit + profit_zilnic;
           
        }

        cout << endl << endl << endl << "Profitul total =suma din profitul zilnic: " << profit << endl
            << "Profitul mediu zilnic = profitul total impartit la cate profituri zilnice am (26): " << profit / 26;

        cout << endl << endl << endl;
        profit_mediu = profit_mediu + profit / 26;
    }
    cout << profit_mediu / 2 << "=profitul mediu pt 2 cicluri"<<endl;
  
    if (profit_mediu / 2 < 125)
        cout << endl<< " Investitia in casa de amanet nu este mai profitabila." << endl;
    else
        cout<< endl << " Investitia in casa de amanet este mai profitabila." << endl;


	return 0;
}
