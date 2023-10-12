using namespace std;
#include <iostream>;

class Herbivore
{
public:
    virtual void Eat() = 0;
    virtual string GetName() = 0 {}
    virtual void Die() = 0;
    virtual int GetWeight() = 0;
};
class Carnivore
{
public:
    virtual void Eat(Herbivore& herbivore) = 0;
};

class Wildebeest : public Herbivore
{
private:
    string name;
    int weight;
    bool isAlive;

public:
    Wildebeest(int w) : weight(w), isAlive(true), name("wildebeest") {}

    void Eat()
    {
        if (isAlive)
        {
            cout << "The wildebeest is eating grass. " << "[+10kg]" << endl;
            weight += 10;
        }
        else
        {
            cout << "Can't feed. The wildebeest is dead." << endl;
        }
    }

    void Die()
    {
        cout << "The wildebeest has been eaten. [Dead]" << endl;
        isAlive = false;
    }

    void Print()
    {
        cout << "\tInformation" << endl;
        cout << "Animal: Wildebeest\nWeight: " << weight << "\nStatus: ";
        if (isAlive)
        {
            cout << "Alive" << endl;
        }
        else
        {
            cout << "Dead" << endl;
        }
        cout << endl;
    }
    int GetWeight()
    {
        return weight;
    }
    string GetName()
    {
        return name;
    }
};
class Bison : public Herbivore
{
private:
    string name;
    int weight;
    bool isAlive;

public:
    Bison(int w) : name("bison"), weight(w), isAlive(true) {}

    void Eat()
    {
        if (isAlive)
        {
            cout << "The bison is eating grass. " << "[+10kg]" << endl;
            weight += 10;
        }
        else
        {
            cout << "Can't feed. The bison is dead." << endl;
        }
    }

    void Die()
    {
        cout << "The bison has been eaten. [Dead]" << endl << endl;
        isAlive = false;
    }

    void Print()
    {
        cout << "\tInformation" << endl;
        cout << "Animal: Bison\nWeight: " << weight << "\nStatus: ";
        if (isAlive)
        {
            cout << "Alive" << endl;
        }
        else
        {
            cout << "Dead" << endl;
        }
        cout << endl;
    }
    int GetWeight()
    {
        return weight;
    }
    string GetName()
    {
        return name;
    }
};

class Lion : public Carnivore
{
private:
    int power;
public:
    Lion(int w) : power(w) {}

    void Eat(Herbivore& herbivore)
    {
        int h_weight = herbivore.GetWeight();
        if(power>= h_weight)
        {
            cout << "Lion is eating a " << herbivore.GetName() << ". [+10 power]" << endl;
            herbivore.Eat();
            power += 10;
            herbivore.Die();
        }
        else
        {
            cout << "Lion wasn't strong enough to eat the " << herbivore.GetName() << ". [-10 power]" << endl;
            power -= 10;
        }
    }

    void Print()
    {
        cout << "\tInformation" << endl;
        cout << "Animal: Lion\nPower: " << power << endl;
        cout << endl;
    }
};

class Wolf : public Carnivore
{
private:
    int power;

public:
    Wolf(int s) : power(s) {}

    void Eat(Herbivore& herbivore)
    {
        int h_weight = herbivore.GetWeight();
        if (power >= h_weight)
        {
            cout << "Wolf is eating a " << herbivore.GetName() << ". [+10 power]" << endl;
            herbivore.Eat();
            power += 10;
            herbivore.Die();
        }
        else
        {
            cout << "Wolf wasn't strong enough to eat the " << herbivore.GetName() << ". [-10 power]" << endl;
            power -= 10;
        }
    }

    void Print()
    {
        cout << "\tInformation" << endl;
        cout << "Animal: Wolf\nPower: " << power << endl;
        cout << endl;
    }
};

class Client
{
public:
    void FeedHerbivores(Bison& bison, Wildebeest& wildebeest)
    {
        bison.Eat();
        wildebeest.Eat();
    }

    void FeedCarnivores(Carnivore& carnivore, Herbivore& herbivore)
    {
        carnivore.Eat(herbivore);
    }
};

int main()
{
    Wildebeest wildebeest(150);
    wildebeest.Print();
    Lion lion(200);
    lion.Print();
    Bison bison(400);
    bison.Print();

    Wolf wolf(150);
    wolf.Print();

    Client client;
    client.FeedHerbivores(bison, wildebeest);
    client.FeedCarnivores(lion, wildebeest);
    client.FeedCarnivores(wolf, bison);

    cout << "\n\tAfter feeding\n" << endl;
    wildebeest.Print();
    lion.Print();
    wolf.Print();
    bison.Print();
}