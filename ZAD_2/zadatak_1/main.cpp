#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore,  GoreDesno,   Lijevo, Stani, Desno, DoljeLijevo, Dolje, DoljeDesno };

typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const vector<vector<int>>& mine)
{
    Tabla sol(n, vector<Polje>(n));
    for(int i = 0; i < mine.size(); i++){
        if(mine[i].size() != 2) throw domain_error("Ilegalan format zadavanja mina");
        if(mine[i][0] < 0 || mine[i][0] >= n || mine[i][1] < 0 || mine[i][1] >= n) throw domain_error("Ilegalne pozicije mina");
        sol[mine[i][0]][mine[i][1]] = Polje::Mina;
    }
    return sol;
}

Polje At(const Tabla& t, int i, int j)
{
    if(i < 0 || i >= t.size() || j < 0 || j >= t.size()) return Polje::Prazno;
    return t[i][j];
}

bool InRange(const Tabla& t, int i, int j)
{
    if(i < 0 || i >= t.size() || j < 0 || j >= t.size()) return false;
    return true;
}


Tabla PoljaOkiline(const Tabla& polja, int x, int y)
{
    Tabla sol(3, vector<Polje>(3));
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            sol[i][j] = At(polja, x-1+i, y-1+j);
        }
    sol[1][1] = Polje::Prazno;
    return sol;
}

vector<vector<int>> PrikaziOkolinu(const Tabla& polja, int x, int y)
{
    vector<vector<int>> sol(3, vector<int>(3));
    if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++){
            int suma;
            suma = 0;
            Tabla okolis = PoljaOkiline(polja, x-1+i, y-1+j);
            for(auto v : okolis)
                for(Polje p : v)
                    if(p == Polje::Mina) suma++;
            sol[i][j] = suma;
        }
    return sol;
}

void IspisiTablu(Tabla t)
{
    for(auto x : t){
        for(Polje p : x)
            cout<<(int)p<<" ";
        cout<<endl;
    }
}

void BlokirajPolje(Tabla& t, int x, int y)
{
    if(x < 0 || x >= t.size() || y < 0 || y >= t.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }

    if(t[x][y] == Polje::BlokiranoMina || t[x][y] == Polje::BlokiranoPosjeceno || t[x][y] == Polje::BlokiranoPrazno ) return;
    if(t[x][y] == Polje::Mina) t[x][y] = Polje::BlokiranoMina;
    if(t[x][y] == Polje::Posjeceno) t[x][y] = Polje::BlokiranoPosjeceno;
    if(t[x][y] == Polje::Prazno) t[x][y] = Polje::BlokiranoPrazno;
}

void DeblokirajPolje(Tabla& t, int x, int y)
{
    if(x < 0 || x >= t.size() || y < 0 || y >= t.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }

    if(t[x][y] == Polje::Mina || t[x][y] == Polje::Posjeceno || t[x][y] == Polje::Prazno ) return;
    if(t[x][y] == Polje::BlokiranoMina) t[x][y] = Polje::Mina;
    if(t[x][y] == Polje::BlokiranoPosjeceno) t[x][y] = Polje::Posjeceno;
    if(t[x][y] == Polje::BlokiranoPrazno) t[x][y] = Polje::Prazno;
}

enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };

Status Idi(Tabla& t, int& x, int& y, Smjerovi s)
{
    if(s == Smjerovi::Stani ) return Status::NijeKraj;
    if(x < 0 || x >= t.size() || y < 0 || y >= t.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }
    if(t[x][y] == Polje::Prazno) t[x][y] = Polje::Posjeceno;
    int sljedeciX = x-1+(int(s)/3);
    int sljedeciY = y-1+(int(s)%3);
    if(InRange(t, sljedeciX, sljedeciY)){
        x = sljedeciX;
        y = sljedeciY;
        if(t[x][y] == Polje::BlokiranoMina || t[x][y] == Polje::BlokiranoPrazno || t[x][y] == Polje::BlokiranoPosjeceno )
            throw logic_error("Blokirano polje");
        if(t[sljedeciX][sljedeciY] == Polje::Mina){
            for(int i = 0; i < t.size(); i++)
                for(int j = 0; j < t.size(); j++)
                    t[i][j] = Polje::Prazno;
            return Status::KrajPoraz;
        }
        for(int i = 0; i < t.size(); i++)
            for(int j = 0; j < t.size(); j++)
                if(t[i][j] == Polje::Prazno ){
                    return Status::NijeKraj;
                }
        return Status::KrajPobjeda;
    }
    else throw out_of_range("Izlazak van igrace table");
}

