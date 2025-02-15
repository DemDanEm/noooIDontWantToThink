#include <iostream>
#include <string>
#include <memory>
#include <list>

class WroomWroom {
protected:
    std::string mark, model, releaseYear, colour, runTime, cost;
public:


    //constuctor
    WroomWroom(std::string nmark = "void", std::string nmodel = "void",
        std::string nyear = "void", std::string ncolor = "void",
        std::string nrun = "void", std::string ncost = "void")
        :
        mark(nmark), model(nmodel), releaseYear(nyear),
        colour(ncolor), runTime(nrun), cost(ncost)
    { }

    //copy constructor
    WroomWroom(WroomWroom const& car) 
    {
        this->mark = car.mark;
        this->model = car.model;
        this->releaseYear = car.releaseYear;
        this->colour = car.colour;
        this->runTime = car.runTime;
        this->cost = car.cost;
    }

    // = operator
    WroomWroom operator= (WroomWroom const& car) 
    {
        this->mark = car.mark;
        this->model = car.model;
        this->releaseYear = car.releaseYear;
        this->colour = car.colour;
        this->runTime = car.runTime;
        this->cost = car.cost;

        return *this;
    }

    //destructor
    ~WroomWroom() = default;

    //Getters for unsettable fields

    std::string get_mark() {return this->mark;}
    std::string get_model() {return this->model;}
    std::string get_year() {return this->releaseYear;}

    // Getters/Setters pairs

    void set_color(std::string color) { this->colour = color; }
    std::string get_color() { return this->colour; }

    void set_time(std::string value) { this->runTime = value; }
    std::string get_time() { return this->runTime; }

    void set_cost(std::string value) { this->cost = value; }
    std::string get_cost() { return this->cost; }
};

class PackDash 
{
protected:
    //Name/weight
    std::string nmae;
    unsigned int waigt;

public:
    // Constructor
    PackDash(std::string nae, int whip): nmae(nae), waigt(whip){}

    // Copy constructor
    PackDash(PackDash const& pack) 
    {
        this->nmae = pack.nmae;
        this->waigt = pack.waigt;
    }

    //Operator =
    PackDash operator=(PackDash pack)
    {
        this->nmae = pack.nmae;
        this->waigt = pack.waigt;
        return *this;
    }

    //Destructor
    ~PackDash() = default;


    //Getters

    int get_weight() { return waigt; }
    std::string get_name() { return nmae; }
};

class BigWroom final : WroomWroom
{
private:
    unsigned int maxPayn;
    std::list<PackDash> load;

public:
    //Constructor
    BigWroom(int payload) : WroomWroom(), maxPayn(payload)
    {
    }

    //Copy constructor
    BigWroom(BigWroom const& car)
    {
        this->mark = car.mark;
        this->model = car.model;
        this->releaseYear = car.releaseYear;
        this->colour = car.colour;
        this->runTime = car.runTime;
        this->cost = car.cost;

        this->maxPayn = car.maxPayn;
        this->load = car.load;
    }

    //Operator =
    BigWroom operator=(BigWroom const& car)
    {
        this->mark = car.mark;
        this->model = car.model;
        this->releaseYear = car.releaseYear;
        this->colour = car.colour;
        this->runTime = car.runTime;
        this->cost = car.cost;

        this->maxPayn = car.maxPayn;
        this->load = car.load;

        return *this;
    }

    ~BigWroom() = default;

    //main functions
    //isReady but based
    bool is_overloaded() {
        unsigned int weight = 0;

        for (PackDash pack : this->load) {
            weight += pack.get_weight();
        }

        return weight > this->maxPayn;
    }

    // Made sense to add theese two
    void add_load(PackDash const& pack) {
        load.push_back(pack);
    }

    // Made sense to add theese two
    void clear_load() {
        load.clear();
    }
};

// Overloadin std::cout
std::ostream& operator<< (std::ostream& st, WroomWroom wr) {

    st << wr.get_mark() << ", " << wr.get_model() << ", " 
        << wr.get_year() << ", " << wr.get_color() << ", " 
        << wr.get_time() << ", " << wr.get_cost();
    return st;
}

int main()
{
    std::string a = "a";
    WroomWroom rum(a, a, a, a, a, a);

    std::cout << rum;
}
