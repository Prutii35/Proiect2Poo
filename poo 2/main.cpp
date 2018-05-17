#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class AutoMobil
{
protected:
    template <class T>  friend class Vanzare;
    double lungime;
    int capacitate;
    double pret;
    int consum;
public:
    AutoMobil();
    virtual void AfisareDate();
};

AutoMobil::AutoMobil()
{
    cout<<"Sa se dea lungimea automobilului: ";
    cin>>lungime;
    cout<<endl<<"Sa se dea capacitatea automobilului: ";
    cin>>capacitate;
    cout<<endl<<"Sa se dea pretul automobilului: ";
    cin>>pret;
    cout<<endl<<"Sa se dea consmul automobilului: ";
    cin>>consum;
    cout<<endl;
}

void AutoMobil::AfisareDate()
{
    cout<<"Lungimea automobilului este: "<<lungime<<endl<<"Capacitatea automobilului este: "<<capacitate<<endl;
    cout<<"Pretul automobilului este: "<<pret<<endl<<"Consumul automobilului este: "<<consum<<endl;
}

class Mini:public AutoMobil  ///lungime <4 , capacitate <=2
{
    int rezervor;///Cati litri incap
public:
    int getRezervor()
    {
        return rezervor;
    }
    Mini();
    friend istream &operator >>(istream &in,Mini &m);
    void AfisareDate();

};

Mini::Mini()
{
    if(lungime >4 || capacitate >2)
    {
        throw "Nu e masina Mini";
    }
    else
        rezervor=0;
}

istream &operator >>(istream &in,Mini &m)
{
    cout<<"Sa se dea cati litri are rezervorul masinii mini: ";
    in>>m.rezervor;
    return in;
}

void Mini::AfisareDate()
{
    cout<<"Masina este Mini."<<endl<<"Lungime: "<<lungime<<endl<<"Capacitate: "<<capacitate<<endl;
    cout<<"Pret: "<<pret<<endl<<"Consum: "<<consum<<endl;
    cout<<"Rezervorul acesteia este de "<<rezervor<<" litri"<<endl;
}

class Mica:public AutoMobil ///lungime 4-4.2, capacitate 3-4
{
    int rezervor;
public:
    int getRezervor()
    {
        return rezervor;
    }
    Mica();
    friend istream &operator >>(istream &in,Mica &m);
    void AfisareDate();
};

Mica::Mica()
{
    if(lungime <4 || lungime>4.2  || capacitate >4)
    {
        throw "Nu e masina Mica";
    }
    else
        rezervor=0;
}

istream &operator >>(istream &in,Mica &m)
{
    cout<<"Sa se dea cati litri are rezervorul masinii mici: ";
    in>>m.rezervor;
    return in;
}

void Mica::AfisareDate()
{
    cout<<"Masina este Mica."<<endl<<"Lungime: "<<lungime<<endl<<"Capacitate: "<<capacitate<<endl;
    cout<<"Pret: "<<pret<<endl<<"Consum: "<<consum<<endl;
    cout<<"Rezervorul acesteia este de "<<rezervor<<" litri"<<endl;
}

class Compacta:public AutoMobil ///lungime 4.2-4.5 capcacitate 4-5
{
   string model;
public:
    string getModel()
    {
        return model;
    }
    Compacta();
    friend istream &operator >>(istream &in,Compacta &c);
    void AfisareDate();
};

Compacta::Compacta()
{
    if(lungime<4.2 || lungime>4.5 || capacitate>5)
    {
        throw "Nu e masina Compacta";
    }
    else
    {
        model="Nimic";
    }
}

istream &operator >>(istream &in,Compacta &c)
{
int n;
    cout<<"Sa se dea modelul masinii: "<<endl<<"1.Hatckback 2.Combi 3.Sedan   ";
    cin>>n;
    switch(n)
    {
    case 1:
        {
            c.model="Hatchback";
            break;
        }
    case 2:
        {
            c.model="Combi";
            break;
        }
    case 3:
        {
            c.model="Sedan";
            break;
        }
    default:
        {
            break;
        }
    }
}

