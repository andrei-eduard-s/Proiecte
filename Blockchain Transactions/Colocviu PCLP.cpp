// Colocviu PCLP vs.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <random>
#include <stdio.h>      
#include <stdlib.h>
#include <iomanip>
using namespace std;
class Tranzactie {
public:
    Tranzactie()
    {
        txCantitate_combustibil = 0;
        txClient = "";
        txNr_Inmatriculare = "";
        txCombustibil = "";
    }
    Tranzactie(string client, string Nr_Inmatriculare, string combustibil, double cantitate_combustibil)
    {
        txClient = client;
        txNr_Inmatriculare = Nr_Inmatriculare;
        txCombustibil = combustibil;
        txCantitate_combustibil = cantitate_combustibil;
    }
    string getTxClient()
    {
        return txClient;
    }
    string getTxNr_Inmatriculare()
    {
        return txNr_Inmatriculare;
    }
    string getTxCombustibil()
    {
        return txCombustibil;
    }
    double getTxCantitate_combustibil()
    {
        return txCantitate_combustibil;
    }
private:
    string txClient;
    string txNr_Inmatriculare;
    string txCombustibil;
    double txCantitate_combustibil;
};
class Block {
public:
    Block(int ix, string prevHash, string client, string Nr_Inmatriculare, string combustibil, double cantitate_combustibil)
    {
        index = ix;
        previousBlockHash = prevHash;
        Tranzactie t(client, Nr_Inmatriculare,combustibil, cantitate_combustibil);
        tx = t;
    }
    int getIndex()
    {
        return index;
    }
    string getTimeStamp()
    {
        timeStamp = now();
        return timeStamp;
    }
    string getPreviousBlockHash()
    {
        return previousBlockHash;
    }
    string getBlockHash()
    {
        blockHash = calculateHash();
        return blockHash;
    }
    Tranzactie getTx()
    {
        return tx;
    }
    double getDurata_stationarii()
    {
        double val_min = 2;
        double val_max = 20;
        std::uniform_real_distribution<double> unif(val_min, val_max);
        std::mt19937 durata;
        durata.seed(std::random_device{}());
        return std::ceil(unif(durata) * 100.0) / 100.0;
    }
    double getPret()
    {
        if (strcmp(getTx().getTxCombustibil().c_str(), "Motorina") == 0)
        {
            double val_min = 5.39;
            double val_max = 5.61;
            std::uniform_real_distribution<double> unif(val_min, val_max);
            std::mt19937 durata;
            durata.seed(std::random_device{}());
            return std::ceil(unif(durata) * 100.0) / 100.0;
        }
        else if (strcmp(getTx().getTxCombustibil().c_str(), "Benzina 95") == 0)
        {
            double val_min = 5.49;
            double val_max = 5.66;
            std::uniform_real_distribution<double> unif(val_min, val_max);
            std::mt19937 durata;
            durata.seed(std::random_device{}());
            return std::ceil(unif(durata) * 100.0) / 100.0;
        }
        else if (strcmp(getTx().getTxCombustibil().c_str(), "Benzina 98") == 0)
        {
            double val_min = 5.67;
            double val_max = 6.32;
            std::uniform_real_distribution<double> unif(val_min, val_max);
            std::mt19937 durata;
            durata.seed(std::random_device{}());
            return std::ceil(unif(durata) * 100.0) / 100.0;
        }
    }
    double getPlata()
    {
        return getTx().getTxCantitate_combustibil() * getPret();
    }
private:
    string calculateHash() {
        hash<string> str_hash;
        return to_string(str_hash(timeStamp + previousBlockHash + getTx().getTxClient() + getTx().getTxNr_Inmatriculare() + to_string(getTx().getTxCantitate_combustibil())));
    }
    string now() {
        time_t t = time(0);
        string str = ctime(&t);
        str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());
        return str;
    }
    int index;
    double durata;
    double pret;
    double plata;
    string timeStamp;
    string previousBlockHash;
    string blockHash;
    Tranzactie tx;
};
class Blockchain {
public:
    Blockchain()
    {
        Block genesis(0, "0", "", "","", 0);
        chain.push_back(genesis);
    }
    void addNewBlock(string client, string Nr_Inmatriculare, string combustibil, double cantitate_combustibil)
    {
        Block c(getLastIndex() + 1, getLastHash(), client, Nr_Inmatriculare,combustibil, cantitate_combustibil);
        chain.push_back(c);
    }
    vector<Block> getChain()
    {
        return chain;
    }

private:
    vector<Block> chain;
    string getLastHash()
    {
        return getChain().back().getBlockHash();
    } //functia getter returneaza hash-ul blocului anterior
    int getLastIndex()
    {
        return getChain().back().getIndex();
    }//functia getter returneaza index-ul blocului anterior
};
ostream& operator<<(ostream& o, Block& b)
{
    o << "{" << endl << "  BlockID: " << b.getIndex() << "," << endl << "  Time_Stamp: " << b.getTimeStamp() << "," << endl
        << "  Previous Block Hash: " << b.getPreviousBlockHash() << "," << endl << "  Block Hash: " << b.getBlockHash() << "," << endl << endl
        << "  Client: " << b.getTx().getTxClient() << "," << endl << "  Nr_Inmatriculare: " << b.getTx().getTxNr_Inmatriculare() << "," << endl
        << "  Combustibil: " << b.getTx().getTxCombustibil() << "," << endl << "  Pret/litru: " << b.getPret() << " lei," << endl
        << "  Cantitate combustibil: " << b.getTx().getTxCantitate_combustibil() << " litri," << endl
        << "  Suma de achitat: " << b.getPlata() << " lei," << endl
        << "  Durata stationarii la pompa: " <<b.getDurata_stationarii() << " minute" << "," <<endl<< "}," << endl;
    return o;
}
ostream& operator<<(ostream& o, Blockchain& bc)
{
    int i = 1;
    vector <Block> chain = bc.getChain();
    Block c(0, "0", "", "","", 0);
    while (i < chain.size())
    {
        c = chain[i];
        o << c;
        i++;
    }
    return o;
    //supraincarcarea operatorului << pentru clasa Blockchain
    //se itereaza vectorul chain si se afiseaza detaliile fiecarui bloc
}
int main()
{
    Blockchain myChain;
    myChain.addNewBlock("Solomon Andrei", "GL01DTZ","Motorina", 30.5);
    myChain.addNewBlock("Mihai Ionut", "BV46ABC","Benzina 95", 15.5);
    //myChain.addNewBlock("Popescu George", "B105VSC","Motorina", 56.8);
    myChain.addNewBlock("Giovani Becali", "B999BOS","Benzina 98", 80.2);
    cout << myChain;
    return 0;
}