Status Idi(Tabla& t, int x, int y, int nX, int nY)
{
    if(x < 0 || x >= t.size() || y < 0 || y >= t.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }
    if(nX < 0 || nX >= t.size() || nY < 0 || nY >= t.size()){
        throw domain_error("Polje (x,y) ne postoji");
    }
    if(t[x][y] == Polje::Prazno) t[x][y] = Polje::Posjeceno;
    x = nX;
    y = nY;
    if(t[x][y] == Polje::BlokiranoMina || t[x][y] == Polje::BlokiranoPrazno || t[x][y] == Polje::BlokiranoPosjeceno )
        throw logic_error("Blokirano polje");
    if(t[x][y] == Polje::Mina){
        for(int i = 0; i < t.size(); i++)
            for(int j = 0; j < t.size(); j++)
                t[i][j] = Polje::Prazno;
        return Status::KrajPoraz;
    }
    for(int i = 0; i < t.size(); i++)
        for(int j = 0; j < t.size(); j++)
            if(t[i][j] == Polje::Prazno ){
                return Status::NijeKraj;
            }
    return Status::KrajPobjeda;
}

enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };

void PrijaviGresku(KodoviGresaka g)
{
    string greskeStr[] = {"Nerazumljiva komanda!" , "Komanda trazi parametar koji nije naveden!", "Parametar komande nije ispravan!", "Zadad je suvisan parametar nakon komande" };
    cout<<greskeStr[(int)g];
}

enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

