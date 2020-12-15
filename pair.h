// Classe pour un couple (int, bool)

class Pair{

    public:
        Pair (bool);
    
    public:
        void setFalse (); // change le booléen du couple en false
        void setInt (int); // permet de modifier l'entier du couple
        void increase (int); // permet d'augmenter l'entier du couple
        bool getBool (); // obtenir le booléen
        int getInt (); // obtenir l'entier

    private:
        int res;
        bool valid;
};