#include <iostream>

int main()
{
    int month;
    std::cout << "Enter the number(1-12): ";
    std::cin>> month;

    switch (month)
    {
        case 1:
            std::cout << "It's Jan";
            break;
    
        case 2:
            std::cout << "It's Feb";
            break;
    
        case 3:
            std::cout << "It's March";
            break;
    
        case 4:
            std::cout << "It's April";
            break;
        
        case 5:
            std::cout << "It's May";
            break;    

        case 6:
            std::cout << "It's June";
            break;
    
        case 7:
            std::cout << "It's July";
            break;
    
        case 8:
            std::cout << "It's Aug";
            break;
    
        case 9:
            std::cout << "It's Sep";
            break;
    
        case 10:
            std::cout << "It's Oct";
            break;
    
        case 11:
            std::cout << "It's Nov";
            break;
    
        case 12:
            std::cout << "It's Dec";
            break;

    
        default:
            std::cout << "Enter valid month";
            break;
    }
}