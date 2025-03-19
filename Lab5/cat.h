#pragma once 

#include <string>
#include <ostream>
#include <sstream>
#include <functional>




class Cat {
    private:
        std::string name;
        unsigned int lives; 

    public:
        Cat(std::string name);
        Cat(std::string name, unsigned int lives);
        ~ Cat();


        std::string const get_name() const;
        unsigned int const get_lives() const;

        virtual bool isEqual(const Cat &lhs) {
            auto a = dynamic_cast<const Cat&>(lhs);

            return Cat::isEqual(a) &&
                 a.get_lives() == get_lives();
        }

        void set_name(std::string const name);
        void set_lives(unsigned int const lives);

        // function returning outstream to print cat. 
        friend std::ostream &operator<<(std::ostream &os, const Cat& cat) {
            std::stringstream ss;
            ss << "Cat named " << cat.get_name() << " is " <<  std::to_string(cat.get_lives()) << " years old."; 
            os << ss.str();
            return os;
        };

        friend bool operator==(const Cat &lhs, const Cat &rhs) {
            return lhs.get_lives() == rhs.get_lives() &&
            lhs.get_name() == rhs.get_name();
        }

        friend bool operator<(const Cat &lhs, const Cat &rhs) {
            if (lhs.get_name() < rhs.get_name()){
                return true;
            } else if (rhs.get_name() < lhs.get_name()){
                return false;
            }
            return lhs.get_lives() < rhs.get_lives();
        }

};


namespace std {

    template <>
    struct hash<Cat> {
        size_t operator()(const Cat &cat) const {    
            
            std::ostringstream ss;
            ss << cat;
            return std::hash<std::string>{}(ss.str());
        }
    };
}