bool UnosKomande(Komande& komanda, Smjerovi& smjer, int& x, int& y, KodoviGresaka& greska)
{
    string s;
    getline(cin, s);

    while(isspace(s[0])){
        s.erase(0, 1);
    }

    //Pomjeri za jedno mjestu u zadanom smjeru
    if(s[0] == 'P' && s[1] == '1')
    {
        int stanje = 1;
        string smjerStr;
        for(int i = 2; i < s.size(); i++){
            if(isspace(s[i]) && stanje == 1)
                continue;
            if(!isspace(s[i]) && stanje == 1){
                if(!isalpha(s[i])){
                    greska = KodoviGresaka::NedostajeParametar;
                    return false;
                } else {
                    smjerStr = s[i];
                    stanje = 2;
                    continue;
                }
            }
            if(isalpha(s[i]) && stanje == 2)
            {
               smjerStr += s[i];
               continue;
            }
            else if(isspace(s[i]) && stanje == 2){
                stanje = 3;
                continue;
            }
            else if (stanje == 2) {
                greska = KodoviGresaka::NeispravanParametar;
                return false;
            }

            if(stanje == 3 && !isspace(s[i])){
                greska = KodoviGresaka::SuvisanParametar;
                return false;
            }
        }
        if(smjerStr == "" ) {
            greska = KodoviGresaka::NedostajeParametar;
            return false;
        }

        if(smjerStr == "GL" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::GoreLijevo;
            return true;
        }
        else if(smjerStr == "G" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::Gore;
            return true;
        }
        else if(smjerStr == "GD" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::GoreDesno;
            return true;
        }
        else if(smjerStr == "L" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::Lijevo;
            return true;
        }
        else if(smjerStr == "D" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::Desno;
            return true;
        }
        else if(smjerStr == "DoL" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::DoljeLijevo;
            return true;
        }
        else if(smjerStr == "Do" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::Dolje;
            return true;
        }
        else if(smjerStr == "DoD" ){
            komanda = Komande::PomjeriJednoMjesto;
            smjer = Smjerovi::DoljeDesno;
            return true;
        }
        else {
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
    }
    else if(s[0] == 'P' && s[1] == '>'){
        stringstream ss(s);
        char c;
        ss>>c>>c;
        int a, b;
        ss>>a>>b;

        if(ss.fail()){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        if(!isspace(ss.peek()) && ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        if(a < 0 || b < 0){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        x = a;
        y = b;
        komanda = Komande::PomjeriDalje;
        return true;
    }
    else if(s[0] == 'B'){
        stringstream ss(s);
        char c;
        ss>>c;
        int a, b;
        ss>>a>>b;

        if(ss.fail()){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        if(!isspace(ss.peek()) && ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        if(a < 0 || b < 0){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        x = a;
        y = b;
        komanda = Komande::Blokiraj;
        return true;
    }
    else if(s[0] == 'D'){
        stringstream ss(s);
        char c;
        ss>>c;
        int a, b;
        ss>>a>>b;

        if(ss.fail()){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        if(!isspace(ss.peek()) && ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        if(a < 0 || b < 0){
            greska = KodoviGresaka::NeispravanParametar;
            return false;
        }
        x = a;
        y = b;
        komanda = Komande::Deblokiraj;
        return true;
    }
    else if(s[0] == 'P' && s[1] =='O'){
        stringstream ss(s);
        char c;
        ss>>c;
        while(isspace(ss.get()));
        if(ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }

        komanda = Komande::PrikaziOkolinu;
        return true;
    }
    else if(s[0] == 'Z'){
        stringstream ss(s);
        char c;
        ss>>c;
        while(isspace(ss.get()));
        if(ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        komanda = Komande::ZavrsiIgru;
        return true;
    }
    else if(s[0] == 'K'){
        stringstream ss(s);
        char c;
        ss>>c;
        while(isspace(ss.get()));
        if(ss.peek() != -1){
            greska = KodoviGresaka::SuvisanParametar;
            return false;
        }
        komanda = Komande::KreirajIgru;
        return true;
    }
    else {
        greska = KodoviGresaka::PogresnaKomanda;
        return false;
    }
}

void IzvrsiKomandu(Komande komanda, Tabla& polja, int& x, int& y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0)
{
    vector<vector<int>> v;
    Status st;

    switch((int)komanda){
    case 0:
        st = Idi(polja, x, y, p_smjer);
        if(st == Status::KrajPobjeda) {
            cout<<"Pobjeda!"<<endl;
            return;
        }
        if(st == Status::KrajPoraz) {
            cout<<"Poraz?!"<<endl;
            return;
        }
        cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
        break;
    case 1:
        st = Idi(polja, x, y, p_x, p_y);
        if(st == Status::KrajPobjeda) {
            cout<<"Pobjeda!"<<endl;
            return;
        }
        if(st == Status::KrajPoraz) {
            cout<<"Poraz?!"<<endl;
            return;
        }
        x = p_x;
        y = p_y;
        cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
        break;
    case 2:
        BlokirajPolje(polja, x, y);
        cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
        break;
    case 3:
        DeblokirajPolje(polja, x, y);
        cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
        break;
    case 4:
        v = PrikaziOkolinu(polja, x, y);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++)
                cout<<v[i][j]<<" ";
            cout<<endl;
        }
        cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
        break;
    case 5:
        x=-10;
        y=-10;
        return;
    case 6:
        break;
    default:
        cout<<"greska: broj komande je "<<(int)komanda<<endl;
        break;
    }
}

int main()
{
    vector<vector<int>> mine {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}};

    Tabla t = KreirajIgru(5, mine);
    IspisiTablu(t);
    cout<<endl;

    Komande kom;
    Smjerovi smj;
    int x=0, y=0;
    KodoviGresaka gre;

    int trX = 0, trY = 0;
    cout<<"Pocetna pozicija: "<<"("<<trX<<","<<trY<<")"<<endl;
    while(true) {
        if(UnosKomande(kom, smj, x, y, gre)){
            if(int(kom) == 1)
                IzvrsiKomandu(kom, t, trX, trY, smj, x, y);
            else
                IzvrsiKomandu(kom, t, x, y, smj);
            if(x== -10 && y == -10 )
                break;
            trX = x;
            trY = y;
        }
        else {
            cout<<"Greska: broj greske "<<(int)gre<<endl;
        }
    }

    IspisiTablu(t);




    return 0;
}
