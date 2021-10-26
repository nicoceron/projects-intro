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
    vc = (x * y) / (1 - pow(1 + y, -z));
    for (i = 1; i <= z; i++)
    {
        cout << setw(10) << i << "\t" << setw(10) << si;
        in = si * y;
        ab = vc - in;
        si -= ab;
        cout << "\t" << setw(10) << in << "\t" << setw(10) << vc << "\t" << setw(10) << ab << "\t" << setw(10) << si << "\n";
    }
    cout << endl
         << endl;
    system("pause");
} /*Tabla*/
/*******************************************************************************
*
*   void printvec( int vec[],int n);
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
void printvec(int vec[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << setw(4) << vec[i];
} /*printvec*/
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
        sum += vec[i];

    p = (double)sum / n;

    for (int i = 0; i < n; i++)
        v += pow(vec[i], 2.0);

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
        if (y <= vec[i])
            break;

    for (j = n - 1; j >= i; j--)
        vec[j + 1] = vec[j];

    vec[i] = y;
    n++;
    return n;
} /*insertar*/
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
        if (y <= vec[i])
            break;

    if (y == vec[i])
    {
        for (j = i + 1; j < n; ++j)
            vec[j - 1] = vec[j];
        n--;
    }
    return n;
} /*borrar*/
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
            cout << "\t\nDigite vector a ser listado (1/2) :";
            cin >> x;
            cout << "\n\n";
            if (x == 1)
            {
                printvec(vec1, n1);
            }
            else if (x == 2)
            {
                printvec(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "\t\nDigite vector a ser ordenado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                printvec(vec1, n1);
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                printvec(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "\t\nDigite el vector a aplicar estadisticas (1/2): ";
            cin >> x;
            if (x == 1)
                estadisticas(vec1, n1);
            else
                estadisticas(vec2, n2);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "\t\nDigite vector seleccionado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                printvec(vec1, n1);
                cout << "\n\n\tDigite el elemento a insertar: ";
                cin >> y;
                n1 = insertar(vec1, n1, y);
                cout << "\n\n\tVector nuevo\n\n";
                printvec(vec1, n1);
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                printvec(vec2, n2);
                cout << "\n\n\tDigite el elemento a insertar: ";
                cin >> y;
                n2 = insertar(vec2, n2, y);
                cout << "\n\n\tVector nuevo\n\n";
                printvec(vec2, n2);
            }
            cout << endl
                 << endl;
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "\t\nDigite vector seleccionado (1/2): ";
            cin >> x;
            if (x == 1)
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec1, n1);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec1, n1);
                printvec(vec1, n1);
                cout << "\n\n\tDigite el elemento a borrar: ";
                cin >> y;
                z = borrar(vec1, n1, y);
                if (z != n1)
                {
                    cout << "\n\n\tVector nuevo\n\n";
                    n1 = z;
                    printvec(vec1, n1);
                }
                else
                {
                    cout << "\n\n\tNO se encontro el numero a borrar :-(";
                }
            }
            else
            {
                cout << "\n\n\tVector original\n\n";
                printvec(vec2, n2);
                cout << "\n\n\tVector ordenado\n\n";
                ordena(vec2, n2);
                printvec(vec2, n2);
                cout << "\n\n\tDigite el elemento a borrar: ";
                cin >> y;
                z = borrar(vec2, n2, y);
                if (z != n2)
                {
                    cout << "\n\n\tVector nuevo\n\n";
                    n2 = z;
                    printvec(vec2, n2);
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
} /*vectores*/
/*******************************************************************************
*
*   void Matrices();
*
*   Purpose: gives menu of the option 3
*
*   Return:  Nothing
*
*   DATE       RESPONSIBLE    COMMENT
*   -----------------------------------------------------------------------
*  Oct 25/21   S.N.Ceron  Initial Implementation
*              J.C.Ruiz
*              M.Arias
*			   A.Orjuela
*******************************************************************************/
void printmat(int mat[][10], int m, int n)
{
    int i, j;

    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
} //imprime matriz

double porcmat(int mat[][10], int m, int n, int x)
{
    int c = 0, tot = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] % x == 0 && mat[i][j] != 0)
            {
                c++;
            }
            tot++;
        }
    }
    return (double)c * 100 / tot;
} //porcentaje matriz

