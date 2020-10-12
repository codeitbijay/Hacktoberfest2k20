
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char tab[50][15];
int n=3; //dlugoœæ wê¿a
int m=5; //iloœæ jedzenia
struct pkt
{
        int x,y;
};
bool polozenia(pkt point[],int i,int j, int ilosc) //sprawdzanie po³o¿enia wê¿a i "jedzenia" w tabeli
{
    bool t=false;
    for(int a=0;a<ilosc;a++)
    {
        if(i==point[a].y&&j==point[a].x)
        {
            t=true;
            break;
        }
    }
    return t;
}
void plansza(pkt point[], pkt jedzenie[]) //wyœwietlanie planszy
{
    cout<<"----------------------------------------------------"<<endl;
    for(int i=0;i<15;i++)
    {
        cout<<"|";
        for(int j=0;j<50;j++)
        {
            if(polozenia(jedzenie,i,j,m)==true)
            tab[j][i]=231;
            if(polozenia(point,i,j,n)==true)
            {
                if(point[0].x==j&&point[0].y==i)
                tab[j][i]=254;
                else
                tab[j][i]=219;
            }
            cout<<tab[j][i];
        }
        cout<<"|"<<endl;
    }
    cout<<"----------------------------------------------------"<<endl;
}
void czysc() //czyszczenie planszy
{
    system("CLS");
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<50;j++)
        tab[j][i]=' ';
    }
}
pkt ruch(pkt point, char znak) // ruch glowa wê¿a
{

    if(znak==-32)
    {
        znak=getch();
        switch(znak)
        {
            case 72:
                {
                    if(point.y>0)
                    point.y=point.y-1;
                    break;
                }
            case 75:
                {   if(point.x>0)
                    point.x=point.x-1;
                    break;
                }
            case 77:
                {
                    if(point.x<100)
                    point.x=point.x+1;
                    break;
                }
            case 80:
                {
                    if(point.y<30)
                    point.y=point.y+1;
                    break;
                }
            default:
                return point;
                break;
        }
    }
    return point;
}

void uzup(pkt point[], int i) //ustawianie wê¿a na pocz¹tku gry
{
    point[i].x=point[i-1].x-1;
    point[i].y=point[i-1].y;
}
void uzup1(pkt point[],pkt point1[], int i) //uzupe³nienie tabeli ze wspó³rzêdnymi w poprzednim ruchu
{

    point[i].x=point1[i-1].x;
    point[i].y=point1[i-1].y;
}
void swap(pkt point[],pkt point1[],int i) //funkcja pomocznica
{
    point1[i].x=point[i].x;
    point1[i].y=point[i].y;
}
void pokaz(pkt point[],pkt point1[]) //funkcja pomocnicza
{
    for(int i=0;i<n;i++)
    {
        cout<<point[i].x<<" "<<point[i].y<<endl;
        cout<<point1[i].x<<" "<<point1[i].y<<endl<<endl;
    }
}
void jedz(pkt jedzenie[], int a) //losowanie
{
    jedzenie[a].x=(rand() % 48 ) + 1;
    jedzenie[a].y=(rand() % 13 ) + 1;
}
bool dotyk(pkt point,pkt point1[]) //sprawdzenie czy wa¿ nie zjada siê lub nie dotyka œciany
{
    bool t=false;
    for(int i=1;i<n;i++)
    {
        if(point.x==point1[i].x&&point.y==point1[i].y) // waz
        {
            t=true;
            break;
        }
    }
    if(t==false) //sciany
    {

        if(point.x<0||point.x>49||point.y<0||point.y>14)
        t=true;
    }
    return t;
}
bool czyzjadl(pkt point, pkt jedzenie[]) //sprawdzanie czy w¹¿ "zjad³"
{
    bool t=false;
    for(int i=0;i<m;i++)
    {
        if(point.x==jedzenie[i].x&&point.y==jedzenie[i].y)
        {
            t=true;
        }
    }
    return t;
}
void usunjedz(pkt point,pkt jedztab[], pkt point1[]) //usuwanie zjedzonego jedzenia
{
    int pomx,pomy;
    for(int i=0;i<m;i++)
    {
        if(point.x==jedztab[i].x&&point.y==jedztab[i].y)
        {
            do
            {
            jedztab[i].x=(rand() % 48 ) + 1;
            jedztab[i].y=(rand() % 13 ) + 1;
            }while(polozenia(point1,jedztab[i].x,jedztab[i].y,n)==true);
        }
    }

}
void dod(pkt point[], pkt pointpom[], pkt point1[]) //przed³u¿anie wê¿a
{
    int pomx=2*point[n-2].x-point[n-3].x,pomy=2*point[n-2].y-point[n-3].y;
    pointpom[n-1].x=pomx;//2*point[n-2].x-point[n-3].x;
    pointpom[n-1].y=pomy;//2*point[n-2].y-point[n-3].y;
}
pkt symuluj(pkt point[]) //symulowanie ruchu wê¿a
{
    pkt point1=point[0];
    if(point[0].x>point[1].x)
        point1.x=point1.x+1;
    else if(point[0].x<point[1].x)
        point1.x=point1.x-1;
    else if(point[0].y>point[1].y)
        point1.y=point1.y+1;
    else if(point[0].y<point[1].y)
        point1.y=point1.y-1;
    return point1;
}
int main(int argc, char** argv) {
    srand( time( NULL ) );
    char a;
    pkt *point;
    pkt *point1;
    point = new pkt [n];
    point1 = new pkt [n];
    pkt jedzenie [m];
    point[0].x=5;point[0].y=1;// pocz¹tkowa pozycja g³owy wê¿a
    for(int i=1;i<n;i++)
        uzup(point,i);
    for(int i=0;i<m;i++)
        jedz(jedzenie,i);
    plansza(point, jedzenie);
    while(true)
    {

        for(int i=0;i<n;i++)
            swap(point,point1,i);
        for(int i=1;i<n;i++)
            uzup1(point,point1,i);
        Sleep(25);
        if(kbhit()==true)
        {
                a=getch();
                if(a==-32)
                point[0]=ruch(point[0],a);
                else
                point[0]=symuluj(point1);
        }
        else
        point[0]=symuluj(point1);
        czysc();
        if(dotyk(point[0],point))
        {
            cout<<"Przegrales"<<endl;
            break;
        }
        if(czyzjadl(point[0],jedzenie)==true)
        {
            n++;
            pkt * pointpom = new pkt[ n ]; //tabela pomocnicza przed dodaniem pkt
            pkt * pointpom1 = new pkt[ n ]; //tabela pomocnicza przed dodaniem pkt
            for(int i=0;i<n-1;i++)
                swap(point,pointpom,i);
            for(int i=0;i<n-1;i++)
                swap(point1,pointpom1,i);
            if(n>2)
            dod(point,pointpom,point1);
            pointpom1[n-1].x=0;
            pointpom1[n-1].y=0;
            delete []point;
            delete []point1;
            point = new pkt[ n ];
            point1 = new pkt[ n ];
            for(int i=0;i<n;i++)
                swap(pointpom,point,i);
            for(int i=0;i<n;i++)
                swap(pointpom1,point1,i);
            delete []pointpom;
            delete []pointpom1;
            usunjedz(point[0],jedzenie,point);
        }
        plansza(point,jedzenie);

    }
    Sleep(500);
    return 0;
}

