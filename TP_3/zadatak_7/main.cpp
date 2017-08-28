/*
Napišite funkciju “PascalovTrougao” (ili “PascalovTrokut”, ovisno od Vaših jezičkih preferencija)
koja kao parametar prima cijeli broj . Ova funkcija treba kreirati strukturu “grbave matrice” sa
redova u kojoj prvi red ima jedan element, drugi red dva elementa, treći red tri elementa, itd. koju
nakon kreiranja treba popuniti elementima Pascalovog trougla (trokuta) sa redova. Funkcija
treba da kao rezultat vrati upravo tako kreiranu “grbavu matricu”. Funkciju testirajte u programu
koji za unesenu vrijednost sa tastature ispisuje Pascalov trougao (trokut) sa redova. Prilikom
ispisa, za svaki element treba zauzeti onoliko prostora koliko iznosi širina najšireg broja koji se
javlja u trouglu (trokutu) uvećana za 1, uz ravnanje udesno (za određivanje ove širine, iskoristite
istu funkciju “NajvecaSirina” koju ste pisali u prethodnom zadatku. Uglavnom, dijalog između
programa i korisnika trebao bi izgledati poput sljedećeg:

    Unesite broj redova: 7
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    1 5 10 10 5 1
    1 6 15 20 15 6 1

Pri tome, elemente Pascalovog trougla nije dozvoljeno računati preko binomnih koeficijenata, već
treba koristiti činjenicu da je svaki element Pascalovog trougla jednak zbiru elemenata koji se
nalaze tačno iznad njega, i njegovog susjeda sa lijeve strane.
Ukoliko se funkciji kao parametar proslijedi 0, funkcija treba da vrati praznu matricu. Ukoliko joj
se proslijedi negativan broj, funkcija treba da baci izuzetak tipa “domain_error” uz prateći tekst
“Broj redova ne smije biti negativan”. U glavnom programu ne trebate predvidjeti hvatanje ovog
izuzetka, ali će biti testirano da li ga funkcija zaista baca.

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

using namespace std;

int NajvecaSirina(vector<vector<int>> c){
    int BrojCifara(int);
    int sol = 0;
    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[i].size(); j++){
            int numDig = BrojCifara(c[i][j]);
            if(c[i][j] < 0) numDig++;
            if(numDig > sol) sol = numDig;
        }
    }
    return sol;
}

int BrojCifara(int x){
    int sol = 0;
    while(x != 0){
        x /= 10;
        sol++;
    }
    return sol;
}

int main()
{
    vector<vector<int>> PascalovTrougao(int);

    auto c = PascalovTrougao(7);

    int sirina = NajvecaSirina(c) + 1;
    for(auto red : c){
        for(int broj : red)
            std::cout<<std::setw(sirina)<<broj;
        std::cout<<std::endl;
    }

    return 0;
}

vector<vector<int>> PascalovTrougao(int n){
    if(n < 0) throw std::domain_error("Broj redova ne smije biti negativan");
    vector<vector<int>> sol(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0)
                sol[i].push_back(1);
            else if(j == i)
                sol[i].push_back(1);
            else
                sol[i].push_back(sol[i-1][j] + sol[i-1][j-1]);
        }
    }
    return sol;
}
