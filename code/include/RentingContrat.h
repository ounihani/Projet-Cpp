#ifndef RENTINGCONTRAT_H
#define RENTINGCONTRAT_H

#include "DataBase.h"
#include <string>
#include "Contrat.h"

class RentingContrat : public Contrat
{
    public:
        RentingContrat();
        ~RentingContrat();

        //crud
        void addContrat(int ,int);
        void editContrat(int id);
        void deleteContrat(int id);
        void showContrat(int id);
        void showAll();

        // Contracts operations

        virtual void showClosedContracts();
        virtual void showPendingContracts();
        virtual void signContact(int);

    private:
        string startingDate;
        string endDate;
        float amountPerMonth;
        DataBase* DB = new DataBase();
};

#endif // RENTINGCONTRAT_H