double modmat(int mat[][10], int m, int n, int x)
{
    int c = 0, tot = 0;
    if (x == 1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] % 2 != 0 && mat[i][j] != 0)
                {
                    mat[i][j] = -1;
                    c++;
                }
                tot++;
            }
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] % 2 == 0 && mat[i][j] != 0)
                {
                    mat[i][j] = -2;
                    c++;
                }
                tot++;
            }
        }
    }
    return (double)c * 100 / tot;
}

void trimat(int mat[][10], int m, int n, char z)
{
    int x = min(m, n);
    if (z == 's')
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (j < i)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
    else if (z == 'i')
    {
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < x; j++)
            {
                if (j > i)
                {
                    mat[i][j] = 0;
                }
            }
        }
    }
}
void Matrices()
{

    int mat[10][10] = {
        {4, 14, 0, 12, 19, 8, 12},
        {5, 10, 0, 9, 3, 11, 4},
        {16, 8, 3, 99, 10, 2, 15},
        {13, 21, 12, 6, 7, 0, 0},
        {0, 3, 11, 7, 9, 4, 13}};
    int m = 5, n = 7;
    int x;
    char z;
    int op;
    do
    {
        system("cls");
        cout << "\n\t\tMENU MATRICES" << endl;
        cout << "\n\t\t1. Muestra Matriz.";
        cout << "\n\t\t2. Porcentaje acorde.";
        cout << "\n\t\t3. Modifica al caso.";
        cout << "\n\t\t4. Ajusta a Triangular.";
        cout << "\n\t\t9. Salir";
        cout << "\n\n\n\tDigite la opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << endl
                 << endl;
            printmat(mat, m, n);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << endl
                 << endl;
            printmat(mat, m, n);
            cout << "\nDigite un numero de un digito: ";
            cin >> x;
            cout << "\nPorcentaje acorde digito leido= " << fixed << setprecision(1) << porcmat(mat, m, n, x) << "%\n\n";
            cout << endl
                 << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "\nDigite 1 si impar 0 si par: ";
            cin >> x;
            cout << "\nPorcentaje numeros modificados= " << fixed << setprecision(1) << modmat(mat, m, n, x) << "%\n\n";
            printmat(mat, m, n);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            z = 'x';
            cout << endl
                 << endl;
            printmat(mat, m, n);
            while (z != 's' && z != 'i')
            {
                cout << "\t\nDigite s:superior/i:inferior -> ";
                cin >> z;
            }
            trimat(mat, m, n, z);
            cout << endl
                 << endl;
            printmat(mat, m, n);
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
} /*Matrices*/

/*******************************************************************************
*
*   void Estructuras();
*
*   Purpose: This part of the code is not going to work
*
*   Return:  Nothing
*
*   DATE       RESPONSIBLE    COMMENT
*   -----------------------------------------------------------------------
*  Oct 25/21   S.N.Ceron  Initial Implementation
*              J.C.Ruiz
*              M.Arias
*			   A.Orjuela
*******************************************************************************/
void Estructuras()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
} /*Estructuras*/

/*******************************************************************************
*
*   void Archivos();
*
*   Purpose: This part of the code is not going to work
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
void Archivos()
{
    system("cls");
    cout << "\n\t\tOPCION EN CONSTRUCCION" << endl
         << endl;
    system("pause");
} /*Archivos*/

/*******************************************************************************
*
*   main();
*
*   Purpose: Is the general function of the code , is in charge of giving the
*			 list and calling the functions through the code options
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
} /*main*/
