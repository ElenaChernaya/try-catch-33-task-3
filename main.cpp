#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

template<typename T_key, typename T_value>
struct Couple
{
    T_key keys;
    T_value values;

public:
    Couple(T_key inKeys, T_value inValues): keys(inKeys), values(inValues) {}
};


template<typename T_key, typename T_value>
class Register
{
    std::vector<Couple<T_key, T_value>> registers;

public:

    void push(Couple<T_key, T_value>& inCouple)
    {
        registers.push_back(inCouple);
    }


    //добавление ключа с элементом
    void add(T_key key, T_value value)
    {
        registers.emplace_back(key, value);
    }

/*
  Не работает!!!
  //удаление всех элементов по ключу
  void _remove(T_key key)
  {
    for (int i = 0; i < registers.size(); ++i)
      {
        if (key == registers[i].keys)
        {
          registers.erase(std::remove(registers.begin(), registers.end(), registers[i].values), registers.end());
        }
    }
  }
*/

    //вывод в консоль
    void print()
    {
        for (int i = 0; i < registers.size(); ++i)
        {
            std::cout << registers[i].keys << " " << registers[i].values << std::endl;
        }
    }


    //поиск элементов по ключу
    void find(T_key key)
    {
        for (int i = 0; i < registers.size(); ++i)
        {
            if (key == registers[i].keys)
            {
                std::cout << "Key " << key << " found value " << registers[i].values << std::endl;
            }
        }
    }
};


//функция добавления эл-тов различных типов в вектор объектов
template<typename T_key, typename T_value>
void input_commands()
{
    T_key key;
    T_value value;
    Register<T_key,T_value> register_t;
    std::string command;

    while (true)
    {
        std::cout << "Enter command:\n";
        std::cin >> command;

        if (command == "add")
        {
            std::cout << "Entering Keys and Values: ";
            std::cin >> key >> value;
            register_t.add(key, value);
        }

        else if (command == "remove")
        {
            std::cout << "Entering Keys: ";
            std::cin >> key;
            //register_t._remove(key); Не работает!!!
        }

        else if (command == "find")
        {
            std::cout << "Entering Keys: ";
            std::cin >> key;
            register_t.find(key);
        }

        else if (command == "print")
        {
            register_t.print();
        }

        else if (command == "exit") break;
    }
}


int main() {

  //input_commands<int, int>();
  input_commands<std::string, double>();
  //input_commands<double, int>();
}