void Compacta::AfisareDate()
{
    cout<<"Masina este Compacta."<<endl<<"Lungime: "<<lungime<<endl<<"Capacitate: "<<capacitate<<endl;
    cout<<"Pret: "<<pret<<endl<<"Consum: "<<consum<<endl<<"Tipul de masina: "<<model<<endl;
}

class Monovolume:public AutoMobil /// lungime >4.5
{
    bool tipAchizitionare; /// 0 noua 1 secondhand
    int vechime;
    int discount;
    bool vara;
public:
    template <class T> friend class Vanzare;
    Monovolume();
    friend istream &operator >>(istream &in,Monovolume &m);
    void AfisareDate();
};

Monovolume::Monovolume()
{
    if(lungime<4.5 || capacitate<4)
    {
        throw "Nu e masina Monovolum";
    }
    else
    {
        tipAchizitionare=0;
        vechime=0;
        discount=0;
        vara=0;
    }
}

istream &operator >>(istream &in,Monovolume &m)
{
    cout<<"Sa sa dea tipul masinii:"<<endl<<"0.Noua      1.Second Hand "<<endl;
    in>>m.tipAchizitionare;
    cout<<endl;
    if(m.tipAchizitionare==0)
    {
        m.vechime=0;
        m.discount=0;
        m.vara=0;
        return in;
    }
    else
    {
        cout<<"Sa se dea anii vechime: ";
        in>>m.vechime;
        m.discount=m.vechime;
        cout<<endl<<"Sa se zica daca este vara sau nu:"<<endl<<"0.Da  1.Nu";
        in>>m.vara;
        if(m.vara==0)
            m.discount=m.discount+10;
    }
}

void Monovolume::AfisareDate()
{
    cout<<"Masina este Monovolum."<<endl<<"Lungime: "<<lungime<<endl<<"Capacitate: "<<capacitate<<endl;
    cout<<"Pret: "<<pret<<endl<<"Consum: "<<consum<<endl;
    if(tipAchizitionare==0)
        cout<<"Tipul masinii: Noua  ---> Nu avem reducere"<<endl;
    else
    {
        cout<<"Tipul masinii: Second Hand"<<endl;
        cout<<"Vechime: "<<vechime<<" ani"<<endl<<"Discount: "<<vechime<<"%"<<endl;
        if(vara==1)
            cout<<"Nu este vara, nu mai avem reduceri in plus"<<endl;
        else
            cout<<"Anotimpul de cumparare: Vara ---> Discount bouns: 10% "<<endl<<"Discount final: "<<discount<<"%"<<endl;
    }
}

template <class T>class Vanzare
{
    int stoc;
    int vandute;
    vector <pair<AutoMobil *,int> >VectorStoc;
    vector <pair<AutoMobil *,int> >VectorVandute;
public:
    Vanzare(int n);
    void AdaugaMasiniStoc();///Completeaza Stocul cu n masini
    void VerificareStoc();///in caz ca s-a introdus o masina care nu corespunde se modifica stocul
    AutoMobil* ScoateMasinaStoc(int);///tipul de masina ---  returneaza o masina de tipul n si o scoate din vector
    void AdaugaMasinaVanduta(AutoMobil *,int);///masina si tipul de masina
    void AfiseazaStoc();
    void AfiseazaVandute();

    template <class U> friend Vanzare <U> &operator -=(Vanzare <U> &v1,Vanzare <U> &v2);
};


template <class T> Vanzare <T> &operator -=(Vanzare <T> &v1,Vanzare <T> &v2)
{
    if(v2.stoc==0)
        return v1;

    AutoMobil *m=v2.VectorStoc[0].first;
    int tip=v2.VectorStoc[0].second;

    v2.ScoateMasinaStoc(tip);
    v2.vandute++;
    v1.VectorStoc.push_back({m,tip});
    v1.stoc++;
}

template <class T> Vanzare<T>::Vanzare(int n)
{
    stoc=n;
    vandute=0;
}

