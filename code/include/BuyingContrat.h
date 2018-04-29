#ifndef BUYINGCONTRAT_H
#define BUYINGCONTRAT_H

#include "DataBase.h"
#include <string>
#include "Contrat.h"

class BuyingContrat: public Contrat
{
    public:
         BuyingContrat();
        ~BuyingContrat();
        //crud
        void addContrat(int,int);
        void editContrat(int id);
        void deleteContrat(int id);
        void showContrat(int id);
        void showAll();

        // Contracts operations

        virtual void showClosedContracts();
        virtual void showPendingContracts();
        virtual void signContact(int);

    private:
        float value;
        DataBase *DB = new DataBase;
};

#endif // BUYINGCONTRAT_H
