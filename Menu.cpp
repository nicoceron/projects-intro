/******************************************************************************/
/*                                                                            */
/*   +----+ +----+                    Proyecto 2021-30 				          */
/*   ++  ++ +++----+                                                          */
/*    |  |   |++  ++      DEVELOPED BY: Ing. Jeisson Ruiz 				      */
/*    |  |   | |  |                     jeisson_ruizc@javeriana.edu.co        */
/*    |  |   | |  |                     Ing. Andres Orjuela       		      */
/*    |  |   | |  |                     orjuela_af@javeriana.edu.co			  */
/*    |  |   | |  |                     Ing. Mariana Pinzon	                  */
/*    |  |   | |  |                     mariana-pinzon@javeriana.edu.co       */
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
/*******************************************************************************
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
    system("cls");
    int x, z, i;
    double y, in, ab, si;
    double vc = 0;
    cout << fixed << setprecision(1);
    cout << "\n\tDigite Valor de la Deuda: ";
    cin >> x;
    cout << "\n\tDigite tasa interes en %: ";
    cin >> y;
    cout << "\n\tDigite Numero de Cuotas : ";
    cin >> z;
    cout << endl;
    si = x;
    y /= 100;
    cout << setw(10) << "\t P\t"
         << setw(10) << "Saldo Inic\t"
         << setw(10) << " Intereses\t"
         << setw(10) << " Vlr.Cuota\t"
         << setw(10) << " Abono Cap.\t"
         << setw(10) << " Saldo Fin\n";
    cout << setw(10) << "\t---\t"
         << setw(10) << "----------\t"
         << setw(10) << "----------\t"
         << setw(10) << "----------\t"
         << setw(10) << "----------\t"
         << setw(10) << "----------\n";
    for (int i = 1; i <= z; i++)
    {
        cout << setw(10) << i;
        cout << "\t" << setw(10) << si;
        in = si * y;
        cout << "\t" << setw(10) << in;
        vc = (x * y) / (1 - pow(1 + y, -z));
        cout << "\t" << setw(10) << vc;
        ab = vc - in;
        cout << "\t" << setw(10) << ab;
        si -= ab;
        cout << "\t" << setw(10) << si << "\n";
    }
    cout << endl
         << endl;
    system("pause");
} /*Tabla*/
/*******************************************************************************
*
*   void imprime( int vec[],int n);
*
*   Purpose: Print the vector 
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
void imprime(int vec[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << setw(4) << vec[i];
    }
} /*imprime*/
/*******************************************************************************
*
*   void ordena( int vec[],int n);
*
*   Purpose: Reorganize the vector
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
void ordena(int vec[], int n)
{
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (vec[i] > vec[j])
            {
                x = vec[i];
                vec[i] = vec[j];
                vec[j] = x;
            }
        }
    }
} /*ordena*/

/*******************************************************************************
*
*   void estadisticas( int vec[],int n);
*
*   Purpose: gives the mean, variance and standard deviation
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
void estadisticas(int vec[], int n)
{
    double sum = 0, v = 0, p;
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
    }
    p = (double)sum / n;
    for (int i = 0; i < n; i++)
    {
        v += pow(vec[i], 2.0);
    }
    v = (double)(v / n) - (pow(p, 2.0));
    cout << "\n\n";
    cout << "Promedio = " << setprecision(1) << fixed << p << '\n';
    cout << "Varianza = " << setprecision(2) << fixed << v << '\n';
    cout << "Desviacion estandar = " << setprecision(2) << fixed << sqrt(v) << '\n';
} /*estadisticas*/

/*******************************************************************************
*
*   void inserta(int vec[],int n,int ne);
*
*   Purpose: insert a number and reorganize the vector
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

int insertar(int vec[], int n, int y)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (y <= vec[i])
        {
            break;
        }
    }
    for (j = n - 1; j >= i; j--)
    {
        vec[j + 1] = vec[j];
    }
    vec[i] = y;
    n++;
    return n;
}

/*******************************************************************************
*
*   void borra(int vec[],int n,int eb);
*
*   Purpose: delete a number of the vector
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

int borrar(int vec[], int n, int y)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (y <= vec[i])
        {
            break;
        }
    }
    if (y == vec[i])
    {
        for (j = i + 1; j < n; ++j)
        {
            vec[j - 1] = vec[j];
        }
        n--;
    }
    return n;
}

/*******************************************************************************
*
*   void vectores();
*
*   Purpose: gives menu of the option 2
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

void Vectores()
{
    int vec1[100] = {3, 7, 68, 34, 12, 21, 9, 23, 14, 83};
    int n1 = 10;
    int vec2[100] = {14, 19, 23, 98, 99, 14, 69, 23, 18, 18, 23, 12, -6, 5, 15};
    int n2 = 15;
    int x, y, z;
    int op;
    do
    {
        system("cls");
        cout << "\n\t\tMENU VECTORES" << endl;
        cout << "\n\t\t1. Lista vector.";
        cout << "\n\t\t2. Ordena vector.";
        cout << "\n\t\t3. Estadisticas.";
        cout << "\n\t\t4. Inserta elemento";
        cout << "\n\t\t5. Borra elemento";
        cout << "\n\t\t9. Salir";
        cout << "\n\n\n\tDigite la opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << "\tDigite vector a ser listado (1/2) :";
            cin >> x;
            cout << "\n\n";
            if (x == 1)
            {
                imprime(vec1, n1);
            }
            else if (x == 2)
            {
                imprime(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "\tDigite vector a ser ordenado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                imprime(vec1, n1);
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                imprime(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "\tDigite el vector a aplicar estadisticas (1/2): ";
            cin >> x;
            if (x == 1)
            {
                estadisticas(vec1, n1);
            }
            else
            {
                estadisticas(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\tDigite vector seleccionado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                imprime(vec1, n1);
                cout << "\n\n\tDigite el elemento a insertar: ";
                cin >> y;
                n1 = insertar(vec1, n1, y);
                cout << "\n\n\tVector nuevo\n\n";
                imprime(vec1, n1);
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                imprime(vec2, n2);
                cout << "\n\n\tDigite el elemento a borrar: ";
                cin >> y;
                n2 = insertar(vec2, n2, y);
                cout << "\n\n\tVector nuevo\n\n";
                imprime(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "\tDigite vector seleccionado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                imprime(vec1, n1);
                cout << "\n\n\tDigite el elemento a borrar: ";
                cin >> y;
                z = borrar(vec1, n1, y);
                if (z != n1)
                {
                    cout << "\n\n\tVector nuevo\n\n";
                    n1 = z;
                    imprime(vec1, n1);
                }
                else
                {
                    cout << "\n\n\tNO se encontro el numero a borrar :-(";
                }
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                imprime(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                imprime(vec2, n2);
                cout << "\n\n\tDigite el elemento a borrar: ";
                cin >> y;
                z = borrar(vec2, n2, y);
                if (z != n2)
                {
                    cout << "\n\n\tVector nuevo\n\n";
                    n2 = z;
                    imprime(vec2, n2);
                }
                else
                {
                    cout << "\n\n\tNO se encontro el numero a borrar :-(";
                }
            }
            cout << endl
                 << endl;
            system("pause");
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