template <class T> void Vanzare<T>::AdaugaMasiniStoc()///cred ca e gata
{
    int i,tip;
    cout<<"Aveti la dispozitie un stoc de "<<stoc<<" masini"<<endl;
    cout<<"Alegeti ce masini doriti sa aveti in stoc: "<<endl;
    for(i=0;i<stoc;i++)
    {
        cout<<endl<<"Sa se dea modelul de masina: "<<endl<<"1.Mini"<<endl<<"2.Mica"<<endl<<"3.Compacta"<<endl<<"4.MonoVolume"<<endl;
        cin>>tip;
        switch(tip)
        {
            case 1:
            {
                try
                {
                    Mini *masina=new Mini();
                    cin>>(*masina);
                    AutoMobil *p=dynamic_cast<AutoMobil *>(masina);
                    VectorStoc.push_back({(p),1});
                    break;
                }
                catch (...)
                {
                    cout<<"Datele date nu corespund unui tip de masina Mini"<<endl<<endl;
                    break;
                }
            }
            case 2:
            {
                try
                {
                    Mica *masina=new Mica();
                    cin>>(*masina);
                    AutoMobil *p=dynamic_cast<AutoMobil *>(masina);
                    VectorStoc.push_back({(p),2});
                    break;
                }
                catch (...)
                {
                    cout<<"Datele date nu corespund unui tip de masina Mica"<<endl<<endl;
                    break;
                }
            }
            case 3:
            {
                 try
                {
                    Compacta *masina=new Compacta();
                    cin>>(*masina);
                    AutoMobil *p=dynamic_cast<AutoMobil *>(masina);
                    VectorStoc.push_back({(p),3});
                    break;
                }
                catch (...)
                {
                    cout<<"Datele date nu corespund unui tip de masina Compacta"<<endl<<endl;
                    break;
                }
            }
            case 4:
            {
                 try
                {
                    Monovolume *masina=new Monovolume();
                    cin>>(*masina);
                    AutoMobil *p=dynamic_cast<AutoMobil *>(masina);
                    VectorStoc.push_back({(p),4});
                    break;
                }
                catch (...)
                {
                    cout<<"Datele date nu corespund unui tip de masina MonoVolum"<<endl<<endl;
                    break;
                }
            }
            default:
                {
                    cout<<"Nu exista optiunea aceasta, incercati iar! "<<endl<<endl;
                    break;
                }
        }
    }
}

template<class T> void Vanzare <T>::VerificareStoc()
{
    stoc=VectorStoc.size();
}

