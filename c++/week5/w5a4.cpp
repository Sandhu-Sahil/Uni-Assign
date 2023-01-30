#include <iostream>
using namespace std;

class base_food_items 
{
    public:
        char item_name[20];
        int quantity;
        int item_price;
    public:
        virtual void order()
        {
            cout << "enter item name:";
            cin>> item_name;
            cout << "enter quantity";
            cin>> quantity;

            cout << "Item price";
            cin >> item_price;
        }
        void total_price()
        {
            cout<<"order is: " << item_name<<"\t"<<"quantity:"<<quantity<<endl;
            cout << "total price=" << item_price*quantity<<endl;
        }
};

class chinese : public base_food_items
{
    public:
        void order()
        {
            cout << "enter chinese item name:";
            cin>> item_name;
            cout << "enter quantity";
            cin>> quantity;

            cout << "Item price";
            cin >> item_price;
        }
        void total_price()
        {
            cout<<"order is: " << item_name<<"\t"<<"quantity:"<<quantity<<endl;
            cout << "total price=" << item_price*quantity<<endl;
        }
};

int main()
{
    base_food_items *ptr;
    chinese obj;
    ptr = &obj;
    base_food_items &ptr2 = *ptr;
    ptr2.order();
    ptr2.total_price();

    return 0;

}