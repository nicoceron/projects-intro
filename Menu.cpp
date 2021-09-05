/******************************************************************************/
/*                                                                            */
/*   +----+ +----+                    Proyecto 2021-30 				          */
/*   ++  ++ +++----+                                                          */
/*    |  |   |++  ++      DEVELOPED BY: Ing. Jeisson Ruiz 				      */
/*    |  |   | |  |                     jeisson_ruizc@javeriana.edu.co        */
/*    |  |   | |  |                     Ing. Andres Orjuela       		      */
/*    |  |   | |  |                     correo       						  */
/*    |  |   | |  |                     Ing. Mariana Pinzon	                  */
/*    |  |   | |  |                     correo                                */
/*    |  |   | |  |                     Ing. Nicolas Ceron                    */
/*    |  |   | |  |                     ceron_s@javeriana.edu.co              */
/*    |  |   | |  |                                                           */
/*    |+----+| |  |       Bogota, D.C., April 15, 2021.                       */
/*    |++  ++  |  |                                                           */
/*    ++|  ++  +  |       Copyright (C++) System Engineering Program          */
/*     +++  +-+  ++                       School of Engineering               */
/*      +++     ++                        Pontificia Universidad Javeriana    */
/*        +-----+                         Bogota - Colombia - South America   */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/*      Origin:  Written and tested by Jeisson Ruiz 				          */
/*      							   Andres  Orjuela 				          */
/*       							   Mariana Pinzon 				          */
/*                                     Nicolas Ceron                          */
/*                                                                            */
/******************************************************************************/
/*********************************  Headers   *********************************/
#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
using namespace std;
/*FN****************************************************************************
*
*   void Tabla();
*
*   Purpose: Do the procces of the automation of the lending
*
*   Return:  Nothing
*
*   DATE       RESPONSIBLE    COMMENT
*   -----------------------------------------------------------------------
*  Sep 09/21   S.N.Ceron  Initial Implementation
*              J.C.Ruiz
*              M.Arias
*			   A.Orjuela
*******************************************************************************/
void Tabla()
{
    int x, z , i ;
    double y,in,ab,si;
    double vc = 0;
    system("cls");
    cout << setiosflags(ios::fixed);
    cout << setprecision(1);
    cout << "\n\tDigite Valor de la Deuda: ";
    cin >> x;
    cout << "\n\tDigite tasa interes en %: ";
    cin >> y;
    cout << "\n\tDigite Numero de Cuotas : ";
    cin >> z;
    si = x;
    y /= 100;
	cout << " P\t" << "saldo Inic\t"<<"Intereses\t"<<"Vlr.Cuota\t"<<"Abono Cap.\t"<<"Saldo Fin\n";
	cout <<"---\t"<<"----------"<<"----------"<<"----------"<<"----------"<<"----------\n";
    for (i = 1; i <= z; i++)
    {
		in = si * y;
		vc = (x * y) / (1 - pow(1 + y, -z));
		ab = vc - in;
		si -= ab;
        cout << i <<"\t"<< si<<"\t"<< in << "\t"<< vc << "\t"<< ab << "\t"<< si << "\t";
    }
    system("pause");
} /*Tabla*/

void Vectores()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
}

void Matrices()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
}

void Estructuras()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
}

void Archivos()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
}

main()
{
    int op;
    do
    {
        system("cls");
        cout << "\n\t\tMENU PRINCIPAL" << endl;
        cout << "\n\t\t1. Tabla Amortizacion Prestamo";
        cout << "\n\t\t2. Vectores Unidimensionales";
        cout << "\n\t\t3. Matrices";
        cout << "\n\t\t4. Estructuras";
        cout << "\n\t\t5. Archivos";
        cout << "\n\t\t9. Salir";
        cout << "\n\n\n\tDigite la opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            Tabla();
            break;
        case 2:
            Vectores();
            break;
        case 3:
            Matrices();
            break;
        case 4:
            Estructuras();
            break;
        case 5:
            Archivos();
            break;
        case 9:
            system("cls");
            cout << "\n\t\tHASTA LA VISTA... Baby :-)" << endl
                 << endl;
            getch();
            break;
        default:
            system("cls");
            cout << "\n\t\tOPCION INVALIDA ... Intente de nuevo" << endl
                 << endl;
            system("pause");
            break;
        }
    } while (op != 9);
}