template <class T>void Vanzare <T>::AfiseazaStoc()
{
    int i;
    cout<<"Se afla "<<stoc<<" masini in stoc. "<<"Masinile aflate la momentul actual in stoc sunt: "<<endl<<endl;
    for(i=0;i<stoc;i++)
        {
            if(VectorStoc[i].second==1)
            {
                cout<<"Masina "<<i+1<<" este de tip Mini."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorStoc[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorStoc[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorStoc[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorStoc[i].first->consum<<endl;
                Mini *p=dynamic_cast<Mini *>(VectorStoc[i].first);
                cout<<"Rezervorul acesteie este de: "<<p->getRezervor()<<endl<<endl;

            }
            else if(VectorStoc[i].second==2)
            {
                cout<<"Masina "<<i+1<<" este de tip Mica."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorStoc[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorStoc[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorStoc[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorStoc[i].first->consum<<endl;
                Mica *p=dynamic_cast<Mica *>(VectorStoc[i].first);
                cout<<"Rezervorul acesteie este de: "<<p->getRezervor()<<endl<<endl;
            }
            else if(VectorStoc[i].second==3)
            {
                cout<<"Masina "<<i+1<<" este de tip Compacta."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorStoc[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorStoc[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorStoc[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorStoc[i].first->consum<<endl;
                Compacta *p=dynamic_cast<Compacta *>(VectorStoc[i].first);
                cout<<"Tipul de masina este: "<<p->getModel()<<endl<<endl;
            }
            else if(VectorStoc[i].second==4)
            {
                cout<<"Masina "<<i+1<<" este de tip MonoVolum."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorStoc[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorStoc[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorStoc[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorStoc[i].first->consum<<endl;
                Monovolume *p=dynamic_cast<Monovolume *>(VectorStoc[i].first);
                if(p->tipAchizitionare==0)
                    cout<<"Masina este noua"<<endl<<endl;
                else
                {
                    cout<<"Masina este second hand"<<endl;
                    cout<<"Vechime: "<<p->vechime<<" ani"<<endl<<"Discount: "<<p->vechime<<"%"<<endl;
        if(p->vara==1)
            cout<<"Nu este vara, nu mai avem reduceri in plus"<<endl;
        else
            cout<<"Anotimpul de cumparare: Vara ---> Discount bouns: 10% "<<endl<<"Discount final: "<<p->discount<<"%"<<endl<<endl;
                }
            }
        }
}

template <class T> void Vanzare<T>::AfiseazaVandute()
{
    int i;
    if(vandute==0)
        cout<<"Nu a fost vanduta nici o masina inca"<<endl<<endl;
    else
    {
    cout<<"Au fost vandute "<<vandute<<" masini. ";
    cout<<"Masinile care au fost vandute pana acum sunt: "<<endl;
    for(i=0;i<vandute;i++)
       {

            if(VectorVandute[i].second==1)
            {
                cout<<"Masina "<<i+1<<" este de tip Mini."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorVandute[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorVandute[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorVandute[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorVandute[i].first->consum<<endl;
                Mini *p=dynamic_cast<Mini *>(VectorVandute[i].first);
                cout<<"Rezervorul acesteie este de: "<<p->getRezervor()<<endl<<endl;
            }
            else if(VectorVandute[i].second==2)
            {
                cout<<"Masina "<<i+1<<" este de tip Mica."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorVandute[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorVandute[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorVandute[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorVandute[i].first->consum<<endl;
                Mica *p=dynamic_cast<Mica *>(VectorVandute[i].first);
                cout<<"Rezervorul acesteie este de: "<<p->getRezervor()<<endl<<endl;
            }

            else if(VectorVandute[i].second==3)
            {
                cout<<"Masina "<<i+1<<" este de tip Compacta."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorVandute[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorVandute[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorVandute[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorVandute[i].first->consum<<endl;
                Compacta *p=dynamic_cast<Compacta *>(VectorVandute[i].first);
                cout<<"Tipul de masina este: "<<p->getModel()<<endl<<endl;
            }
            else if(VectorVandute[i].second==4)
            {
                cout<<"Masina "<<i+1<<" este de tip MonoVolum."<<endl;
                cout<<"Lungimea automobilului este: "<<VectorVandute[i].first->lungime<<endl<<"Capacitatea automobilului este: "<<VectorVandute[i].first->capacitate<<endl;
                cout<<"Pretul automobilului este: "<<VectorVandute[i].first->pret<<endl<<"Consumul automobilului este: "<<VectorVandute[i].first->consum<<endl;
                Monovolume *p=dynamic_cast<Monovolume *>(VectorVandute[i].first);
                if(p->tipAchizitionare==0)
                    cout<<"Masina este noua"<<endl<<endl;
                else
                {
                    cout<<"Masina este second hand"<<endl;
                    cout<<"Vechime: "<<p->vechime<<" ani"<<endl<<"Discount: "<<p->vechime<<"%"<<endl;
        if(p->vara==1)
            cout<<"Nu este vara, nu mai avem reduceri in plus"<<endl;
        else
            cout<<"Anotimpul de cumparare: Vara ---> Discount bouns: 10% "<<endl<<"Discount final: "<<p->discount<<"%"<<endl<<endl;
                }
            }
       }
    }
}

template <class T> void Vanzare <T>::AdaugaMasinaVanduta(AutoMobil *m,int n)
{
        VectorVandute.push_back({m,n});
        vandute++;
}

template <class T> AutoMobil* Vanzare <T>::ScoateMasinaStoc(int n)
{
    if(stoc==0)
        {
            cout<<"Stocul este gol"<<endl;
            return nullptr;
        }
    else
    {
        int i;
        for(i=0;i<stoc;i++)
        {
            if(VectorStoc[i].second==n)
            {
                AutoMobil *m=VectorStoc[i].first;
                int j;
                for(j=i;j<stoc-1;j++)
                {
                    VectorStoc[j]=VectorStoc[j+1];
                }
                stoc--;
                return m;
            }
        }
         cout<<"Nu avem acest tip de masina in stoc"<<endl;
         return nullptr;
    }

}

int main()
{
    int n,i,tip,ok=0;
    cout<<"Proiect 2 POO ----> Tema4: Parc Auto"<<endl<<endl;
    cout<<"Tipurile de masina aflate in acest parc sunt:"<<endl;
    cout<<"1.Masina Mini --- Masina de oras de mic litraj, lungime mai mica de 4 metrii si capacitate de 2 sau mai putine persoane."<<endl;
    cout<<"2.Masina Mica --- Masina de oras, cu lungime intre 4 si 4.2 metrii si capcatitate de 3-4 persoane."<<endl;
    cout<<"3.Masina Compacta --- Masina de oras si de drum lung, cu lungime intre 4.2 si 4.5 metrii, capacitate de 5 persoane si poate fi de tip HatchBack, Combi sau Sedan"<<endl;
    cout<<"4.Masina MonoVolum --- Masina sub forma de van, cu lungime de peste 4.5 metrii si capcaitate mai mare decat 4"<<endl<<endl;
    cout<<"Sa se dea cate masini se afla in acest parc auto: ";
    cin>>n;
    Vanzare <AutoMobil> v(n);
    cout<<endl;
    v.AdaugaMasiniStoc();
    v.VerificareStoc();
    cout<<endl<<"Meniu: "<<endl<<endl;
    cout<<"Selectati ce operatie doriti sa faceti: "<<endl<<endl;
    while(ok==0)
    {
        cout<<endl<<endl<<"1.Afisare Stoc"<<endl<<"2.Afisare Masini Vandute"<<endl<<"3.Vinde o masina"<<endl<<"4.Iesire"<<endl<<"5.Scadere Vectori"<<endl<<endl<<"Operatie: ";
        cin>>tip;
        switch(tip)
        {
        case 1:
            {
                v.AfiseazaStoc();
                break;
            }
        case 2:
            {
                v.AfiseazaVandute();
                break;
            }
        case 3:
            {
                int op;
                cout<<"Ce masina doriti sa vindeti: ";
                cout<<endl<<"1.Mini"<<endl<<"2.Mica"<<endl<<"3.Compacta"<<endl<<"4.Monovolum"<<endl<<endl;
                cin>>op;
                if(op==0 || op>=5)
                    cout<<"Nu avem un astfel de tip"<<endl;
                else
                {
                    AutoMobil *m=v.ScoateMasinaStoc(op);
                    if(m!=nullptr)
                        v.AdaugaMasinaVanduta(m,op);
                }
                  break;
            }
        case 4:
            {
                ok=1;
                break;
            }
        case 5:
            {
                cout<<"Primul vector: "<<endl;
                Vanzare <AutoMobil >v1(0);
                v1.AdaugaMasiniStoc();
                v1.VerificareStoc();
                cout<<endl<<endl<<"Al doilea vector: "<<endl;
                Vanzare <AutoMobil>v2(2);
                v2.AdaugaMasiniStoc();
                v2.VerificareStoc();
                v1-=v2;

                cout<<endl<<"Primul vector: "<<endl<<endl;
                v1.AfiseazaStoc();
                cout<<endl<<endl<<"Al doilea vector: ";
                v2.AfiseazaStoc();
                break;
            }
        default:
            {
                cout<<"Ati ales gresit"<<endl<<endl;
                break;
            }
        }

    }
    return 0;
}
