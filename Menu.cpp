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
struct persona
{
    string nombre;
    // nombre del periodista
    int fecnac;
    /* fecha de nacimiento en formato AAAAMMDD
donde AAAA es año con 4 dígitos MM mes con 2
dígitos y DD el día con 2 dígitos */
    char sexo;
    // sexo del estudiante (f ó m)
    string ciudad;
    // ciudad donde reside el reportero
    int nd;
    // número de deportes que le interesan
    int codigo[8];
    // códigos de los deportes que le interesan
};
struct sport
{
    int codigo;
    // código del deporte
    char auxi;
    // indicativo S o N si el deporte tiene o no auxilio
    string nombre;
    // nombre del deporte
    int numtrans[10];
    // número de transmisiones en los últimos 10 campeonatos
};
void printrep(persona reporter[], int nr)
{
    cout << "              L I S T A D O     B A S I C O     R E P O R T E R O S\n\n"
         << "  nombre     fecnac    sex     ciudad    nd  dep1 dep2 dep3 dep4 dep5 dep6 dep7 dep8" << endl
         << "----------  --------  -----  ----------  --  ---- ---- ---- ---- ---- ---- ---- ----" << endl;
    for (int i = 0; i < nr; i++)
    {
        cout << setw(10) << reporter[i].nombre << setw(10) << reporter[i].fecnac << setw(5) << reporter[i].sexo << setw(13) << reporter[i].ciudad << setw(5) << reporter[i].nd << " ";
        for (int j = 0; j < reporter[i].nd; j++)
        {
            cout << setw(5) << reporter[i].codigo[j];
        }
        cout << endl;
    }
}
void printsport(sport deporte[], int nd)
{
    cout << "              LISTADO BASICO DEPORTES\n\n"
         << "              Transmisiones ultimos 10 campeonatos\n\n"
         << "  cod  auxi     nombre     T0 T1 T2 T3 T4 T5 T6 T7 T8 T9 " << endl
         << "  ---  ----  ------------  -- -- -- -- -- -- -- -- -- --" << endl;
    for (int i = 0; i < nd; i++)
    {
        cout << setw(5) << deporte[i].codigo << setw(6) << deporte[i].auxi << setw(13) << deporte[i].nombre << "  ";

        for (int j = 0; j < 10; j++)
        {
            cout << setw(3) << deporte[i].numtrans[j];
        }
        cout << endl;
    }
}
void printrs(persona reporter[], int nr, sport deporte[], int nd)
{
    int x;
    string d;
    cout << "        LISTADO REPORTEROS por DEPORTE\n\n"
         << "Digite nombre deporte: ";
    cin >> d;
    cout << "\nReporteros que laboran con ese deporte\n\n";
    for (int i = 0; i < nd; i++)
    {
        if (d == deporte[i].nombre)
        {
            x = deporte[i].codigo;
        }
    }
    for (int i = 0; i < nr; i++)
    {
        for (int j = 0; j < reporter[i].nd; j++)
        {
            if (x == reporter[i].codigo[j])
            {
                cout << reporter[i].nombre << '\n';
            }
        }
    }
}
void estrep(persona reporter[], int nr, sport deporte[], int nd)
{
    double sf = 0, sm = 0, age = 0, saux = 0, naux = 0, promr = 0;
    for (int i = 0; i < nr; i++)
    {
        if (reporter[i].sexo == 'f')
        {
            sf++;
        }
        else
        {
            sm++;
        }
        age = 2021 - reporter[i].fecnac / 10000;
        promr += age;
    }
    for (int i = 0; i < nd; i++)
    {
        if (deporte[i].auxi == 'S')
        {
            saux++;
        }
        else
        {
            naux++;
        }
    }
    cout << fixed << setprecision(1) << "\tPorcentaje Hombres = " << sm * 100 / nr << '%' << '\n'
         << "\tPorcentaje Mujeres = " << sf * 100 / nr << '%' << "\n\n"
         << "Edad promedio reporteros = " << setprecision(2) << promr / nr << " anos"
         << "\n\n"
         << fixed << setprecision(1)
         << "Porcentaje Deportes CON Auxilio = " << saux * 100 / nd << '%' << '\n'
         << "Porcentaje Deportes SIN Auxilio = " << naux * 100 / nd << '%';
}
void Estructuras()
{
    int nr = 30;
    persona reporter[100] = {
        {"esteban", 19631023, 'm', "medellin", 8, {106, 102, 115, 110, 101, 103, 109, 104}},
        {"fernanda", 19601221, 'f', "medellin", 1, {109}},
        {"cesar", 19610430, 'm', "armenia", 8, {113, 105, 115, 112, 110, 102, 104, 108}},
        {"eyner", 19600202, 'm', "bogota", 2, {104, 113}},
        {"luisa", 19941210, 'f', "medellin", 7, {113, 109, 110, 105, 103, 106, 115}},
        {"jacob", 19650925, 'm', "armenia", 2, {108, 105}},
        {"nicolas", 19620520, 'm', "pereira", 1, {109}},
        {"maria", 19630306, 'f', "cali", 7, {109, 103, 104, 106, 113, 105, 101}},
        {"yair", 19620909, 'm', "cali", 1, {109}},
        {"vanesa", 19651001, 'f', "medellin", 4, {108, 107, 101, 105}},
        {"francisco", 19631025, 'm', "cali", 6, {109, 105, 102, 110, 112, 101}},
        {"camilo", 19610901, 'm', "armenia", 5, {110, 104, 101, 109, 114}},
        {"kevin", 19620602, 'm', "cali", 4, {108, 114, 101, 110}},
        {"valeria", 19630230, 'f', "pereira", 3, {111, 107, 102}},
        {"sebastian", 19630407, 'm', "cali", 5, {101, 112, 104, 115, 111}},
        {"sofia", 19610406, 'f', "bogota", 8, {111, 115, 105, 101, 104, 103, 108, 110}},
        {"santiago", 19601209, 'm', "cali", 2, {106, 114}},
        {"enrique", 19610927, 'm', "cali", 1, {107}},
        {"jose", 19620530, 'm', "armenia", 8, {105, 115, 103, 101, 110, 104, 114, 106}},
        {"david", 19610922, 'm', "medellin", 5, {106, 115, 102, 101, 110}},
        {"ana", 19611229, 'f', "armenia", 5, {110, 113, 104, 111, 103}},
        {"joshua", 19600901, 'm', "armenia", 4, {113, 109, 106, 112}},
        {"felipe", 19600614, 'm', "bogota", 5, {113, 112, 108, 104, 114}},
        {"janna", 19601003, 'f', "medellin", 2, {104, 102}},
        {"alejandra", 19640329, 'f', "cali", 5, {108, 101, 103, 105, 113}},
        {"daniela", 19611005, 'f', "bogota", 7, {102, 112, 105, 104, 107, 106, 115}},
        {"andres", 19630821, 'm', "cali", 1, {114}},
        {"juana", 19630817, 'f', "pereira", 6, {104, 103, 107, 115, 114, 102}},
        {"zaida", 19651209, 'f', "bogota", 7, {113, 102, 112, 103, 101, 107, 114}},
        {"jeisson", 19630905, 'm', "medellin", 8, {113, 108, 101, 115, 104, 111, 114, 102}},
    };
    int nd = 15;
    sport deporte[100] = {
        {101, 'S', "futbol", {18, 20, 1, 18, 15, 10, 10, 12, 8, 13}},
        {102, 'N', "beisbol", {6, 18, 17, 5, 19, 1, 20, 17, 12, 4}},
        {103, 'S', "tenis", {11, 6, 15, 7, 2, 18, 2, 4, 17, 7}},
        {104, 'S', "natacion", {10, 18, 14, 13, 1, 17, 6, 7, 11, 15}},
        {105, 'N', "gimnasia", {14, 9, 2, 7, 8, 6, 4, 6, 6, 15}},
        {106, 'S', "salto", {7, 2, 1, 16, 2, 6, 18, 15, 12, 16}},
        {107, 'S', "bmx", {8, 13, 2, 9, 3, 18, 17, 1, 18, 7}},
        {108, 'N', "pista", {4, 5, 1, 19, 2, 10, 15, 19, 16, 3}},
        {109, 'S', "ruta", {12, 19, 14, 12, 11, 4, 18, 7, 14, 19}},
        {110, 'S', "voleybol", {10, 4, 17, 5, 4, 3, 9, 17, 14, 10}},
        {111, 'N', "basketbol", {2, 19, 19, 1, 19, 5, 8, 3, 12, 12}},
        {112, 'S', "karate", {2, 6, 19, 7, 12, 11, 15, 3, 8, 10}},
        {113, 'S', "arco", {4, 9, 15, 12, 15, 6, 11, 14, 12, 7}},
        {114, 'S', "clavado", {10, 3, 5, 9, 5, 10, 4, 18, 7, 19}},
        {115, 'N', "pingpong", {18, 6, 14, 1, 6, 5, 9, 7, 12, 16}},
    };
    int op;
    do
    {
        system("cls");
        cout << "\n\t\tREPORTEROS DEPORTIVOS" << endl;
        cout << "\n\t\t1. Listado Basico Reporteros";
        cout << "\n\t\t2. Listado Basico Deportes";
        cout << "\n\t\t3. Lista reporters by sport";
        cout << "\n\t\t4. Estadisticas";
        cout << "\n\t\t9. Salir";
        cout << "\n\n\n\tDigite la opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            system("cls");
            cout << endl
                 << endl;
            printrep(reporter, nr);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 2:
            system("cls");
            cout << endl
                 << endl;
            printsport(deporte, nd);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 3:
            system("cls");
            cout << endl
                 << endl;
            printrs(reporter, nr, deporte, nd);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 4:
            system("cls");
            cout << endl
                 << endl;
            estrep(reporter, nr, deporte, nd);
            cout << endl
                 << endl;
            system("pause");
            break;
        case 9:
            system("cls");
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
